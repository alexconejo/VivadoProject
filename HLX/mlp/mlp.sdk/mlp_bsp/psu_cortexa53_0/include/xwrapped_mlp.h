// ==============================================================
// File generated on Thu Dec 17 22:11:27 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XWRAPPED_MLP_H
#define XWRAPPED_MLP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xwrapped_mlp_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_bus_BaseAddress;
} XWrapped_mlp_Config;
#endif

typedef struct {
    u32 Control_bus_BaseAddress;
    u32 IsReady;
} XWrapped_mlp;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XWrapped_mlp_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XWrapped_mlp_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XWrapped_mlp_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XWrapped_mlp_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XWrapped_mlp_Initialize(XWrapped_mlp *InstancePtr, u16 DeviceId);
XWrapped_mlp_Config* XWrapped_mlp_LookupConfig(u16 DeviceId);
int XWrapped_mlp_CfgInitialize(XWrapped_mlp *InstancePtr, XWrapped_mlp_Config *ConfigPtr);
#else
int XWrapped_mlp_Initialize(XWrapped_mlp *InstancePtr, const char* InstanceName);
int XWrapped_mlp_Release(XWrapped_mlp *InstancePtr);
#endif

void XWrapped_mlp_Start(XWrapped_mlp *InstancePtr);
u32 XWrapped_mlp_IsDone(XWrapped_mlp *InstancePtr);
u32 XWrapped_mlp_IsIdle(XWrapped_mlp *InstancePtr);
u32 XWrapped_mlp_IsReady(XWrapped_mlp *InstancePtr);
void XWrapped_mlp_EnableAutoRestart(XWrapped_mlp *InstancePtr);
void XWrapped_mlp_DisableAutoRestart(XWrapped_mlp *InstancePtr);
u32 XWrapped_mlp_Get_return(XWrapped_mlp *InstancePtr);


void XWrapped_mlp_InterruptGlobalEnable(XWrapped_mlp *InstancePtr);
void XWrapped_mlp_InterruptGlobalDisable(XWrapped_mlp *InstancePtr);
void XWrapped_mlp_InterruptEnable(XWrapped_mlp *InstancePtr, u32 Mask);
void XWrapped_mlp_InterruptDisable(XWrapped_mlp *InstancePtr, u32 Mask);
void XWrapped_mlp_InterruptClear(XWrapped_mlp *InstancePtr, u32 Mask);
u32 XWrapped_mlp_InterruptGetEnabled(XWrapped_mlp *InstancePtr);
u32 XWrapped_mlp_InterruptGetStatus(XWrapped_mlp *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
