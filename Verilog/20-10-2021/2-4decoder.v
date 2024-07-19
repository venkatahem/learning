module de2to4_test;
reg a,b;
wire [0:3] d;
de2to4 aa(.a(a),.b(b),.d(d));
initial begin
  #0 a=0; b=0;
  #10 a=0; b=1;
  #10 a=1;b=0;
  #10 a=1;b=1;
end
initial begin
    $display("2:4 Decoder (Structural) -- HEM -- 2020503007");
  $monitor("A = %b,B = %b, Out: D[0]=%b, D[1]=%b, D[2]=%b, D[3]=%b",a,b,d[0],d[1],d[2],d[3]);
end
endmodule

module de2to4(a,b,d);
input a,b;
output [0:3] d;
wire w1,w2;
not n1(w1,a);
not n2(w2,b);
and a1(d[0],w1,w2);
and a2(d[1],w1,b);
and a3(d[2],a,w2);
and a4(d[3],a,b);
endmodule