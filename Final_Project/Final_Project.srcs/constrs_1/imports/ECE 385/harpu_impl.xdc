# Implementation-only timing constraints
# The 100 MHz system clock and 25 MHz video pixel clock cross at the dual-port BRAM (fb_mem_inst),
# which operates asynchronously across physical port boundaries.
set_clock_groups -asynchronous \
    -group [get_clocks -include_generated_clocks Clk] \
    -group [get_clocks -include_generated_clocks clk_out1_clk_wiz_0]
