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
$display("HEM -- 202053007 --8241 to 2421-- Data Flow");
  $monitor("BCD = %b , 2421 = %b",in,out);
end
endmodule

module bcdto2421(in,out);
input [0:3] in;
output [3:0] out;
assign out[3] = in[0]|(in[1]&in[2])|(in[1]&in[3]);
assign out[2] = in[0]|(in[1]&in[2])|(in[1]&(~in[3]));
assign out[1] = in[0]|((~in[1])&in[2])|(in[1]&(~in[2])&in[3]);
assign out[0] = in[3];
endmodule