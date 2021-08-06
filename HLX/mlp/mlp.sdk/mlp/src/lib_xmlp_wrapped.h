/*
 * lib_xmlp_wrapped.h
 *
 *  Created on: 26 ene. 2021
 *      Author: User
 */

#ifndef H_LIB_EXAMPLE_HW_H
#define H_LIB_EXAMPLE_HW_H

#define SIZE  784

//int Setup_HW_Accelerator(float A[DIM][DIM], float B[DIM][DIM], float res_hw[DIM][DIM], int dma_size);

int Run_HW_Accelerator(float imagesFloat[SIZE], int dma_size);

int Start_HW_Accelerator(void);

#endif
