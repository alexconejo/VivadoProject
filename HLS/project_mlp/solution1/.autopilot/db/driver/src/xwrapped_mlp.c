// ==============================================================
// File generated on Thu Dec 17 22:11:27 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xwrapped_mlp.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XWrapped_mlp_CfgInitialize(XWrapped_mlp *InstancePtr, XWrapped_mlp_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_bus_BaseAddress = ConfigPtr->Control_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XWrapped_mlp_Start(XWrapped_mlp *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL) & 0x80;
    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XWrapped_mlp_IsDone(XWrapped_mlp *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XWrapped_mlp_IsIdle(XWrapped_mlp *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XWrapped_mlp_IsReady(XWrapped_mlp *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XWrapped_mlp_EnableAutoRestart(XWrapped_mlp *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL, 0x80);
}

void XWrapped_mlp_DisableAutoRestart(XWrapped_mlp *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_CTRL, 0);
}

u32 XWrapped_mlp_Get_return(XWrapped_mlp *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_AP_RETURN);
    return Data;
}
void XWrapped_mlp_InterruptGlobalEnable(XWrapped_mlp *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_GIE, 1);
}

void XWrapped_mlp_InterruptGlobalDisable(XWrapped_mlp *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_GIE, 0);
}

void XWrapped_mlp_InterruptEnable(XWrapped_mlp *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_IER);
    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_IER, Register | Mask);
}

void XWrapped_mlp_InterruptDisable(XWrapped_mlp *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_IER);
    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_IER, Register & (~Mask));
}

void XWrapped_mlp_InterruptClear(XWrapped_mlp *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XWrapped_mlp_WriteReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_ISR, Mask);
}

u32 XWrapped_mlp_InterruptGetEnabled(XWrapped_mlp *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_IER);
}

u32 XWrapped_mlp_InterruptGetStatus(XWrapped_mlp *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XWrapped_mlp_ReadReg(InstancePtr->Control_bus_BaseAddress, XWRAPPED_MLP_CONTROL_BUS_ADDR_ISR);
}

