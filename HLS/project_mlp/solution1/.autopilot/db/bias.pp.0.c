# 1 "../../mlp_hw/src/bias.c"
# 1 "../../mlp_hw/src/bias.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "C:/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 300 "C:/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "../../mlp_hw/src/bias.c" 2
const float BiasesHidden1[64] = {0.07893301878446415, 0.18067453139663692, -0.2903878187386645, -0.03876005896781437, 0.12588729215085442, 0.2555337196559217, -0.01183150838188082, 0.02478208043084896, 0.29548622509322015, -0.16256726231955154, -0.35185001498783214, -0.4237997603173161, -0.11795441998359352, -0.5505574223941035, -0.07512225939883496, -0.11666877918668854, 0.12600006195178576, -0.048993891252860015, -0.2851253792793106, -0.3431432266146811, 0.250225575185948, 0.16998884275554485, 0.0970861259936688, -0.3745850808349226, 0.3113320372730389, -0.07477573313159648, 0.2745132108171723, 0.08162795070658731, 0.0790174577439345, -0.17792632665370262, 0.5964189318155806, -0.21632872209583162, -0.19783278511170693, -0.38399745185896555, 0.23836532579582403, -0.054334108763029035, 0.06666104556196173, -0.21153878692809366, 0.07760427577616191, -0.04762440426842114, 0.29878556505716064, 0.035674924159989636, -0.43497609695000305, -0.010302884019157507, -0.07725739169173938, -0.10545974972810139, -0.40275059864090146, 0.18317797725763144, 0.1524775289393275, -0.1296876759410946, -0.3040165336291312, -0.5462031557511615, -0.2168425397693673, 0.30344025384903706, 0.15892202666645625, -0.7610443407880582, 0.3835314741017008, -0.047705393595204336, -0.48405566047239523, -0.058606328464386556, 0.08101285857343826, -0.05533978421326036, -0.22677716417229926, 0.2101594187314316, };
const float BiasesHidden2[128] = {-0.09059891590111974, -0.10638886172036684, 0.04006461596245814, -0.05375411352463905, -0.05548091557972232, 0.06665508407298291, 0.025373848557946114, -0.010162186744645495, 0.011140501918281451, -0.08001948985855901, -0.028802966725319942, 0.06174551023259704, -0.05461092941455406, 0.06532031767416711, -0.06434110401942554, -0.017761678764244483, -0.10824413596003386, 0.08971009563722573, 0.0304882439456863, -0.01864460398121551, 0.09417605736048067, 0.10086736793417654, -0.01640289276321986, 0.09524073135594886, 0.015508244481696142, -0.009640724680666818, -0.01768861608367913, 0.007401364738909183, -0.06896701537412932, 0.023547419120369915, -0.08525698104539188, 0.010690445856829187, -0.022531666926929976, 0.0374173892722302, 0.059550464878033095, -0.14742991600728977, 0.042005232593492765, 0.0028904172766750155, -0.08235403112838229, 0.038018756463540866, -0.06681694690502214, 0.020303670849176017, 0.0606546134945864, -0.035895520567373614, -0.01681752863695632, -0.052617912539070825, -0.01749695812960077, 0.045109900369272454, -0.1289182651611822, -0.06806408066489995, 0.11623123708575683, -0.053852701192504016, -0.1213711284771815, -0.06367254342504192, -0.11668715448677494, -0.040244353070707034, -0.030171372190387666, 0.03980009522183855, -0.02871733029497817, 0.03658307475252379, 0.024465154227989755, -0.12722649039868428, 0.06427528669851518, 0.07177629998932711, 0.004822658991798342, -0.023340881967325332, 0.06433587442066153, -0.018243946565203256, -0.09918036365399656, -0.057180040794053706, -0.0738693395979587, 0.03953376135270281, 0.10015587890316512, 0.01690847768397355, 0.07310160930080312, -0.08462325546000993, -0.06128440799741231, -0.09604381865454999, -0.02461705356658346, -0.03859236249171177, 0.05077856919747381, 0.0258310728017187, 0.029980098488518285, 0.041166397892446145, -0.019035776090353652, -0.08868692309638301, 0.04809713217438629, -0.07403075505543923, 0.007474137039633358, 0.054797733356621976, 0.07194637863695998, 0.0531836403274489, -0.12356042974252485, 0.046271532951276964, -0.11122926895114783, 0.11796314978787487, -0.04821047181690598, 0.12931498305068148, -0.07771236230550824, -0.13866506222568536, -0.164258333408163, -0.0022262757867550463, 0.10048379770340436, -0.011073358726599028, -0.005073248437756731, 0.04756607420824461, 0.10328955124619538, 0.006414199333060338, -0.07916812836205284, -0.09804603614235208, -0.1323576893570023, -0.0724544061725746, -0.08552474362415491, -0.08339983829033026, 0.0020892075889145526, 0.12022566536470079, -0.04368111980501325, -0.06610419270537264, 0.10435962610125124, -0.01054271044379323, 0.04242470654971389, 0.050937303039835395, 0.05853002928151794, -0.08714530574255579, 0.02350492616481747, -0.0307935679256222, 0.07407274366053442, -0.026050604995880744, };
const float BiasesOut[10]={0.029660294590785032, 0.07804932235663845, -0.09407099755917862, -0.03720304024825733, -0.06752550581319465, 0.011335090404317535, -0.09715315484588428, 0.057061674338424004, -0.1409159091225172, 0.051400500397748065, };
