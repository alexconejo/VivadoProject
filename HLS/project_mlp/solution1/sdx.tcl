# ==============================================================
# File generated on Thu Dec 17 22:11:30 +0100 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../../../../mlp_hw_bueno/src/testbench_function.cpp -cflags { -Wno-unknown-pragmas}
add_files -tb ../../../../mlp_hw_bueno/src/t10k-labels-idx1-ubyte -cflags { -Wno-unknown-pragmas}
add_files -tb ../../../../mlp_hw_bueno/src/t10k-images-idx3-ubyte -cflags { -Wno-unknown-pragmas}
add_files ../../mlp_hw_bueno/src/top_function.cpp
add_files ../../mlp_hw_bueno/src/mlp.h
add_files ../../mlp_hw/src/coef.c
add_files ../../mlp_hw/src/bias.c
set_part xczu3eg-sbva484-1-e
create_clock -name default -period 10
