module Fourbit_adder; 
reg [3:0] a,b; 
reg c0; 
wire [3:0] Sum; 
wire c1,c2,c3,Cout1; 
fa f1(.a(a[0]), .b(b[0]), .c(c0), .S(Sum[0]), .Cout(c1)); 
fa f2(.a(a[1]), .b(b[1]), .c(c1), .S(Sum[1]), .Cout(c2)); 
fa f3(.a(a[2]), .b(b[2]), .c(c2), .S(Sum[2]), .Cout(c3)); 
fa f4(.a(a[3]), .b(b[3]), .c(c3), .S(Sum[3]), .Cout(Cout1)); 
initial begin 
#0 c0=0; a=4'b1000; b=4'b1100; 
#10  a=4'b0111; b=4'b1011; 
#10  a=4'b0111; b=4'b0011;
end 
initial begin 
$display("Four Bit Adder (Structural) -- HEM -- 2020503007\n");
$monitor("a=%b b=%b sum=%b cout=%b", a,b,Sum,Cout1);
end
endmodule 

module fa(a,b,c,S,Cout); 
input a,b,c; 
output S, Cout; 
wire S1,C1,C2; 
ha h1(.a(a), .b(b), .S(S1), .Cout(C1));
ha h2(.a(S1), .b(c), .S(S), . Cout(C2)); 
or(Cout, C1, C2);
endmodule 

module ha(a,b,S,Cout); 
input a,b; 
output S, Cout; 
xor(S,a,b); 
and(Cout,a,b);
endmodule