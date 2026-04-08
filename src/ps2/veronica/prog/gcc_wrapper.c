#ifdef __cplusplus
	#define EXTERN extern "C"
#else
	#define EXTERN extern
#endif


/*
 *	Exported routines
 *
 */
 
EXTERN float _f_ulltof(unsigned long long ul);
EXTERN double _d_utod(unsigned int ui);

EXTERN int _dpfeq(double left, double right);
EXTERN int _dpfne(double left, double right);
EXTERN int _dpflt(double left, double right);
EXTERN int _dpfle(double left, double right);
EXTERN int _dpfgt(double left, double right);
EXTERN int _dpfge(double left, double right);


/*
 *	Imported routines (GCC)
 *
 */
 
EXTERN float __floatdisf(unsigned long long ul);

EXTERN double __floatdidf(unsigned long long ul);
EXTERN int dpcmp(double left, double right);


EXTERN float _f_ulltof(unsigned long long ul) {
	signed long long sl = (signed long long) ul;
	
	if (sl > 0)	
		return __floatdisf(ul);
	else {
		float f = __floatdisf((ul>>1)|(ul&1));
		return f+f;
	}
}



EXTERN double _d_ulltod(unsigned long long ul) {
	signed long long sl = (signed long long) ul;
	
	if (sl > 0)	
		return __floatdidf(ul);
	else {
		double d = __floatdidf((ul>>1)|(ul&1));
		return d+d;
	}
}


EXTERN double _d_utod(unsigned int ui) {
	return _d_ulltod(ui);
}


/*
 *	The GCC runtime has only one float compare function that
 *	return a number to tell how the float compare.  Our backend
 *	assume the compare functions will return a boolean.  
 *	This wrapper makes the intreface between GCC and our backend.
 *
 */

EXTERN int _dpfeq(double left, double right)
{
	return dpcmp(left, right) == 0;
}


EXTERN int _dpfne(double left, double right)
{
	return dpcmp(left, right) != 0;
}


EXTERN int _dpflt(double left, double right)
{
	return dpcmp(left, right) < 0;
}


EXTERN int _dpfle(double left, double right)
{
	return dpcmp(left, right) <= 0;
}


EXTERN int _dpfgt(double left, double right)
{
	return dpcmp(left, right) > 0;
}


EXTERN int _dpfge(double left, double right)
{
	return dpcmp(left, right) >= 0;
}

