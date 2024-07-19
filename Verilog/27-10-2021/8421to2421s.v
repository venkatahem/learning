module bcdto2421_test;
reg [3:0] in;
wire [3:0] out;
bcdto2421 aa(.in(in),.out(out));
initial begin
#0 in = 4'b0000;
#10 in = 4'b0001;
#10 in = 4'b0010;
#10 in = 4'b0011;
#10 in = 4'b0100;
#10 in = 4'b0101;
#10 in = 4'b0110;
#10 in = 4'b0111;
#10 in = 4'b1000;
#10 in = 4'b1001;
end
initial begin
$display("HEM -- 202053007 --8241 to 2421-- Structural");
  $monitor("BCD = %b , 2421 = %b",in,out);
end
endmodule

module bcdto2421(in,out);
input [0:3] in;
output [3:0] out;
wire w1,w2,w3,w4,w5,w6,w7,w8;
not n1(w1,in[1]);
not n2(w2,in[2]);
not n3(w3,in[3]);
and a1(w4,in[1],in[2]);
and a2(w5,in[1],in[3]);
and a3(w6,in[1],w3);
and a4(w7,w1,in[2]);
and a5(w8,in[1],w2,in[3]);
or o1(out[3],in[0],w1,w2);
or o2(out[2],in[0],w4,w6);
or o3(out[1],in[0],w7,w8);
and o4(out[0],in[3],1);

endmodule