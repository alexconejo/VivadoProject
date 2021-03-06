/*
 * lib_xmlp_wrapped.c
 *
 *  Created on: 26 ene. 2021
 *      Author: User
 */

// ==============================================================
// File generated on Tue Oct 27 16:43:43 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xwrapped_mlp.h"
#include "lib_xmlp_wrapped.h"


#include "platform.h"
#include "xparameters.h"
#include "xscugic.h"
#include "xaxidma.h"
#include "xil_printf.h"

#define XPAR_FABRIC_MLP_0_INTERRUPT_INTR XPAR_FABRIC_WRAPPED_MLP_0_INTERRUPT_INTR
#define XPAR_MLP_0_S_AXI_CONTROL_BUS_BASEADDR XPAR_WRAPPED_MLP_0_S_AXI_CONTROL_BUS_BASEADDR

volatile static int ResultExample = 0;

XWrapped_mlp xmlp_dev;

XWrapped_mlp_Config xmlp_config = {
	0,
	XPAR_MLP_0_S_AXI_CONTROL_BUS_BASEADDR
};

//Interrupt Controller Instance
XScuGic ScuGic;

// AXI DMA Instance
extern XAxiDma AxiDma;


int XMlpSetup(){
	return XWrapped_mlp_CfgInitialize(&xmlp_dev,&xmlp_config);
}

void XMlpStart(void *InstancePtr){
	XWrapped_mlp *pExample = (XWrapped_mlp *)InstancePtr;
	XWrapped_mlp_InterruptEnable(pExample,1);
	XWrapped_mlp_InterruptGlobalEnable(pExample);
	XWrapped_mlp_Start(pExample);
}


void XMlpIsr(void *InstancePtr){
	XWrapped_mlp *pExample = (XWrapped_mlp *)InstancePtr;

	//Disable the global interrupt
	XWrapped_mlp_InterruptGlobalDisable(pExample);
	//Disable the local interrupt
	XWrapped_mlp_InterruptDisable(pExample,0xffffffff);

	// clear the local interrupt
	XWrapped_mlp_InterruptClear(pExample,1);

	ResultExample = 1;

	XWrapped_mlp_InterruptEnable(pExample,1);
	XWrapped_mlp_InterruptGlobalEnable(pExample);

}

int XMlpSetupInterrupt()
{
	//This functions sets up the interrupt on the ARM
	int result;
	XScuGic_Config *pCfg = XScuGic_LookupConfig(XPAR_SCUGIC_SINGLE_DEVICE_ID);
	if (pCfg == NULL){
		print("Interrupt Configuration Lookup Failed\n\r");
		return XST_FAILURE;
	}
	result = XScuGic_CfgInitialize(&ScuGic,pCfg,pCfg->CpuBaseAddress);
	if(result != XST_SUCCESS){
		return result;
	}
	// self test
	result = XScuGic_SelfTest(&ScuGic);
	if(result != XST_SUCCESS){
		return result;
	}
	// Initialize the exception handler
	Xil_ExceptionInit();
	// Register the exception handler
	//print("Register the exception handler\n\r");
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,(Xil_ExceptionHandler)XScuGic_InterruptHandler,&ScuGic);
	//Enable the exception handler
	Xil_ExceptionEnable();
	// Connect the Adder ISR to the exception table
	//print("Connect the Adder ISR to the Exception handler table\n\r");
	result = XScuGic_Connect(&ScuGic,XPAR_FABRIC_MLP_0_INTERRUPT_INTR,(Xil_InterruptHandler)XMlpIsr,&xmlp_dev);
	if(result != XST_SUCCESS){
		return result;
	}
	//print("Enable the Adder ISR\n\r");
	XScuGic_Enable(&ScuGic,XPAR_FABRIC_MLP_0_INTERRUPT_INTR);
	return XST_SUCCESS;
}

int Setup_HW_Accelerator(float C_INTRO[SIZE], float res[SIZE], int dma_size)
//Setup the Vivado HLS Block
{
	int status = XMlpSetup();
	if(status != XST_SUCCESS){
		print("Error: example setup failed\n");
		return XST_FAILURE;
	}
	status =  XMlpSetupInterrupt();
	if(status != XST_SUCCESS){
		print("Error: interrupt setup failed\n");
		return XST_FAILURE;
	}

	XMlpStart(&xmlp_dev);


	return 0;
}



int Start_HW_Accelerator(void)
{
	int status = XMlpSetup();
	if(status != XST_SUCCESS){
		print("Error: example setup failed\n");
		return XST_FAILURE;
	}
	status =  XMlpSetupInterrupt();
	if(status != XST_SUCCESS){
		print("Error: interrupt setup failed\n");
		return XST_FAILURE;
	}

	XMlpStart(&xmlp_dev);

	return 0;
}

int Run_HW_Accelerator(float imagesFloat[SIZE], int dma_size)
{

	//transfer A to the Vivado HLS block
	int status = XAxiDma_SimpleTransfer(&AxiDma, (unsigned int) imagesFloat, dma_size, XAXIDMA_DMA_TO_DEVICE);
	if (status != XST_SUCCESS) {
		print("Error: DMA transfer (HW) to Vivado HLS block failed\n");
		return XST_FAILURE;
	}
	/* Wait for transfer to be done. Otherwise you'll get an error */
	while (XAxiDma_Busy(&AxiDma, XAXIDMA_DMA_TO_DEVICE)) ;

	while (!ResultExample);
	ResultExample = 0;
	u32 label = XWrapped_mlp_Get_return(&xmlp_dev);
	printf("La label es %f", label);

	/* Accelerator must me restarted */
	XMlpStart(&xmlp_dev);

	return 0;

}
