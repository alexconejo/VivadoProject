// ==============================================================
// File generated on Thu Dec 17 22:11:27 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xwrapped_mlp.h"

extern XWrapped_mlp_Config XWrapped_mlp_ConfigTable[];

XWrapped_mlp_Config *XWrapped_mlp_LookupConfig(u16 DeviceId) {
	XWrapped_mlp_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XWRAPPED_MLP_NUM_INSTANCES; Index++) {
		if (XWrapped_mlp_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XWrapped_mlp_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XWrapped_mlp_Initialize(XWrapped_mlp *InstancePtr, u16 DeviceId) {
	XWrapped_mlp_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XWrapped_mlp_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XWrapped_mlp_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

