module comp_test;
reg [3:0] a,b;
wire less,equal,greater;
comp aa(.a(a),.b(b),.less(less),.equal(equal),.greater(greater));
initial begin
  #0 a=4'b0001; b=4'b0001;
  #10 a=4'b0011; b=4'b0001;
  #10 a=4'b0011; b=4'b0111;
end
initial begin
  $display("Comparator (Behavioural) -- HEM -- 2020503007");
  $monitor("\na=%b, b=%b\nless=%b equal=%b greater=%b",a,b,less,equal,greater);
end
endmodule

module comp(a,b,less,equal,greater);
input[3:0] a,b;
output less,equal,greater;
reg less,equal,greater;
reg y0,y1,x2,x3;
always@(a,b)
begin
  y0 = (a[0]*b[0]) + ((~a[0])*(~b[0]));
  y1 = (a[1]*b[1]) + ((~a[1])*(~b[1]));
  x2 = (a[2]*b[2]) + ((~a[2])*(~b[2]));
  x3 = (a[3]*b[3]) + ((~a[3])*(~b[3]));
  equal = y0*y1*x2*x3;
  less = ((~a[3])*b[3])+(x3*(~a[2])*b[2])+(x3*x2*(~a[1])*b[1])+(x3*x2*y1*(~a[0])*b[0]);
  greater = ((~b[3])*a[3])+(x3*(~b[2])*a[2])+(x3*x2*(~b[1])*a[1])+(x3*x2*y1*(~b[0])*a[0]);
end
endmodule