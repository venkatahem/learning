module en4to2test;
reg [3:0] a;
wire b,c;
en4to2 aa(.a(a),.b(b),.c(c));
initial begin
  #0 a=4'b0001;
  #10 a=4'b0010;
  #10 a=4'b0100;
  #10 a=4'b1000;
end
initial begin
    $display("4:2 Encoder (Structural)-- HEM -- 2020503007");
    $monitor("A = %b, Out1 = %b, Out2 = %b",a,b,c);
end
endmodule

module en4to2(a,b,c);
input [3:0]a;
output b,c;
or o1(b,a[3],a[2]);
or o2(c,a[3],a[1]);
endmodule