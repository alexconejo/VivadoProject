// ==============================================================
// File generated on Thu Dec 17 22:11:21 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __Wrapped_MLP_ddiv_ibs__HH__
#define __Wrapped_MLP_ddiv_ibs__HH__
#include "ACMP_ddiv.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int dout_WIDTH>
SC_MODULE(Wrapped_MLP_ddiv_ibs) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    ACMP_ddiv<ID, 22, din0_WIDTH, din1_WIDTH, dout_WIDTH> ACMP_ddiv_U;

    SC_CTOR(Wrapped_MLP_ddiv_ibs):  ACMP_ddiv_U ("ACMP_ddiv_U") {
        ACMP_ddiv_U.clk(clk);
        ACMP_ddiv_U.reset(reset);
        ACMP_ddiv_U.ce(ce);
        ACMP_ddiv_U.din0(din0);
        ACMP_ddiv_U.din1(din1);
        ACMP_ddiv_U.dout(dout);

    }

};

#endif //
