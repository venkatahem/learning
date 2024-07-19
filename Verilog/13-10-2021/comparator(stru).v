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
  $display("Comparator (Structural) -- HEM -- 2020503007");
  $monitor("\na=%b, b=%b\nless=%b equal=%b greater=%b",a,b,less,equal,greater);
end
endmodule

module comp(a,b,less,equal,greater);
input[3:0] a,b;
output less,equal,greater;
wire [20:0] w;
wire [3:0] s,t,u;

not n1(w[0],a[0]);
not n2(w[1],a[1]);
not n3(w[2],a[2]);
not n4(w[3],a[3]);
not n5(w[4],b[0]);
not n6(w[5],b[1]);
not n7(w[6],b[2]);
not n8(w[7],b[3]);

and a1(w[8],a[0],b[0]);
and a2(w[9],a[1],b[1]);
and a3(w[10],a[2],b[2]);
and a4(w[11],a[3],b[3]);

and a5(w[12],w[0],w[4]);
and a6(w[13],w[1],w[5]);
and a7(w[14],w[2],w[6]);
and a8(w[15],w[3],w[7]);

or o1(s[0],w[8],w[12]);
or o2(s[1],w[9],w[13]);
or o3(s[2],w[10],w[14]);
or o4(s[3],w[11],w[15]);

and a9(equal,s[0],s[1],s[2],s[3]);

and a10(t[0],a[3],w[7]);
and a11(t[1],s[3],a[2],w[6]);
and a12(t[2],s[3],s[2],a[1],w[5]);
and a13(t[3],s[3],s[2],s[1],a[0],w[4]);

or o5(greater,t[0],t[1],t[2],t[3]);

and a14(u[0],b[3],w[3]);
and a15(u[1],s[3],b[2],w[2]);
and a16(u[2],s[3],s[2],b[1],w[1]);
and a17(u[3],s[3],s[2],s[1],b[0],w[0]);

or o6(less,u[0],u[1],u[2],u[3]);

endmodule