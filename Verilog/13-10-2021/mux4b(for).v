module Mux_4TO1; 
wire out; 
reg [3:0] in; 
reg [1:0] select; 
mux4_1 mux(.in(in),.out(out)); 
initial begin 
    #0 in=4'b1000; select=2'b00; 
    #10 select=2'b01; 
    #10 select=2'b10; 
    #10 select=2'b11; 
    end 
    initial begin 
        $display("The behaviour of 4:1 multiplexer is given below"); 
        end 
        initial begin 
            $monitor("input=%b select=%b output=%b",in, select,out); 
            end
endmodule 

module mux4_1(in,out); 
input [0:3] in; 
integer i;
//input [1:0] select; 
output out; 
reg out;
always @(in) 
begin 
    for(i=0;i<4;i++)
    begin

    if(i==0) 
    out=in[0];

    else if(i==1) 
    out=in[1];

    else if(i==2) 
    out=in[2];

    else out=in[3];

    end
end 
endmodule