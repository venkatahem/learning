module jdoodle; 
reg a,b,c; 
wire S,Cout; 
fa aa(.a(a), .b(b), .c(c), .S(S), .Cout(Cout)); 
initial begin 
    #0 a=0; b=0; c=0; 
    #20 a=0; b=0; c=1; 
    #30 a=0; b=1; c=0; 
    #40 a=0; b=1; c=1; 
    #50 a=1; b=0; c=0; 
    #60 a=1; b=0; c=1; 
    #70 a=1; b=1; c=0; 
    #80 a=1; b=1; c=1;
end
initial begin 
    $display("Full Subtractor (Structural) -- HEM -- 2020503007\n");
    $monitor("a=%b b=%b c=%b diff=%b carry=%b", a,b,c,S,Cout);
end 
endmodule

module ha(a,b,S,Cout); 
input a,b; 
output S, Cout; 
wire w1;
xor(S,a,b); 
not(w1,a);
and(Cout,w1,b);
endmodule

module fa(a,b,c,S,Cout); 
input a,b,c; 
output S, Cout; 
wire S1,C1,C2; 
ha h1(.a(a), .b(b), .S(S1), .Cout(C1)); 
ha h2(.a(S1), .b(c), .S(S), . Cout(C2)); 
or(Cout,C1,C2);
endmodule
