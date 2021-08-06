#ifndef __MLP_H__
#define __MLP_H__

#include <cassert>
#include <ap_axi_sdata.h>

#define C_TOTAL 10000
#define C_INTRO 784
#define C_HIDD 64
#define C_HIDD2 128
#define C_OUT 10
#define U 4
#define TI 5
#define TD 5
typedef float T;


typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef ap_axiu<32,U,TI,TD> AXI_VAL;

template <typename _T, int _U, int _TI, int _TD>
T pop_stream(ap_axiu <sizeof(_T)*8,_U,_TI,_TD> const &e, ap_uint<_U> &user,ap_uint<_TI> &id, ap_uint<_TD> &dest)
{
#pragma HLS INLINE

	assert(sizeof(_T) == sizeof(int));
	union
	{
		int ival;
		_T oval;
	} converter;
	converter.ival = e.data;
	_T ret = converter.oval;

	volatile ap_uint<sizeof(_T)> strb = e.strb;
	volatile ap_uint<sizeof(_T)> keep = e.keep;
	user = e.user;
	volatile ap_uint<1> last = e.last;
	id = e.id;
	dest = e.dest;

	return ret;
}
template <typename _T, int _U, int _TI, int _TD> ap_axiu <sizeof(_T)*8,_U,_TI,_TD> push_stream(T const &v,
		bool last = false, ap_uint<_U> const user = 0,ap_uint<_TI> const id = 0,
			const ap_uint<_TD> dest = 0)
{
#pragma HLS INLINE
	ap_axiu<sizeof(_T)*8,_U,_TI,_TD> e;

	assert(sizeof(_T) == sizeof(int));
	union
	{
		int oval;
		_T ival;
	} converter;
	converter.ival = v;
	e.data = converter.oval;

	// set it to sizeof(T) ones
	e.strb = -1;
	e.keep = 15; //e.strb;
	e.user = user;
	e.last = last ? 1 : 0;
	e.id = id;
	e.dest = dest;
	return e;
}
uint8_t MLP (const float pixels[C_INTRO]);
uint8_t Wrapped_MLP (AXI_VAL INPUT_STREAM[C_INTRO]);


#endif

