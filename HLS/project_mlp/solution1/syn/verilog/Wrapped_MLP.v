// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="Wrapped_MLP,hls_ip_2018_3,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu3eg-sbva484-1-e,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=9.201400,HLS_SYN_LAT=547559,HLS_SYN_TPT=none,HLS_SYN_MEM=116,HLS_SYN_DSP=34,HLS_SYN_FF=5965,HLS_SYN_LUT=9693,HLS_VERSION=2018_3}" *)

module Wrapped_MLP (
        ap_clk,
        ap_rst_n,
        INPUT_STREAM_TDATA,
        INPUT_STREAM_TVALID,
        INPUT_STREAM_TREADY,
        INPUT_STREAM_TKEEP,
        INPUT_STREAM_TSTRB,
        INPUT_STREAM_TUSER,
        INPUT_STREAM_TLAST,
        INPUT_STREAM_TID,
        INPUT_STREAM_TDEST,
        s_axi_CONTROL_BUS_AWVALID,
        s_axi_CONTROL_BUS_AWREADY,
        s_axi_CONTROL_BUS_AWADDR,
        s_axi_CONTROL_BUS_WVALID,
        s_axi_CONTROL_BUS_WREADY,
        s_axi_CONTROL_BUS_WDATA,
        s_axi_CONTROL_BUS_WSTRB,
        s_axi_CONTROL_BUS_ARVALID,
        s_axi_CONTROL_BUS_ARREADY,
        s_axi_CONTROL_BUS_ARADDR,
        s_axi_CONTROL_BUS_RVALID,
        s_axi_CONTROL_BUS_RREADY,
        s_axi_CONTROL_BUS_RDATA,
        s_axi_CONTROL_BUS_RRESP,
        s_axi_CONTROL_BUS_BVALID,
        s_axi_CONTROL_BUS_BREADY,
        s_axi_CONTROL_BUS_BRESP,
        interrupt
);

parameter    ap_ST_fsm_state1 = 3'd1;
parameter    ap_ST_fsm_state2 = 3'd2;
parameter    ap_ST_fsm_state3 = 3'd4;
parameter    C_S_AXI_CONTROL_BUS_DATA_WIDTH = 32;
parameter    C_S_AXI_CONTROL_BUS_ADDR_WIDTH = 5;
parameter    C_S_AXI_DATA_WIDTH = 32;

parameter C_S_AXI_CONTROL_BUS_WSTRB_WIDTH = (32 / 8);
parameter C_S_AXI_WSTRB_WIDTH = (32 / 8);

input   ap_clk;
input   ap_rst_n;
input  [31:0] INPUT_STREAM_TDATA;
input   INPUT_STREAM_TVALID;
output   INPUT_STREAM_TREADY;
input  [3:0] INPUT_STREAM_TKEEP;
input  [3:0] INPUT_STREAM_TSTRB;
input  [3:0] INPUT_STREAM_TUSER;
input  [0:0] INPUT_STREAM_TLAST;
input  [4:0] INPUT_STREAM_TID;
input  [4:0] INPUT_STREAM_TDEST;
input   s_axi_CONTROL_BUS_AWVALID;
output   s_axi_CONTROL_BUS_AWREADY;
input  [C_S_AXI_CONTROL_BUS_ADDR_WIDTH - 1:0] s_axi_CONTROL_BUS_AWADDR;
input   s_axi_CONTROL_BUS_WVALID;
output   s_axi_CONTROL_BUS_WREADY;
input  [C_S_AXI_CONTROL_BUS_DATA_WIDTH - 1:0] s_axi_CONTROL_BUS_WDATA;
input  [C_S_AXI_CONTROL_BUS_WSTRB_WIDTH - 1:0] s_axi_CONTROL_BUS_WSTRB;
input   s_axi_CONTROL_BUS_ARVALID;
output   s_axi_CONTROL_BUS_ARREADY;
input  [C_S_AXI_CONTROL_BUS_ADDR_WIDTH - 1:0] s_axi_CONTROL_BUS_ARADDR;
output   s_axi_CONTROL_BUS_RVALID;
input   s_axi_CONTROL_BUS_RREADY;
output  [C_S_AXI_CONTROL_BUS_DATA_WIDTH - 1:0] s_axi_CONTROL_BUS_RDATA;
output  [1:0] s_axi_CONTROL_BUS_RRESP;
output   s_axi_CONTROL_BUS_BVALID;
input   s_axi_CONTROL_BUS_BREADY;
output  [1:0] s_axi_CONTROL_BUS_BRESP;
output   interrupt;

 reg    ap_rst_n_inv;
wire    ap_start;
reg    ap_done;
reg    ap_idle;
(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    ap_ready;
reg   [31:0] INPUT_STREAM_data_V_0_data_out;
wire    INPUT_STREAM_data_V_0_vld_in;
wire    INPUT_STREAM_data_V_0_vld_out;
wire    INPUT_STREAM_data_V_0_ack_in;
reg    INPUT_STREAM_data_V_0_ack_out;
reg   [31:0] INPUT_STREAM_data_V_0_payload_A;
reg   [31:0] INPUT_STREAM_data_V_0_payload_B;
reg    INPUT_STREAM_data_V_0_sel_rd;
reg    INPUT_STREAM_data_V_0_sel_wr;
wire    INPUT_STREAM_data_V_0_sel;
wire    INPUT_STREAM_data_V_0_load_A;
wire    INPUT_STREAM_data_V_0_load_B;
reg   [1:0] INPUT_STREAM_data_V_0_state;
wire    INPUT_STREAM_data_V_0_state_cmp_full;
wire    INPUT_STREAM_dest_V_0_vld_in;
reg    INPUT_STREAM_dest_V_0_ack_out;
reg   [1:0] INPUT_STREAM_dest_V_0_state;
reg    INPUT_STREAM_TDATA_blk_n;
wire    ap_CS_fsm_state2;
wire   [0:0] exitcond_fu_130_p2;
wire   [9:0] i_1_fu_136_p2;
reg    ap_block_state2;
reg   [9:0] pixels_address0;
reg    pixels_ce0;
reg    pixels_we0;
wire   [31:0] pixels_d0;
wire   [31:0] pixels_q0;
wire    grp_MLP_fu_113_ap_start;
wire    grp_MLP_fu_113_ap_done;
wire    grp_MLP_fu_113_ap_idle;
wire    grp_MLP_fu_113_ap_ready;
wire   [9:0] grp_MLP_fu_113_pixels_address0;
wire    grp_MLP_fu_113_pixels_ce0;
wire   [7:0] grp_MLP_fu_113_ap_return;
reg   [9:0] i_reg_102;
reg    grp_MLP_fu_113_ap_start_reg;
reg    ap_block_state2_ignore_call0;
wire    ap_CS_fsm_state3;
wire   [63:0] tmp_s_fu_142_p1;
reg   [2:0] ap_NS_fsm;
wire   [7:0] ap_return;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
#0 INPUT_STREAM_data_V_0_sel_rd = 1'b0;
#0 INPUT_STREAM_data_V_0_sel_wr = 1'b0;
#0 INPUT_STREAM_data_V_0_state = 2'd0;
#0 INPUT_STREAM_dest_V_0_state = 2'd0;
#0 grp_MLP_fu_113_ap_start_reg = 1'b0;
end

Wrapped_MLP_CONTROL_BUS_s_axi #(
    .C_S_AXI_ADDR_WIDTH( C_S_AXI_CONTROL_BUS_ADDR_WIDTH ),
    .C_S_AXI_DATA_WIDTH( C_S_AXI_CONTROL_BUS_DATA_WIDTH ))
Wrapped_MLP_CONTROL_BUS_s_axi_U(
    .AWVALID(s_axi_CONTROL_BUS_AWVALID),
    .AWREADY(s_axi_CONTROL_BUS_AWREADY),
    .AWADDR(s_axi_CONTROL_BUS_AWADDR),
    .WVALID(s_axi_CONTROL_BUS_WVALID),
    .WREADY(s_axi_CONTROL_BUS_WREADY),
    .WDATA(s_axi_CONTROL_BUS_WDATA),
    .WSTRB(s_axi_CONTROL_BUS_WSTRB),
    .ARVALID(s_axi_CONTROL_BUS_ARVALID),
    .ARREADY(s_axi_CONTROL_BUS_ARREADY),
    .ARADDR(s_axi_CONTROL_BUS_ARADDR),
    .RVALID(s_axi_CONTROL_BUS_RVALID),
    .RREADY(s_axi_CONTROL_BUS_RREADY),
    .RDATA(s_axi_CONTROL_BUS_RDATA),
    .RRESP(s_axi_CONTROL_BUS_RRESP),
    .BVALID(s_axi_CONTROL_BUS_BVALID),
    .BREADY(s_axi_CONTROL_BUS_BREADY),
    .BRESP(s_axi_CONTROL_BUS_BRESP),
    .ACLK(ap_clk),
    .ARESET(ap_rst_n_inv),
    .ACLK_EN(1'b1),
    .ap_start(ap_start),
    .interrupt(interrupt),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_idle(ap_idle),
    .ap_return(grp_MLP_fu_113_ap_return)
);

Wrapped_MLP_pixels #(
    .DataWidth( 32 ),
    .AddressRange( 784 ),
    .AddressWidth( 10 ))
pixels_U(
    .clk(ap_clk),
    .reset(ap_rst_n_inv),
    .address0(pixels_address0),
    .ce0(pixels_ce0),
    .we0(pixels_we0),
    .d0(pixels_d0),
    .q0(pixels_q0)
);

MLP grp_MLP_fu_113(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst_n_inv),
    .ap_start(grp_MLP_fu_113_ap_start),
    .ap_done(grp_MLP_fu_113_ap_done),
    .ap_idle(grp_MLP_fu_113_ap_idle),
    .ap_ready(grp_MLP_fu_113_ap_ready),
    .pixels_address0(grp_MLP_fu_113_pixels_address0),
    .pixels_ce0(grp_MLP_fu_113_pixels_ce0),
    .pixels_q0(pixels_q0),
    .ap_return(grp_MLP_fu_113_ap_return)
);

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        INPUT_STREAM_data_V_0_sel_rd <= 1'b0;
    end else begin
        if (((1'b1 == INPUT_STREAM_data_V_0_ack_out) & (1'b1 == INPUT_STREAM_data_V_0_vld_out))) begin
            INPUT_STREAM_data_V_0_sel_rd <= ~INPUT_STREAM_data_V_0_sel_rd;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        INPUT_STREAM_data_V_0_sel_wr <= 1'b0;
    end else begin
        if (((1'b1 == INPUT_STREAM_data_V_0_ack_in) & (1'b1 == INPUT_STREAM_data_V_0_vld_in))) begin
            INPUT_STREAM_data_V_0_sel_wr <= ~INPUT_STREAM_data_V_0_sel_wr;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        INPUT_STREAM_data_V_0_state <= 2'd0;
    end else begin
        if ((((2'd2 == INPUT_STREAM_data_V_0_state) & (1'b0 == INPUT_STREAM_data_V_0_vld_in)) | ((2'd3 == INPUT_STREAM_data_V_0_state) & (1'b0 == INPUT_STREAM_data_V_0_vld_in) & (1'b1 == INPUT_STREAM_data_V_0_ack_out)))) begin
            INPUT_STREAM_data_V_0_state <= 2'd2;
        end else if ((((2'd1 == INPUT_STREAM_data_V_0_state) & (1'b0 == INPUT_STREAM_data_V_0_ack_out)) | ((2'd3 == INPUT_STREAM_data_V_0_state) & (1'b0 == INPUT_STREAM_data_V_0_ack_out) & (1'b1 == INPUT_STREAM_data_V_0_vld_in)))) begin
            INPUT_STREAM_data_V_0_state <= 2'd1;
        end else if (((~((1'b0 == INPUT_STREAM_data_V_0_vld_in) & (1'b1 == INPUT_STREAM_data_V_0_ack_out)) & ~((1'b0 == INPUT_STREAM_data_V_0_ack_out) & (1'b1 == INPUT_STREAM_data_V_0_vld_in)) & (2'd3 == INPUT_STREAM_data_V_0_state)) | ((2'd1 == INPUT_STREAM_data_V_0_state) & (1'b1 == INPUT_STREAM_data_V_0_ack_out)) | ((2'd2 == INPUT_STREAM_data_V_0_state) & (1'b1 == INPUT_STREAM_data_V_0_vld_in)))) begin
            INPUT_STREAM_data_V_0_state <= 2'd3;
        end else begin
            INPUT_STREAM_data_V_0_state <= 2'd2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        INPUT_STREAM_dest_V_0_state <= 2'd0;
    end else begin
        if ((((2'd2 == INPUT_STREAM_dest_V_0_state) & (1'b0 == INPUT_STREAM_dest_V_0_vld_in)) | ((2'd3 == INPUT_STREAM_dest_V_0_state) & (1'b0 == INPUT_STREAM_dest_V_0_vld_in) & (1'b1 == INPUT_STREAM_dest_V_0_ack_out)))) begin
            INPUT_STREAM_dest_V_0_state <= 2'd2;
        end else if ((((2'd1 == INPUT_STREAM_dest_V_0_state) & (1'b0 == INPUT_STREAM_dest_V_0_ack_out)) | ((2'd3 == INPUT_STREAM_dest_V_0_state) & (1'b0 == INPUT_STREAM_dest_V_0_ack_out) & (1'b1 == INPUT_STREAM_dest_V_0_vld_in)))) begin
            INPUT_STREAM_dest_V_0_state <= 2'd1;
        end else if (((~((1'b0 == INPUT_STREAM_dest_V_0_vld_in) & (1'b1 == INPUT_STREAM_dest_V_0_ack_out)) & ~((1'b0 == INPUT_STREAM_dest_V_0_ack_out) & (1'b1 == INPUT_STREAM_dest_V_0_vld_in)) & (2'd3 == INPUT_STREAM_dest_V_0_state)) | ((2'd1 == INPUT_STREAM_dest_V_0_state) & (1'b1 == INPUT_STREAM_dest_V_0_ack_out)) | ((2'd2 == INPUT_STREAM_dest_V_0_state) & (1'b1 == INPUT_STREAM_dest_V_0_vld_in)))) begin
            INPUT_STREAM_dest_V_0_state <= 2'd3;
        end else begin
            INPUT_STREAM_dest_V_0_state <= 2'd2;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst_n_inv == 1'b1) begin
        grp_MLP_fu_113_ap_start_reg <= 1'b0;
    end else begin
        if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
            grp_MLP_fu_113_ap_start_reg <= 1'b1;
        end else if ((grp_MLP_fu_113_ap_ready == 1'b1)) begin
            grp_MLP_fu_113_ap_start_reg <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        i_reg_102 <= i_1_fu_136_p2;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        i_reg_102 <= 10'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == INPUT_STREAM_data_V_0_load_A)) begin
        INPUT_STREAM_data_V_0_payload_A <= INPUT_STREAM_TDATA;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == INPUT_STREAM_data_V_0_load_B)) begin
        INPUT_STREAM_data_V_0_payload_B <= INPUT_STREAM_TDATA;
    end
end

always @ (*) begin
    if (((exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        INPUT_STREAM_TDATA_blk_n = INPUT_STREAM_data_V_0_state[1'd0];
    end else begin
        INPUT_STREAM_TDATA_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        INPUT_STREAM_data_V_0_ack_out = 1'b1;
    end else begin
        INPUT_STREAM_data_V_0_ack_out = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == INPUT_STREAM_data_V_0_sel)) begin
        INPUT_STREAM_data_V_0_data_out = INPUT_STREAM_data_V_0_payload_B;
    end else begin
        INPUT_STREAM_data_V_0_data_out = INPUT_STREAM_data_V_0_payload_A;
    end
end

always @ (*) begin
    if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        INPUT_STREAM_dest_V_0_ack_out = 1'b1;
    end else begin
        INPUT_STREAM_dest_V_0_ack_out = 1'b0;
    end
end

always @ (*) begin
    if (((grp_MLP_fu_113_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state3))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((grp_MLP_fu_113_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state3))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        pixels_address0 = tmp_s_fu_142_p1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        pixels_address0 = grp_MLP_fu_113_pixels_address0;
    end else begin
        pixels_address0 = 'bx;
    end
end

always @ (*) begin
    if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        pixels_ce0 = 1'b1;
    end else if ((1'b1 == ap_CS_fsm_state3)) begin
        pixels_ce0 = grp_MLP_fu_113_pixels_ce0;
    end else begin
        pixels_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        pixels_we0 = 1'b1;
    end else begin
        pixels_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else if ((~((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out)) & (exitcond_fu_130_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((grp_MLP_fu_113_ap_done == 1'b1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign INPUT_STREAM_TREADY = INPUT_STREAM_dest_V_0_state[1'd1];

assign INPUT_STREAM_data_V_0_ack_in = INPUT_STREAM_data_V_0_state[1'd1];

assign INPUT_STREAM_data_V_0_load_A = (~INPUT_STREAM_data_V_0_sel_wr & INPUT_STREAM_data_V_0_state_cmp_full);

assign INPUT_STREAM_data_V_0_load_B = (INPUT_STREAM_data_V_0_state_cmp_full & INPUT_STREAM_data_V_0_sel_wr);

assign INPUT_STREAM_data_V_0_sel = INPUT_STREAM_data_V_0_sel_rd;

assign INPUT_STREAM_data_V_0_state_cmp_full = ((INPUT_STREAM_data_V_0_state != 2'd1) ? 1'b1 : 1'b0);

assign INPUT_STREAM_data_V_0_vld_in = INPUT_STREAM_TVALID;

assign INPUT_STREAM_data_V_0_vld_out = INPUT_STREAM_data_V_0_state[1'd0];

assign INPUT_STREAM_dest_V_0_vld_in = INPUT_STREAM_TVALID;

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

always @ (*) begin
    ap_block_state2 = ((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out));
end

always @ (*) begin
    ap_block_state2_ignore_call0 = ((exitcond_fu_130_p2 == 1'd0) & (1'b0 == INPUT_STREAM_data_V_0_vld_out));
end

always @ (*) begin
    ap_rst_n_inv = ~ap_rst_n;
end

assign exitcond_fu_130_p2 = ((i_reg_102 == 10'd784) ? 1'b1 : 1'b0);

assign grp_MLP_fu_113_ap_start = grp_MLP_fu_113_ap_start_reg;

assign i_1_fu_136_p2 = (i_reg_102 + 10'd1);

assign pixels_d0 = INPUT_STREAM_data_V_0_data_out;

assign tmp_s_fu_142_p1 = i_reg_102;

endmodule //Wrapped_MLP
