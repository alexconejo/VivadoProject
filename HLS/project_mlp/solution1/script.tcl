############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project project_mlp
set_top Wrapped_MLP
add_files ../../mlp_hw_bueno/src/top_function.cpp
add_files ../../mlp_hw_bueno/src/mlp.h
add_files ../../mlp_hw/src/coef.c
add_files ../../mlp_hw/src/bias.c
add_files -tb ../../mlp_hw_bueno/src/testbench_function.cpp -cflags "-Wno-unknown-pragmas"
add_files -tb ../../mlp_hw_bueno/src/t10k-labels-idx1-ubyte -cflags "-Wno-unknown-pragmas"
add_files -tb ../../mlp_hw_bueno/src/t10k-images-idx3-ubyte -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./project_mlp/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -setup
export_design -rtl verilog -format ip_catalog
