/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "platform.h"
#include "xil_printf.h"
#include "xstatus.h"
#include "xtmrctr.h"
#include "xaxidma.h"
#include "lib_xmlp_wrapped.h"


/* No olvideis habilitar la librer???a xilffs en la configuraci???n del BSP */
#include "ff.h"
/* Recursos web */
/* http://elm-chan.org/fsw/ff/00index_e.html (referencia r???pida)
 * https://xilinx-wiki.atlassian.net/wiki/spaces/A/pages/18841771/xilffs (documentaci???n de Xilinx)
 */
#define BYTES 10
#define SIZE 784
#define DATA 7840
#define NUM_TESTS 1
static FATFS fat_fs;

float BiasesHidden1[64];
float WeightHidden1[64][784];
float BiasesHidden2 [128];
float WeightHidden2 [128][64];
float BiasesOut[10];
float WeightOut[10][128];

#define C_HIDD 64
#define C_HIDD2 128
#define C_OUT 10


// AXI DMA Instance
XAxiDma AxiDma;
// TIMER Instance
XTmrCtr timer_dev;

float _Alignas(16)imagesFloat[SIZE];
float _Alignas(16)labelsFloat[SIZE];

uint8_t* m_labels;
uint8_t* m_pixels;

u32 images[DATA];
u32 labels[DATA];

int MLP (float pixels[SIZE]);


int init_dma(){
	XAxiDma_Config *CfgPtr_0;
	int status;

	CfgPtr_0 = XAxiDma_LookupConfig( (XPAR_AXI_DMA_0_DEVICE_ID) );

	if(!CfgPtr_0){
		print("Error looking for AXI DMA [0] config\n\r");
		return XST_FAILURE;
	}

	status = XAxiDma_CfgInitialize(&AxiDma,CfgPtr_0);
	if(status != XST_SUCCESS){
		print("Error initializing DMA[0] \n\r");
		return XST_FAILURE;
	}

	//check for scatter gather mode
	/*if(XAxiDma_HasSg(&AxiDma)){
		print("Error DMA [0] configured in SG mode\n\r");
		return XST_FAILURE;
	}*/

	/* Disable interrupt, we use polling mode */
	XAxiDma_IntrDisable(&AxiDma, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

	// Reset DMA
	XAxiDma_Reset(&AxiDma);
	while (!XAxiDma_ResetIsDone(&AxiDma)) {}

	return XST_SUCCESS;

}
u32 mount_filesystem() {
	TCHAR *Path = "0:/";
	FRESULT res;
	res = f_mount(&fat_fs, Path, 1);

	if (res != FR_OK) {
		xil_printf("mount failed %d\n\r",res);
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

u32 umount_filesystem() {
	TCHAR *Path = "0:/";
	FRESULT res;
	res = f_mount(NULL, Path, 0);

	if (res != FR_OK) {
		xil_printf("umount failed %d\n\r",res);
		return XST_FAILURE;
	}
	return XST_SUCCESS;
}

/*u32 EndianSwap (u32 a){
    return (a<<24) | ((a<<8) & 0x00ff0000) |
           ((a>>8) & 0x0000ff00) | (a>>24);
}*/

u32 LoadFile(){
	FIL f_images;
	FIL f_labels;
	u32 bytes_read_images = 0;
	u32 bytes_read_labels = 0;


	if (mount_filesystem() == XST_FAILURE)
		return XST_FAILURE;

	/* Documentaci???n cabecera BMP
	 * https://docs.fileformat.com/image/bmp/
	 */
	FRESULT res_images = f_open(&f_images, "images", FA_READ);
	FRESULT res_labels = f_open(&f_labels,"labels",FA_READ);

	f_lseek(&f_images,16);

	if (res_images != FR_OK) {
		xil_printf("could not open the file %d\n\r",res_images);
		return XST_FAILURE;
	}

	if (res_labels != FR_OK) {
		xil_printf("could not open the file %d\n\r", res_labels);
		return XST_FAILURE;
	}

	f_read(&f_images, images, DATA, &bytes_read_images);
	f_read(&f_labels, labels, DATA, &bytes_read_labels);
	f_close(&f_images);
	f_close(&f_labels);

	for (size_t i = 0; i < SIZE; ++i){
		imagesFloat[i] = (float)images[i] / 255.0f;
	}

	printf("Bytes Read from images %d\r\n",bytes_read_images);
	printf("Bytes Read from labels %d\r\n",bytes_read_labels);


	return XST_SUCCESS;
}

int main()
{
	init_platform();

	print("Hello SD!\n\r");
	LoadFile();
	unsigned int dma_size = SIZE * sizeof(float);

	float acc_factor;
	unsigned int init_time, curr_time, calibration;
	unsigned int begin_time;
	unsigned int end_time;
	unsigned int run_time_sw = 0;
	unsigned int run_time_hw = 0;
	int status;
	int result;

	float res[SIZE];
	float pixels[SIZE];

	// Init DMA
	status = init_dma();
	if (status != XST_SUCCESS) {
		print("\rError: DMA init failed\n");
		return XST_FAILURE;
	}
	print("\nDMA Init done\n");

	// Setup HW timer
	status = XTmrCtr_Initialize(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	if (status != XST_SUCCESS) {
		print("Error: timer setup failed\n");
		//return XST_FAILURE;
	}
	XTmrCtr_SetOptions(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID,
			XTC_ENABLE_ALL_OPTION);

	// Calibrate HW timer
	XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	init_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	curr_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	calibration = curr_time - init_time;

	// call the software version of the function
	/*xil_printf("Running Matrix Mult in SW\n");
	XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	begin_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	for (int i = 0; i < NUM_TESTS; i++) {
		//result= MLP(pixels);
	}
	end_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	run_time_sw = end_time - begin_time - calibration;
	xil_printf(
			"\nTotal run time for SW on Processor is %d cycles over %d tests.\n",
			run_time_sw / NUM_TESTS, NUM_TESTS);

	// call the HW accelerator
	XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	begin_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);*/

	// Setup the HW Accelerator
	status = Start_HW_Accelerator(); //Just once

	//flush the cache. You have to do this every time data is changed
	Xil_DCacheFlushRange((unsigned int) imagesFloat, dma_size);
	Xil_DCacheFlushRange((unsigned int) res, dma_size);

	print("\rCache cleared\n\r");
	for (int i = 0; i < NUM_TESTS; i++) {
		status = Run_HW_Accelerator(imagesFloat, dma_size);
	}
	end_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	run_time_hw = end_time - begin_time - calibration;
	xil_printf(
			"Total run time for AXI DMA + HW accelerator is %d cycles over %d tests\n",
			run_time_hw / NUM_TESTS, NUM_TESTS);

	Xil_DCacheFlushRange((unsigned int)res,dma_size);

	// Loop measurement
	XTmrCtr_Reset(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	begin_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	for (int i = 0; i < NUM_TESTS; i++)
		;
	end_time = XTmrCtr_GetValue(&timer_dev, XPAR_AXI_TIMER_0_DEVICE_ID);
	run_time_sw = end_time - begin_time - calibration;
	xil_printf("Loop time for %d iterations is %d cycles\n", NUM_TESTS,
			run_time_sw);

	acc_factor = (float) run_time_sw / (float) run_time_hw;
	//xil_printf("Acceleration factor: %d.%d \n\n",
	//		(int) acc_factor, (int) (acc_factor * 1000) % 1000);

	printf("\r\033[1mAcceleration factor: %d.%d \033[0m\r\n\r\n",
			(int) acc_factor, (int) (acc_factor * 1000) % 1000);
	//Compare the results from sw and hw


	// HW vs. SW speedup factor
	acc_factor = (float) run_time_sw / (float) run_time_hw;
	//xil_printf("Acceleration factor: %d.%d \n\n",
	//		(int) acc_factor, (int) (acc_factor * 1000) % 1000);

	printf("\r\033[1mAcceleration factor: %d.%d \033[0m\r\n\r\n",
			(int) acc_factor, (int) (acc_factor * 1000) % 1000);

	cleanup_platform();
	return 0;
}

int MLP ( float pixels[SIZE]){
	int i,j;
	float sumatorio=0, input=0,output=0, aux=0, posicion_mayor=0;
	float hiddenlayer1[C_HIDD];
	float hiddenlayer2[C_HIDD2];
	float outlayer[C_OUT];

	for(i=0; i< C_HIDD;i++){
		for(j=0;j<SIZE;j++){
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
