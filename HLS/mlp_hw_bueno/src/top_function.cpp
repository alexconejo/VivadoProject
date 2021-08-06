#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#include "mlp.h"

extern const float BiasesHidden1[64];
extern const float WeightHidden1[64][784];
extern const float BiasesHidden2 [128];
extern const float WeightHidden2 [128][64];
extern const float BiasesOut[10];
extern const float WeightOut[10][128];


uint8_t MLP (const float pixels[C_INTRO]){
	int i,j;
	float sumatorio=0, input=0,output=0, aux=0, posicion_mayor=0;
	float hiddenlayer1[C_HIDD];
	float hiddenlayer2[C_HIDD2];
	float outlayer[C_OUT];

	for(i=0; i< C_HIDD;i++){
		for(j=0;j<C_INTRO;j++){
			sumatorio+=WeightHidden1[i][j]*pixels[j];
		}
		input=sumatorio+BiasesHidden1[i];
		hiddenlayer1[i] = 1.0 / (1.0 + exp(-input));
		sumatorio=0;
	}

	for(i=0; i< C_HIDD2;i++){
		for(j=0;j<C_HIDD;j++){
			sumatorio+=WeightHidden2[i][j]*hiddenlayer1[j];
		}
		input=sumatorio+BiasesHidden2[i];
		hiddenlayer2[i] = 1.0 / (1.0 + exp(-input));
		sumatorio=0;
	}

	for(i=0; i< C_OUT;i++){
		for(j=0;j<C_HIDD2;j++){
			sumatorio+=WeightOut[i][j]*hiddenlayer2[j];
		}
		input=sumatorio+BiasesOut[i];
		outlayer[i] = 1.0 / (1.0 + exp(-input));
		sumatorio=0;
		if(outlayer[i]>aux){
			aux=outlayer[i];
			posicion_mayor=i;
		}
	}

	return posicion_mayor;
}

uint8_t Wrapped_MLP (AXI_VAL INPUT_STREAM[C_INTRO]){
#pragma HLS INTERFACE s_axilite port=return     bundle=CONTROL_BUS
#pragma HLS INTERFACE axis      port=INPUT_STREAM

	ap_uint<U> user;
	ap_uint<TI> id;
	ap_uint<TD> dest;
	T pixels[C_INTRO];

	for (int i=0;i<C_INTRO; i++){
		pixels[i] = pop_stream<T,U,TI,TD>(INPUT_STREAM[i],user,id,dest);
	}
	int digit=MLP(pixels);
	return digit;
}
