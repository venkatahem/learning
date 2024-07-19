
module ctlab_test;
reg a,b,c,d;
wire out1,out2;
ctlab oo(.out1(out1),.out2(out2),.a(a),.b(b),.c(c),.d(d));
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
  $display("Que_1_SOP_(Structural) -- HEM -- 2020503007\n");
  $display("Expression -> CT1: C0'.C1.K0.K1' | CT2: C0.C1'.K0.K1");
  $monitor("\n%b %b %b %b\nCT1 = %b | CT2 = %b\ttime = %3d",a,b,c,d,out1,out2,$time);
end
endmodule

module ctlab(out1,out2,a,b,c,d);
input a,b,c,d;
output out1,out2;
wire w1,w2,w3,w4,w5,w6,w7;
not n1(w1,a);
not n2(w2,d);
not n3(w3,b);
and a1(w4,w1,b);
and a2(w5,c,w2);
and a3(out1,w4,w5);
and a4(w6,a,w3);
and a5(w7,c,d);
and a7(out2,w6,w7);
endmodule