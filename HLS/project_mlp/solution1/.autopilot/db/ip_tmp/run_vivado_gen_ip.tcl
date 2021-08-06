create_project prj -part xczu3eg-sbva484-1-e -force
set_property target_language verilog [current_project]
set vivado_ver [version -short]
set COE_DIR "../../syn/verilog"
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_dadd_3_full_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_dadd_3_full_dsp_64]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_ddiv_20_no_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_ddiv_20_no_dsp_64]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_dexp_11_full_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_dexp_11_full_dsp_64]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_fadd_2_full_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_fadd_2_full_dsp_32]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_fcmp_0_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_fcmp_0_no_dsp_32]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_fmul_1_max_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_fmul_1_max_dsp_32]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_fpext_0_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_fpext_0_no_dsp_32]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_fptrunc_0_no_dsp_64_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_fptrunc_0_no_dsp_64]]
}
source "C:/Users/User/Desktop/VivadoWorkspace/VivadoHLS/project_mlp/solution1/syn/verilog/Wrapped_MLP_ap_sitofp_2_no_dsp_32_ip.tcl"
if {[regexp -nocase {2015\.3.*} $vivado_ver match] || [regexp -nocase {2016\.1.*} $vivado_ver match]} {
    extract_files -base_dir "./prjsrcs/sources_1/ip" [get_files -all -of [get_ips Wrapped_MLP_ap_sitofp_2_no_dsp_32]]
}
