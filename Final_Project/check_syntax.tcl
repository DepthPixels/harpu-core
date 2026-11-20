read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/sphere_shader.sv"
read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/math_sqrt.sv"
read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/sdf_scene.sv"
read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/ray_gen.sv"
read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/lut_inv_sqrt.sv"
read_verilog -sv "F:/ECE_385_Final_Project/Final_Project/Final_Project.srcs/sources_1/new/raymarch_core.sv"
synth_design -top raymarch_core -part xc7s50csga324-1 -rtl
exit
