-makelib xcelium_lib/xilinx_vip -sv \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "C:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "C:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "C:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
  "C:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "C:/Xilinx/Vivado/2018.3/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_4 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/zynq_ultra_ps_e_vip_v1_0_4 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/00a3/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_zynq_ultra_ps_e_0_0/sim/design_mlp_zynq_ultra_ps_e_0_0_vip_wrapper.v" \
-endlib
-makelib xcelium_lib/axi_lite_ipif_v3_0_4 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/66ea/hdl/axi_lite_ipif_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/lib_cdc_v1_0_2 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/lib_pkg_v1_0_2 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/0513/hdl/lib_pkg_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_timer_v2_0_20 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/e9c1/hdl/axi_timer_v2_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_axi_timer_0_0/sim/design_mlp_axi_timer_0_0.vhd" \
-endlib
-makelib xcelium_lib/generic_baseblocks_v2_1_0 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_register_slice_v2_1_18 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/cc23/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/64f4/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_3 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/64f4/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib xcelium_lib/axi_data_fifo_v2_1_17 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/c4fd/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_crossbar_v2_1_19 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/6c9d/hdl/axi_crossbar_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_xbar_0/sim/design_mlp_xbar_0.v" \
-endlib
-makelib xcelium_lib/proc_sys_reset_v5_0_13 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_rst_ps8_0_100M_0/sim/design_mlp_rst_ps8_0_100M_0.vhd" \
-endlib
-makelib xcelium_lib/lib_fifo_v1_0_12 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/544a/hdl/lib_fifo_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/lib_srl_fifo_v1_0_2 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/51ce/hdl/lib_srl_fifo_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_datamover_v5_1_20 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/dfb3/hdl/axi_datamover_v5_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_sg_v4_1_11 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/efa7/hdl/axi_sg_v4_1_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_dma_v7_1_19 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/09b0/hdl/axi_dma_v7_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_axi_dma_0_0/sim/design_mlp_axi_dma_0_0.vhd" \
-endlib
-makelib xcelium_lib/xbip_utils_v3_0_9 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/0da8/hdl/xbip_utils_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_utils_v2_0_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/ec8e/hdl/axi_utils_v2_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_pipe_v3_0_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/442e/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_wrapper_v3_0_4 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_addsub_v3_0_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/a04b/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_multadd_v3_0_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/b226/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_bram18k_v3_0_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/c08f/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/mult_gen_v12_0_14 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/6bb5/hdl/mult_gen_v12_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/floating_point_v7_1_7 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/c63e/hdl/floating_point_v7_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_BiasesHidden1.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_BiasesHidden2.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_BiasesOut.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_hiddenlayer1.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_hiddenlayer2.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_WeightHidden1.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_WeightHidden2.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/MLP_WeightOut.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_CONTROL_BUS_s_axi.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_dadd_hbi.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_ddiv_ibs.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_dexp_jbC.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_fadd_bkb.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_fcmp_g8j.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_fmul_cud.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_fpextfYi.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_fptrueOg.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_pixels.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP_sitofdEe.v" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/verilog/Wrapped_MLP.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_dadd_3_full_dsp_64.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_ddiv_20_no_dsp_64.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_dexp_11_full_dsp_64.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_fadd_2_full_dsp_32.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_fcmp_0_no_dsp_32.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_fmul_1_max_dsp_32.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_fpext_0_no_dsp_32.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_fptrunc_0_no_dsp_64.vhd" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/d475/hdl/ip/Wrapped_MLP_ap_sitofp_2_no_dsp_32.vhd" \
  "../../../bd/design_mlp/ip/design_mlp_Wrapped_MLP_0_0/sim/design_mlp_Wrapped_MLP_0_0.vhd" \
-endlib
-makelib xcelium_lib/xlconstant_v1_1_5 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/4649/hdl/xlconstant_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_0/sim/bd_bbf8_one_0.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_1/sim/bd_bbf8_psr_aclk_0.vhd" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/979d/hdl/sc_util_v1_0_vl_rfs.sv" \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_2/sim/bd_bbf8_s00mmu_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_3/sim/bd_bbf8_s00tr_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/9ade/hdl/sc_si_converter_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_4/sim/bd_bbf8_s00sic_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_5/sim/bd_bbf8_s00a2s_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_6/sim/bd_bbf8_sarn_0.sv" \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_7/sim/bd_bbf8_srn_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_8/sim/bd_bbf8_m00s2a_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/ip/ip_9/sim/bd_bbf8_m00e_0.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/bd_0/sim/bd_bbf8.v" \
  "../../../bd/design_mlp/ip/design_mlp_axi_smc_0/sim/design_mlp_axi_smc_0.v" \
-endlib
-makelib xcelium_lib/axi_protocol_converter_v2_1_18 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/7a04/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_clock_converter_v2_1_17 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/693a/hdl/axi_clock_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/blk_mem_gen_v8_4_2 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/37c2/simulation/blk_mem_gen_v8_4.v" \
-endlib
-makelib xcelium_lib/axi_dwidth_converter_v2_1_18 \
  "../../../../mlp.srcs/sources_1/bd/design_mlp/ipshared/0815/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_mlp/ip/design_mlp_auto_ds_0/sim/design_mlp_auto_ds_0.v" \
  "../../../bd/design_mlp/ip/design_mlp_auto_pc_0/sim/design_mlp_auto_pc_0.v" \
  "../../../bd/design_mlp/ip/design_mlp_auto_ds_1/sim/design_mlp_auto_ds_1.v" \
  "../../../bd/design_mlp/ip/design_mlp_auto_pc_1/sim/design_mlp_auto_pc_1.v" \
  "../../../bd/design_mlp/sim/design_mlp.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

