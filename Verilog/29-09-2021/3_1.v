module divisible_test;
reg a,b,c,d;
wire div;

divisible aa(.div(div),.a(a),.b(b),.c(c),.d(d));
initial begin
#0 a=0; b=0; c=0; d=0; //0
#10 a=0; b=0; c=0; d=1; //1
#10 a=0; b=0; c=1; d=0; //2
#10 a=0; b=0; c=1; d=1; //3
#10 a=0; b=1; c=0; d=0; //4
#10 a=0; b=1; c=0; d=1; //5
#10 a=0; b=1; c=1; d=0; //6
#10 a=0; b=1; c=1; d=1; //7
#10 a=1; b=0; c=0; d=0; //8
#10 a=1; b=0; c=0; d=1; //9
#10 a=1; b=0; c=1; d=0; //10
#10 a=1; b=0; c=1; d=1; //11
#10 a=1; b=1; c=0; d=0; //12
#10 a=1; b=1; c=0; d=1; //13
#10 a=1; b=1; c=1; d=0; //14
#10 a=1; b=1; c=1; d=1; //15
end

initial begin
$display("Que_3_POS_(Behavioural) -- HEM -- 2020503007");
$display("Expression: (A+B+C).(A+B'+D').(B'+C+D').(A'+C'+D).(A'+B+C').(B+C'+D)");
$monitor("\n%b%b%b%b\n DIVISIBILITY(3 or 4) = %b \ttime=%3d",a,b,c,d,div,$time);
end
endmodule

module divisible(div,a,b,c,d);
output div;
input a,b,c,d;
reg div;
always@(a,b,c,d)
begin
 div = (a|b|c) & (a|(~b)|(~d)) & ((~b)|c|(~d)) & ((~a)|(~c)|d) & ((~a)|b|(~c)) & (b|(~c)|d);
end
endmodule