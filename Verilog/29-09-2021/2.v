
module lift_test;
reg a,b,c,d;
wire out;
lift oo(.out(out),.a(a),.b(b),.c(c),.d(d));
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
  $display("Que_2_SOP_(Behavioural) -- HEM -- 2020503007\n");
  $display("Expression: M'F2 + M'F3 + M'F1");
  $monitor("\nM=%b F1=%b F2=%b F3=%b (%b %b %b %b)\nOpen = %b\ttime = %3d",a,b,c,d,a,b,c,d,out,$time);
end
endmodule

module lift(out,a,b,c,d);
input a,b,c,d;
output out;
reg out;
always@(a,b,c,d)
begin
  out = ((!a)*b)+((!a)*c)+((!a)*d);
end
endmodule