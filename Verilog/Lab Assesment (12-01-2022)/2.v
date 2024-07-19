module bool_pos;
reg A,B,C,D;
wire out;
pos aa(.out(out),.a(A),.b(B),.c(C),.d(D));
initial begin
#0  A=0; B=0; C=0 ; D=0; 
#10 A=0; B=0; C=0;  D=1;
#10 A=0; B=0; C =1 ;D=0;
#10 A=0; B=0; C =1 ;D=1;
#10 A=0; B=1; C =0; D=0;
#10 A=0; B=1; C =0 ;D=1;
#10 A=0; B=1; C =1; D=0;
#10 A=0; B=1; C =1; D=1;
#10 A=1; B=0; C=0;  D=0; 
#10 A=1; B=0; C =0 ;D=1;
#10 A=1; B=0; C =1 ;D=0;
#10 A=1; B=0; C =1 ;D=1;
#10 A=1; B=1; C =0 ;D=0;
#10 A=1; B=1; C =0 ;D=1;
#10 A=1; B=1; C =1 ;D=0;
#10 A=1; B=1; C =1 ;D=1;
end
initial begin
    $display("Que 2 -- Behavioral Model -- D.K.Venkata Hem -- 2020503007");
    $monitor("\nA = %b B = %b C = %b D = %b\nD*(A' + B' + C) = %b\tTime = %3d",A,B,C,D,out,$time);
end
endmodule

module pos(out,a,b,c,d);
input a,b,c,d;
output out;
reg out;
always@(a,b,c,d)
begin
  out = d&((~a)|(~b)|c);
end
endmodule