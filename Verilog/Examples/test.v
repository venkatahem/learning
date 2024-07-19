module sample_test;
reg A,B,C,D;
wire div;

divisible aa(.div(div),.A(A),.B(B),.C(C),.D(D));
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
$display("Behavior_Model");
$display("DIVISIBLE BY 3 OR 4(QN3-SOP)-AADHITH UJESH(2020503001)\n\n");
$display("POS for DIVISIBILITY BY 3 OR 4 is (A+B+C).(B'+C+D').(A'+B+C').(A'+C'+D).(A+B+D).(A'+B+C')\n");
$monitor("\n %b%b%b%b\n DIVISIBILITY = %b \ttime=%d\n\n",A,B,C,D,div,$time);
end
endmodule

module divisible(div,A,B,C,D);
output div;
input A,B,C,D;
reg div;
always@(A,B,C,D)
begin
div = (A|B|C) & ((~B)|C|(~D)) & ((~A)|B|(~C)) & ((~A)|(~C)|D) & (A|B|D) & ((~A)|B|(~C));
end
endmodule