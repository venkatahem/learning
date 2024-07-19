module Fourbit_addersub; 
reg [3:0] a,b; 
reg c0,m; 
wire [3:0] Sum; 
wire c1,c2,c3,Cout1; 
fa f1(.a(a[0]), .b(b[0]^m), .c(c0), .S(Sum[0]), .Cout(c1)); 
fa f2(.a(a[1]), .b(b[1]^m), .c(c1), .S(Sum[1]), .Cout(c2)); 
fa f3(.a(a[2]), .b(b[2]^m), .c(c2), .S(Sum[2]), .Cout(c3)); 
fa f4(.a(a[3]), .b(b[3]^m), .c(c3), .S(Sum[3]), .Cout(Cout1)); 
initial begin 
#0 m=1; c0=m; a=4'b1000; b=4'b1100; 
#10 a=4'b0011; b=4'b0011; 
#10 a=4'b0111; b=4'b1011;
end 
initial begin 
$display("Four Bit Adder-Subtractor (Structural) -- HEM -- 2020503007\n");
$display("m=1");
$monitor("a=%b b=%b sum=%b", a,b,Sum);
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