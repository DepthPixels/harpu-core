# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct F:\ECE_385_Final_Project\Vitis_Workspace\harpu_top\platform.tcl
# 
# OR launch xsct and run below command.
# source F:\ECE_385_Final_Project\Vitis_Workspace\harpu_top\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {harpu_top}\
-hw {F:\ECE_385_Final_Project\Final_Project\harpu_top.xsa}\
-out {F:/ECE_385_Final_Project/Vitis_Workspace}

platform write
domain create -name {standalone_microblaze_0} -display-name {standalone_microblaze_0} -os {standalone} -proc {microblaze_0} -runtime {cpp} -arch {32-bit} -support-app {hello_world}
platform generate -domains 
platform active {harpu_top}
platform generate -quick
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
platform active {harpu_top}
platform config -updatehw {F:/ECE_385_Final_Project/Final_Project/harpu_top.xsa}
platform clean
platform generate
