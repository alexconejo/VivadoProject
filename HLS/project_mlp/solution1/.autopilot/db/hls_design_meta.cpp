#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("INPUT_STREAM_TDATA", 32, hls_in, 0, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TVALID", 1, hls_in, 6, "axis", "in_vld", 1),
	Port_Property("INPUT_STREAM_TREADY", 1, hls_out, 6, "axis", "in_acc", 1),
	Port_Property("INPUT_STREAM_TKEEP", 4, hls_in, 1, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TSTRB", 4, hls_in, 2, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TUSER", 4, hls_in, 3, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TLAST", 1, hls_in, 4, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TID", 5, hls_in, 5, "axis", "in_data", 1),
	Port_Property("INPUT_STREAM_TDEST", 5, hls_in, 6, "axis", "in_data", 1),
	Port_Property("s_axi_CONTROL_BUS_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_AWADDR", 5, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_ARADDR", 5, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_CONTROL_BUS_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "Wrapped_MLP";
