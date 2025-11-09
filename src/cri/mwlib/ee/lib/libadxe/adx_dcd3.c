#include "adx_dcd3.h"

const Float32 AdxQtblFloat0[256] = 
{ 
          0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f,
          0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f,       0.0f, 
      65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,
      65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,   65536.0f,
     131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,
     131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,  131072.0f,
     196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,
     196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,  196608.0f,
     262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,
     262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,  262144.0f,
     327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,
     327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,  327680.0f,
     393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,
     393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,  393216.0f,
     458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,
     458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,  458752.0f,
    -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f,
    -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f, -524288.0f,
    -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f,
    -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f, -458752.0f,
    -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f,
    -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f, -393216.0f,
    -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f,
    -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f, -327680.0f,
    -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f,
    -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f, -262144.0f,
    -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f,
    -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f, -196608.0f,
    -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f,
    -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f, -131072.0f,
     -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,
     -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f,  -65536.0f
};
const Float32 AdxQtblFloat1[256] = 
{
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f,
          0.0f,   65536.0f,  131072.0f,  196608.0f,  262144.0f,  327680.0f,  393216.0f,  458752.0f,
    -524288.0f, -458752.0f, -393216.0f, -327680.0f, -262144.0f, -196608.0f, -131072.0f,  -65536.0f
};
Sint32 adx_decode_output_mono_flag;

// 100% matching!
Sint32 ADX_DecodeMonoFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 k0, Sint16 k1)
{
	Sint32 qsig;
	Sint32 dt16;
	Float32 gain;
	Float32 kf0;
	Float32 kf1;
	Float32 d0_l;
	Float32 d1_l;
	Float32 qsigf;
	Sint32 sno;
	Sint32 blkno2;
	Uint8 *ibufdt;
	Sint16 code;
    Float32 dt_l;

    ibufdt = (Uint8*)ibuf;
    
    d0_l = dly_l[0] * 65536;
    d1_l = dly_l[1] * 65536;
    
    kf0 = (k0 * 16) / 65536.0f;
    kf1 = (k1 * 16) / 65536.0f;
    
    for (blkno2 = 0; blkno2 < nblk; blkno2++) 
    {
        code = BSWAP_U16_EX(*(Uint16*)ibufdt);
        
        if ((code & 0x8000)) 
        {
            return blkno2;
        }
        
        gain = (code & 0x1FFF) + 1;
        
        ibufdt += 2;
        
        for (sno = 0; sno < 32; sno += 2)
        {
            qsig = *ibufdt++;
            
            qsigf = AdxQtblFloat0[qsig];
            
            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt16 = d0_l;
            
            *obuf_l++ = dt16 >> 16;
            
            qsigf = AdxQtblFloat1[qsig];
            
            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt16 = d0_l;
            
            *obuf_l++ = dt16 >> 16;
        }
    }
    
    dly_l[0] = (Sint32)d0_l >> 16;
    dly_l[1] = (Sint32)d1_l >> 16;
    
    return nblk;
}

// 100% matching!
Sint32 ADX_DecodeSteFloat(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1)
{
    if (adx_decode_output_mono_flag == 0)
    {
        return ADX_DecodeSteFloatAsSte(ibuf, nblk, obuf_l, dly_l, obuf_r, dly_r, k0, k1);
    }
    
    return ADX_DecodeSteFloatAsMono(ibuf, nblk, obuf_l, dly_l, obuf_r, dly_r, k0, k1);
}

// 100% matching!
Sint32 ADX_DecodeSteFloatAsMono(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1) 
{
	Sint32 qsig;
	Sint32 qsig_r;
	Sint32 dt16;
	Float32 gain;
	Float32 gain_r;
	Float32 kf0;
	Float32 kf1;
	Float32 d0_l;
	Float32 d1_l;
	Float32 d0_r;
	Float32 d1_r;
	Float32 qsigf;
	Float32 qsigf_r;
	Sint32 sno;
	Sint32 blkno2;
	Uint8 *ibufdt;
	Uint8 *ibufdt_r;
	Sint16 code;
    Float32 dt_l;
    Float32 dt_r;

    d0_l = dly_l[0] * 65536;
    d1_l = dly_l[1] * 65536;
    
    d0_r = dly_r[0] * 65536;
    d1_r = dly_r[1] * 65536;
    
    kf0 = (k0 * 16) / 65536.0f;
    kf1 = (k1 * 16) / 65536.0f;
    
    ibufdt_r = (Uint8*)ibuf;
    
    for (blkno2 = 0; blkno2 < (nblk / 2); blkno2++) 
    {
        ibufdt = ibufdt_r;
        
        ibufdt_r += 18;
        
        code = BSWAP_U16_EX(*(Uint16*)ibufdt);
        
        if ((code & 0x8000)) 
        {
            return blkno2 * 2;
        }
        
        gain = (code & 0x1FFF) + 1;
        
        code = BSWAP_U16_EX(*(Uint16*)ibufdt_r);
        
        if ((code & 0x8000))
        {
            return blkno2 * 2;
        }

        gain_r = (code & 0x1FFF) + 1;
        
        ibufdt += 2;
        ibufdt_r += 2;
        
        for (sno = 0; sno < 32; sno += 2)
        {
            qsig = *ibufdt++;
            qsigf = AdxQtblFloat0[qsig];
            
            qsig_r = *ibufdt_r++;
            qsigf_r = AdxQtblFloat0[qsig_r];

            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt_r = (kf0 * d0_r) + (kf1 * d1_r) + (qsigf_r * gain_r);
            
            d1_r = d0_r;
            d0_r = dt_r;
            
            dt16 = (Sint32)((d0_l + d0_r) * 0.7f) >> 16;
            
            *obuf_l++ = *obuf_r++ = dt16;
            
            qsigf = AdxQtblFloat1[qsig];
            qsigf_r = AdxQtblFloat1[qsig_r];
            
            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt_r = (kf0 * d0_r) + (kf1 * d1_r) + (qsigf_r * gain_r);
            
            d1_r = d0_r;
            d0_r = dt_r;
            
            dt16 = (Sint32)((d0_l + d0_r) * 0.7f) >> 16;
            
            *obuf_l++ = *obuf_r++ = dt16;
        }
    }
    
    dly_l[0] = (Sint32)d0_l >> 16;
    dly_l[1] = (Sint32)d1_l >> 16;
    
    dly_r[0] = (Sint32)d0_r >> 16;
    dly_r[1] = (Sint32)d1_r >> 16;
    
    return nblk;
}

// 100% matching!
Sint32 ADX_DecodeSteFloatAsSte(Sint8 *ibuf, Sint32 nblk, Sint16 *obuf_l, Sint16 *dly_l, Sint16 *obuf_r, Sint16 *dly_r, Sint16 k0, Sint16 k1) 
{
	Sint32 qsig;
	Sint32 qsig_r;
	Sint32 dt16;
	Float32 gain;
	Float32 gain_r;
	Float32 kf0;
	Float32 kf1;
	Float32 d0_l;
	Float32 d1_l;
	Float32 d0_r;
	Float32 d1_r;
	Float32 qsigf;
	Float32 qsigf_r;
	Sint32 sno;
	Sint32 blkno2;
	Uint8 *ibufdt;
	Uint8 *ibufdt_r;
	Sint16 code;
    Float32 dt_l;
    Float32 dt_r;

    d0_l = dly_l[0] * 65536;
    d1_l = dly_l[1] * 65536;
    
    d0_r = dly_r[0] * 65536;
    d1_r = dly_r[1] * 65536;
    
    kf0 = (k0 * 16) / 65536.0f;
    kf1 = (k1 * 16) / 65536.0f;
    
    ibufdt_r = (Uint8*)ibuf;
    
    for (blkno2 = 0; blkno2 < (nblk / 2); blkno2++) 
    {
        ibufdt = ibufdt_r;
        
        ibufdt_r += 18;
        
        code = BSWAP_U16_EX(*(Uint16*)ibufdt);
        
        if ((code & 0x8000)) 
        {
            return blkno2 * 2;
        }
        
        gain = (code & 0x1FFF) + 1;
        
        code = BSWAP_U16_EX(*(Uint16*)ibufdt_r);
        
        if ((code & 0x8000))
        {
            return blkno2 * 2;
        }

        gain_r = (code & 0x1FFF) + 1;
        
        ibufdt += 2;
        ibufdt_r += 2;
        
        for (sno = 0; sno < 32; sno += 2)
        {
            qsig = *ibufdt++;
            qsigf = AdxQtblFloat0[qsig];
            
            qsig_r = *ibufdt_r++;
            qsigf_r = AdxQtblFloat0[qsig_r];

            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt_r = (kf0 * d0_r) + (kf1 * d1_r) + (qsigf_r * gain_r);
            
            d1_r = d0_r;
            d0_r = dt_r;
            
            dt16 = d0_l;
            
            *obuf_l++ = dt16 >> 16;
            
            dt16 = d0_r;
            
            *obuf_r++ = dt16 >> 16;

            qsigf = AdxQtblFloat1[qsig];
            qsigf_r = AdxQtblFloat1[qsig_r];
            
            dt_l = (kf0 * d0_l) + (kf1 * d1_l) + (qsigf * gain);
            
            d1_l = d0_l;
            d0_l = dt_l;
            
            dt_r = (kf0 * d0_r) + (kf1 * d1_r) + (qsigf_r * gain_r);
            
            d1_r = d0_r;
            d0_r = dt_r;
            
            dt16 = d0_l;
            
            *obuf_l++ = dt16 >> 16;
            
            dt16 = d0_r;
            
            *obuf_r++ = dt16 >> 16;
        }
    }
    
    dly_l[0] = (Sint32)d0_l >> 16;
    dly_l[1] = (Sint32)d1_l >> 16;
    
    dly_r[0] = (Sint32)d0_r >> 16;
    dly_r[1] = (Sint32)d1_r >> 16;
    
    return nblk;
}

// 100% matching!
void ADX_SetDecodeSteAsMonoSw(Sint32 flag)
{
    adx_decode_output_mono_flag = flag;
}
