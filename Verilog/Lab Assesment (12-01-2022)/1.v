module demorgan_test;
reg a,b,c;
wire o1,o2,o3,o4;
demorgan aa(.a(a),.b(b),.c(c),.o1(o1),.o2(o2),.o3(o3),.o4(o4));
initial begin
    #0 a=0; b=0; c=0; 
    #10 a=1; b=0; c=0; 
    #10 a=0; b=1; c=0; 
    #10 a=0; b=0; c=1; 
    #10 a=1; b=1; c=0; 
    #10 a=1; b=0; c=1; 
    #10 a=0; b=1; c=1; 
    #10 a=1; b=1; c=1; 
end
initial begin
    $display("Que-1 -- Demorgan theorem -- D.K.Venkata Hem -- 2020503007\n");
    $monitor("-------\nX1 = %b  X2 = %b  X3 = %b\n1st\n(X1+X2+X3)' = %b & X1'.X2'.X3' = %b\n2nd\n(X1.X2.X3)' = %b & X1'+X2'+X3' = %b\tTime = %2d",a,b,c,o1,o2,o3,o4,$time);
end
endmodule

module demorgan(a,b,c,o1,o2,o3,o4);
input a,b,c;
output o1,o2,o3,o4;
wire w0,w1,w2,w3,w4,w5,w6,w7,w8;
not n1(w0,a);
not n2(w1,b);
not n3(w2,c);
or a1(w3,a,b);
or a2(w4,w3,c);
not n4(o1,w4);
and b1(w5,w0,w1);
and b2(o2,w5,w2);
and b3(w6,a,b);
and b4(w7,w6,c);
not n5(o3,w7);
or a3(w8,w0,w1);
or a4(o4,w8,w2);
endmodule
