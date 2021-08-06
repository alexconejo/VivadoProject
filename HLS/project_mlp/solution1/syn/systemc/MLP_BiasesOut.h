// ==============================================================
// File generated on Thu Dec 17 22:11:27 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __MLP_BiasesOut_H__
#define __MLP_BiasesOut_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct MLP_BiasesOut_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 10;
  static const unsigned AddressWidth = 4;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(MLP_BiasesOut_ram) {
        ram[0] = "0b00111100111100101111101000100101";
        ram[1] = "0b00111101100111111101100001010011";
        ram[2] = "0b10111101110000001010100001001100";
        ram[3] = "0b10111101000110000110001000110111";
        ram[4] = "0b10111101100010100100101011010000";
        ram[5] = "0b00111100001110011011011011010001";
        ram[6] = "0b10111101110001101111100000111100";
        ram[7] = "0b00111101011010011011100110000001";
        ram[8] = "0b10111110000100000100110001000011";
        ram[9] = "0b00111101010100101000100101010101";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(MLP_BiasesOut) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 10;
static const unsigned AddressWidth = 4;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


MLP_BiasesOut_ram* meminst;


SC_CTOR(MLP_BiasesOut) {
meminst = new MLP_BiasesOut_ram("MLP_BiasesOut_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~MLP_BiasesOut() {
    delete meminst;
}


};//endmodule
#endif
