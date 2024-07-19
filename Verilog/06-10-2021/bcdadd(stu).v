module bcd_TEST;
    reg [3:0] a,b;
    reg C0 = 0;
    wire [3:0] Sum;
    wire Cout;
    bcd b1(.a(a),.b(b),.C0(C0),.Sum(Sum),.Cout(Cout));
    initial begin
    #0 a=4'b0111; b=4'b0011; 
    #10 a=4'b0011; b=4'b0001; 
    #10 a=4'b1000; b=4'b1001; 
    #10 a=4'b1000; b=4'b1000; 
    end
    initial begin
    $display("BCD Adder (Structural) -- HEM -- 2020503007\n");
    $monitor("a=%b b=%b cout=%b sum=%b",a, b, Cout, Sum);
    end
endmodule 

module ha(a, b, Sum, C);
    input a,b;
    output Sum, C;
    xor x1(Sum,a,b);
    and a1(C,a,b);
endmodule

module fa(a, b, c,Sum, C);
    input a,b,c;
    output Sum, C;
    wire Sum1 ,C1, C2;
    ha ha1(.a(a),.b(b),.Sum(Sum1),.C(C1));
    ha ha2(.a(Sum1),.b(c),.Sum(Sum),.C(C2)); 
    or o1(C, C1, C2);
endmodule

module four_bit_adder(a, b,C0, Sum, Cout);
    input [3:0] a,b;
    input C0;
    output [3:0]Sum;
    output Cout;
    wire C1,C2,C3;
    fa fa1(.a(a[0]), .b(b[0]), .c(C0), .Sum(Sum[0]), .C(C1));
    fa fa2(.a(a[1]), .b(b[1]), .c(C1), .Sum(Sum[1]), .C(C2));
    fa fa3(.a(a[2]), .b(b[2]), .c(C2), .Sum(Sum[2]), .C(C3));
    fa fa4(.a(a[3]), .b(b[3]), .c(C3), .Sum(Sum[3]), .C(Cout));
endmodule 


module bcd(a, b, C0, Sum, Cout);
    input [3:0]a,b;
    input C0;
    output [3:0]Sum;
    output Cout;
    wire [3:0] w1,c;
    wire w2, w3, w4, w5, w6,Cout;
    four_bit_adder fba1(.a(a),.b(b),.C0(C0),.Sum(w1),.Cout(w2));
    buf b1(c[0], 0);
    and a1(w4, w1[3], w1[2]);
    and a2(w5, w1[3], w1[1]);
    or o1(w6, w4, w5);
    or o2(c[1], w6, w2);
    buf b2(c[2], c[1]);
    buf b3(c[3], 0);
    buf b4(Cout, c[1]);
    four_bit_adder fba2(.a(w1),.b(c),.C0(C0),.Sum(Sum),.Cout(w3));
endmodule




