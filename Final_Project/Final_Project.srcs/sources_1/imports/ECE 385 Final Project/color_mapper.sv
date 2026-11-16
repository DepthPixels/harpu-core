//-------------------------------------------------------------------------
//    Color_Mapper.sv                                                    --
//    Stephen Kempf                                                      --
//    3-1-06                                                             --
//                                                                       --
//    Modified by David Kesler  07-16-2008                               --
//    Translated by Joe Meng    07-07-2013                               --
//    Modified by Zuofu Cheng   08-19-2023                               --
//                                                                       --
//    Fall 2023 Distribution                                             --
//                                                                       --
//    For use with ECE 385 USB + HDMI                                    --
//    University of Illinois ECE Department                              --
//-------------------------------------------------------------------------


module  color_mapper (
    input  logic [7:0] keycode,
    input  logic [9:0] drawX, drawY,
    output logic [3:0] red, green, blue    
);

    logic [11:0] color;

    always_comb begin
        if ((drawX < 640) && (drawY < 480))
            { red, green, blue } = color;
        else
            { red, green, blue } = 12'h000;
    end
    
    always_comb begin
        if (keycode == 8'h16) begin
            color = { 4'h0, 4'hF, 4'h0 };
        end else if (keycode == 8'h04) begin
            color = { 4'hF, 4'h0, 4'h0 };
        end else if (keycode == 8'h07) begin
            color = { 4'h0, 4'h0, 4'hF };
        end else begin
            color = { 4'h4, 4'hD, 4'hC };
        end
    end 
    
endmodule
