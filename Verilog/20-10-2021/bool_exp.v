module bool_exp_test;
    wire o;
    reg a,b,c,d;
    bool_exp aa(.o(o), .a(a), .b(b), .c(c), .d(d));
    initial begin
        #0 a=0;b=0;c=0;d=0;
        #10 a=0;b=0;c=0;d=1;
        #20 a=0;b=0;c=1;d=0;
        #30 a=0;b=0;c=1;d=1;
        #40 a=0;b=1;c=0;d=0;
        #50 a=0;b=1;c=0;d=1;
        #60 a=0;b=1;c=1;d=0;
        #70 a=0;b=1;c=1;d=1;
        #80 a=1;b=0;c=0;d=0;
        #90 a=1;b=0;c=0;d=1;
        #100 a=1;b=0;c=1;d=0;
        #110 a=1;b=0;c=1;d=1;
        #120 a=1;b=1;c=0;d=0;
        #130 a=1;b=1;c=0;d=1;
        #140 a=1;b=1;c=1;d=0;
        #150 a=1;b=1;c=1;d=1;
    end
    initial begin
    $display("Solving Boolean Exp using MUX -- HEM -- 2020503007");
        $monitor("A=%b,B=%b,C=%b,D=%b, Out = %b",a,b,c,d,o);
    end
endmodule

module bool_exp(a,b,c,d,o);
    input a,b,c,d;
    output o;
    mux m1(.y(o), .i0(c&d), .i1(d), .i2(c|~d), .i3(d), .s0(b), .s1(a));
endmodule

module mux(y,i0,i1,i2,i3,s0,s1);
    input i0,i1,i2,i3;
    input s0,s1;
    output y;
    assign y = (~s1 & ~s0 & i0)|(~s1 & s0 & i1)|(s1 & ~s0 & i2) |(s1 & s0 & i3);
endmodule
