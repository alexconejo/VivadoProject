// ==============================================================
// File generated on Thu Dec 17 22:11:25 +0100 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __MLP_BiasesHidden1_H__
#define __MLP_BiasesHidden1_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct MLP_BiasesHidden1_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 32;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(MLP_BiasesHidden1_ram) {
        ram[0] = "0b00111101101000011010011110100010";
        ram[1] = "0b00111110001110010000001010111111";
        ram[2] = "0b10111110100101001010110110110110";
        ram[3] = "0b10111101000111101100001011011110";
        ram[4] = "0b00111110000000001110100010011001";
        ram[5] = "0b00111110100000101101010101010001";
        ram[6] = "0b10111100010000011101100011110001";
        ram[7] = "0b00111100110010110000001111001010";
        ram[8] = "0b00111110100101110100100111111000";
        ram[9] = "0b10111110001001100111100000001000";
        ram[10] = "0b10111110101101000010010110101111";
        ram[11] = "0b10111110110110001111110001001000";
        ram[12] = "0b10111101111100011001001000010110";
        ram[13] = "0b10111111000011001111000101010101";
        ram[14] = "0b10111101100110011101100110110011";
        ram[15] = "0b10111101111011101111000000001010";
        ram[16] = "0b00111110000000010000011000101001";
        ram[17] = "0b10111101010010001010110111010010";
        ram[18] = "0b10111110100100011111101111110100";
        ram[19] = "0b10111110101011111011000001111000";
        ram[20] = "0b00111110100000000001110110010001";
        ram[21] = "0b00111110001011100001000110001110";
        ram[22] = "0b00111101110001101101010100010111";
        ram[23] = "0b10111110101111111100100110011110";
        ram[24] = "0b00111110100111110110011011101010";
        ram[25] = "0b10111101100110010010010000000101";
        ram[26] = "0b00111110100011001000110011111111";
        ram[27] = "0b00111101101001110010110010001110";
        ram[28] = "0b00111101101000011101001111101000";
        ram[29] = "0b10111110001101100011001001010010";
        ram[30] = "0b00111111000110001010111011101001";
        ram[31] = "0b10111110010111011000010101000111";
        ram[32] = "0b10111110010010101001010010101101";
        ram[33] = "0b10111110110001001001101101010000";
        ram[34] = "0b00111110011101000001011000001010";
        ram[35] = "0b10111101010111101000110101110001";
        ram[36] = "0b00111101100010001000010110010110";
        ram[37] = "0b10111110010110001001110110100000";
        ram[38] = "0b00111101100111101110111011111110";
        ram[39] = "0b10111101010000110001000111001111";
        ram[40] = "0b00111110100110001111101001101100";
        ram[41] = "0b00111101000100100001111111011111";
        ram[42] = "0b10111110110111101011010100110000";
        ram[43] = "0b10111100001010001100110101101101";
        ram[44] = "0b10111101100111100011100100100000";
        ram[45] = "0b10111101110101111111101101001000";
        ram[46] = "0b10111110110011100011010101010100";
        ram[47] = "0b00111110001110111001001100000010";
        ram[48] = "0b00111110000111000010001100010010";
        ram[49] = "0b10111110000001001100110011011001";
        ram[50] = "0b10111110100110111010100000001110";
        ram[51] = "0b10111111000010111101001111111000";
        ram[52] = "0b10111110010111100000101111111001";
        ram[53] = "0b00111110100110110101110010000101";
        ram[54] = "0b00111110001000101011110001110101";
        ram[55] = "0b10111111010000101101001111001101";
        ram[56] = "0b00111110110001000101111000111101";
        ram[57] = "0b10111101010000110110011010111011";
        ram[58] = "0b10111110111101111101011000100101";
        ram[59] = "0b10111101011100000000110100110001";
        ram[60] = "0b00111101101001011110101000010010";
        ram[61] = "0b10111101011000101010101111111000";
        ram[62] = "0b10111110011010000011100001000110";
        ram[63] = "0b00111110010101110011010000001000";


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


SC_MODULE(MLP_BiasesHidden1) {


static const unsigned DataWidth = 32;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


MLP_BiasesHidden1_ram* meminst;


SC_CTOR(MLP_BiasesHidden1) {
meminst = new MLP_BiasesHidden1_ram("MLP_BiasesHidden1_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~MLP_BiasesHidden1() {
    delete meminst;
}


};//endmodule
#endif
