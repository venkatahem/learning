module en8to3test;
reg [7:0] a;
wire b,c,d;
en8to3 aa(.a(a),.b(b),.c(c),.d(d));
initial begin
  #0 a=8'b00000001;
  #10 a=8'b00000010;
  #10 a=8'b00000100;
  #10 a=8'b00001000;
  #10 a=8'b00010000;
  #10 a=8'b00100000;
  #10 a=8'b01000000;
  #10 a=8'b10000000;
end
initial begin
    $display("8:3 Encoder (Dat Flow)-- HEM -- 2020503007");
    $monitor("A = %b, Out1 = %b, Out2 = %b Out3=%b",a,b,c,d);
end
endmodule

module en8to3(a,b,c,d);
input [7:0]a;
output b,c,d;
assign b = a[7]|a[6]|a[5]|a[4];
assign c = a[7]|a[6]|a[3]|a[2];
assign d = a[7]|a[5]|a[3]|a[1];
endmodule