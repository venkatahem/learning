module full_sub4_test;
    wire d,e;
    reg a,b,c;
    full_sub4 aa(.d(d), .e(e), .a(a), .b(b), .c(c));
    initial begin
        #0 a=0;b=0;c=0;
        #10 a=0;b=0;c=1;
        #20 a=0;b=1;c=0;
        #30 a=0;b=1;c=1;
        #40 a=1;b=0;c=0;
        #50 a=1;b=0;c=1;
        #60 a=1;b=1;c=0;
        #70 a=1;b=1;c=1;
    end
    initial begin
        $display("Subtractor -- HEM -- 2020503007");
        $monitor("A=%b, B=%b, C=%b, Diff = %b, Borrow= %b",a,b,c,d,e);
    end
endmodule

module full_sub4(d,e,a,b,c);
    input a,b,c;
    output d,e;
    mux m1(.y(d), .i0(a), .i1(~a), .i2(~a), .i3(a),    .s0(c), .s1(b));
    mux m2(.y(e), .i0(1'b0), .i1(~a), .i2(~a), .i3(1'b1), .s0(c), .s1(b));
endmodule

module mux(y,i0,i1,i2,i3,s0,s1);
    input i0,i1,i2,i3;
    input s0,s1;
    output y;
    assign y = (~s1 & ~s0 & i0)|(~s1 & s0 & i1)|(s1 & ~s0 & i2) |(s1 & s0 & i3);
endmodule
