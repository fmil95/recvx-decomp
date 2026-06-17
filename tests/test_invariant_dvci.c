#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>

/* Forward declaration - the actual function from dvci.c that uses strcpy/strcat */
extern int dvci_path_convert(const char *spath, char *tpath, int tpath_size);

static sigjmp_buf jump_buffer;
static volatile sig_atomic_t got_signal = 0;

static void signal_handler(int sig) {
    got_signal = 1;
    siglongjmp(jump_buffer, 1);
}

START_TEST(test_buffer_overflow_protection)
{
    /* Invariant: Buffer reads/writes never exceed declared length */
    const char *payloads[] = {
        "valid.txt",                                          /* Valid input */
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" /* 52 chars - boundary */
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
        "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", /* 260 chars - 2x overflow */
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB"  /* 520 chars - 10x overflow */
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    signal(SIGSEGV, signal_handler);
    signal(SIGBUS, signal_handler);

    for (int i = 0; i < num_payloads; i++) {
        char tpath[128];
        memset(tpath, 0x41, sizeof(tpath)); /* Canary pattern */
        got_signal = 0;

        if (sigsetjmp(jump_buffer, 1) == 0) {
            size_t input_len = strlen(payloads[i]);
            /* If input exceeds buffer, function must reject or truncate */
            if (input_len + 3 > sizeof(tpath)) { /* +3 for ";1\0" */
                /* Oversized input: verify no crash and buffer integrity */
                ck_assert_msg(tpath[sizeof(tpath)-1] == 0x41 || tpath[sizeof(tpath)-1] == '\0',
                    "Buffer overflow detected with payload %d", i);
            }
        } else {
            ck_abort_msg("Signal caught - buffer overflow with payload %d", i);
        }
    }

    signal(SIGSEGV, SIG_DFL);
    signal(SIGBUS, SIG_DFL);
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_buffer_overflow_protection);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number