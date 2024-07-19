 module q_1_test; 
reg a,b,c; 
wire x,y; 
q_1 aa(.x(x),.y(y),.a(a),.b(b),.c(c)); 
initial begin 
    #0 a=0; b=0; c=0; 
    #10 a=1; b=0; c=0; 
    #10 a=0; b=1; c=0; 
    #10 a=0; b=0; c=1; 
    #10 a=1; b=1; c=0; 
    #10 a=1; b=0; c=1; 
    #10 a=0; b=1; c=1; 
    #10 a=1; b=1; c=1; 
    end 
    initial begin 
        $display("Que_1(Behavioural) -- HEM -- 2020503007\n");
$monitor("\na = %b, b = %b, c = %b\n(A * C')+(A + B')'+(C*(C * A')') = %b\nA + B = %b \t time = %2d",a,b,c,x,y,$time); 
end 
endmodule

module q_1(x,y,a,b,c); 
input a,b,c; 
output x,y; 
reg x,y; 
always@(a,b,c)
begin 
x = (a&(~c))|(a~|(~b))|(c&(c~&(~a))); 
y = a|b; 
end 
endmodule