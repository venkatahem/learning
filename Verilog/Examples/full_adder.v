module fa_test; 
reg a,b,c; 
wire sum1,cout; 
full_adder aa(.a(a), .b(b), .c(c),.carry(cout),.sum(sum1)); 
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
    $display("Full Adder (Behavioural) -- HEM -- 2020503007\n");
    $monitor("a=%b b=%b c=%b sum=%b cout=%b time = %3d",a,b,c,sum1,cout,$time);
end 
endmodule 

module full_adder(a,b,c,carry,sum);
input a,b,c;
output carry,sum;
wire w1,w2,w3;
half_adder h1(.a(a),.b(b),.c1(w1),.s(w2));
half_adder h2(.a(w2),.b(c),.c1(w2),.s(sum));
assign carry = w1|w2;
endmodule

module half_adder(a,b,c1,s);
input a,b;
output c1,s;
assign s = a^b;
assign c1 = a&b;
endmodule