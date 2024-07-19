module bool_mux;
wire out;
reg a, b, c, d;
bool_exp aa(.o(out), .a(a), .b(b), .c(c), .d(d));
initial begin
    #0 a=0; b=0; c=0; d=0;
    #10 a=0; b=0; c=0; d=1;
    #10 a=0; b=0; c=1; d=0;
    #10 a=0; b=0; c=1; d=1;
    #10 a=0; b=1; c=0; d=0;
    #10 a=0; b=1; c=0; d=1;
    #10 a=0; b=1; c=1; d=0;
    #10 a=0; b=1; c=1; d=1;
    #10 a=1; b=0; c=0; d=0;
    #10 a=1; b=0; c=0; d=1;
    #10 a=1; b=0; c=1; d=0;
    #10 a=1; b=0; c=1; d=1;
    #10 a=1; b=1; c=0; d=0;
    #10 a=1; b=1; c=0; d=1;
    #10 a=1; b=1; c=1; d=0;
    #10 a=1; b=1; c=1; d=1;
    //D is input and A,B,C are select lines
end
initial begin
$display("Que 3 -- D.K.Venkata Hem -- 2020503007\n");
$display("Solving boolean expression using 8:1 MUX F(a,b,c,d) = sum(1,2,6,7,11,14)\n");
$monitor("\na = %b  b %b  c = %b  d = %b\tOut(F) = %b\tTime=%3d",a,b,c,d,out,$time);
end
endmodule

module bool_exp(o, a, b, c, d);
    input a, b, c, d;
    output o;
    mux aa(.out(o), .i0(d), .i1(~d), .i2(1'b0), .i3(1'b1), .i4(1'b0), .i5(d), .i6(1'b0), .i7(~d), .s0(a), .s1(b), .s2(c));
endmodule

module mux(out, i0, i1, i2, i3, i4, i5, i6, i7, s0, s1, s2);
    input i0, i1, i2, i3, i4, i5, i6, i7;
    input s0, s1, s2;
    output out;
    wire a1, a2, a3, a4, a5, a6, a7, a8, w0, w1, w2;
    not n0(w0, s0);
    not n1(w1, s1);
    not n2(w2, s2);
    and b1(a1, w0, w1, w2, i0);
    and b2(a2, w0, w1, s2, i1);
    and b3(a3, w0, s1, w2, i2);
    and b4(a4, w0, s1, s2, i3);
    and b5(a5, s0, w1, w2, i4);
    and b6(a6, s0, w1, s2, i5);
    and b7(a7, s0, s1, w2, i6);
    and b8(a8, s0, s1, s2, i7);
    or o1(out, a1, a2, a3, a4, a5, a6, a7, a8);
endmodule