module Fourbit_addersub; 
reg [3:0] a,b; 
reg c0=0,m; 
wire [3:0] Sum; 
wire c1; 
bcdadd f1(.a(a), .b(b), .c(c0), .S(Sum), .Cout(c1)); 
initial begin 
#0  a=4'b1000; b=4'b1100; 
#10 a=4'b0011; b=4'b0011; 
#10 a=4'b0111; b=4'b1011;
end 
initial begin 
$display("Four Bit Adder-Subtractor (Behavioural) -- HEM -- 2020503007\n");
$monitor("a=%b b=%b sum=%b carry=%b" , a,b,Sum,c1);
end
endmodule 

module bcdadd(a,b,c,S,Cout); //Main module of one digit BCD adder
input [3:0]a;
input [3:0]b;
input c;
output[3:0]S;
output Cout;
wire [3:0]w;
wire y,c0,cl,c2,c3,c4,c5;
fulladd ml(a[0],b[0],c,w[0],c0);
fulladd m2(a[1],b[1],c0,w[1],cl);
fulladd m3(a[2],b[2],cl,w[2],c2);
fulladd m4(a[3],b[3],c2,w[3],c3);
assign y=c3|(w[3]&(w[2]|w[1]));
halfadd m5(w[1],y,S[1],c4);
fulladd m6(w[2],y,c4,S[2],c5);
halfadd m7(w[3],c5,S[3],Cout);
assign S=w;
endmodule

module fulladd(a,b,c,S,Cout); //submodule for fulladder
input a,b;
input c;
output S;
output Cout;
wire wl,w2,w3;
halfadd gl(a,b,w1,w2);
halfadd g2(wl,cin,S,w3);
assign Cout=w3|w2;
endmodule

module halfadd(a,b,S,Cout); //submodule for halfadder
input a,b;
output S,Cout;
assign S=a^b;
assign Cout=a&b;
endmodule
