module bcd_TEST;
    reg [3:0] a,b;
    reg C0 = 0;
    wire [3:0] Sum;
    wire Cout;
    bcd b1(.a(a),.b(b),.C0(C0),.Sum(Sum),.Cout(Cout));
    initial begin
    #0 a=4'b0011; b=4'b0001; 
    #10 a=4'b0111; b=4'b0011; 
    #10 a=4'b1000; b=4'b1000; 
    #10 a=4'b1000; b=4'b1001; 
    end
    initial begin
    $display("BCD Adder (Behavioural) -- HEM -- 2020503007\n");
    $monitor("a=%b b=%b Cout=%b sum=%b ", a,b,Cout,Sum);
    end
endmodule 

module ha(a, b, Sum, Carry);
    input a,b;
    output Sum, Carry;
    reg Sum, Carry;
    always @(a,b) 
    begin
        Sum = a ^ b;
        Carry = a & b;
    end
endmodule

module fa(a, b, c,Sum, Carry);
    input a,b,c;
    output Sum, Carry;
    wire Sum1, Carry1, Carry2;
    reg Carry;
    ha h1(.a(a), .b(b), .Sum(Sum1), .Carry(Carry1));
    ha h2(.a(Sum1), .b(c), .Sum(Sum), .Carry(Carry2));
    always @(Carry1,Carry2) 
    begin
        Carry = Carry1 | Carry2;
    end
endmodule

module four_bit_adder(a, b,C0, Sum, Cout);
    input [3:0] a,b;
    input C0;
    output [3:0]Sum;
    output Cout;
    wire Carry1,Carry2,Cout;
    fa f1(.a(a[0]), .b(b[0]), .c(C0), .Sum(Sum[0]), .Carry(Carry1));
    fa f2(.a(a[1]), .b(b[1]), .c(Carry1), .Sum(Sum[1]), .Carry(Carry2));
    fa f3(.a(a[2]), .b(b[2]), .c(Carry2), .Sum(Sum[2]), .Carry(Carry3));
    fa f4(.a(a[3]), .b(b[3]), .c(Carry3), .Sum(Sum[3]), .Carry(Cout));
endmodule 

module bcd(a, b, C0, Sum, Cout);
    input [3:0]a,b;
    input C0;
    output [3:0]Sum;
    output Cout;
    reg [3:0] c;
    reg Cout;
    wire [3:0] w1;
    wire w2, w3;
    four_bit_adder fba1(.a(a),.b(b),.C0(C0),.Sum(w1),.Cout(w2));
    always@(w1,w2) 
    begin
        c[0] = 0;
        c[1] = w2 | (w1[3] & w1[2]) | (w1[3] & w1[1]);
        c[2] = c[1];
        c[3] = 0;
        Cout = c[1];
    end
    four_bit_adder fba2(.a(w1),.b(c),.C0(1'b0),.Sum(Sum),.Cout(w3));
endmodule


