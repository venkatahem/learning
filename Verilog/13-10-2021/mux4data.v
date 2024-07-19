module Mux_4_1; 
wire out; 
reg I0, I1, I2,I3; 
reg S1, S0; 
mux4_1 mux(.I0(I0),.I1(I1),.I2(I2),.I3(I3),.S1(S1),.S0(S0),.out(out)); 
initial begin 
#0 I0=1; I1=0; I2=1;I3=0; S1=0; S0=0; 
#10 S1=0; S0=1; 
#10 S1=1; S0=0; 
#10 S1=1; S0=1; 
end 
initial begin 
$display("MUX 4:1 -- HEM -- Data Flow -- 2020503007");
end 
initial begin 
$monitor("I0=%b I1=%b I2=%b I3=%b S1=%b S0=%b output=%b",I0,I1,I2,I3,S1,S0,out);
end
endmodule 

module mux4_1(I0,I1,I2,I3,S1,S0,out); 
input I0, I1, I2,I3; 
input S0, S1; 
output out;

assign out = S1 ? (S0 ? I3 : I2) : (S0 ? I1 : I0) ;

endmodule