module master_slave_dff;
reg D, clk;
wire Q1, Q1n,Q2n,Q2;
 ms_dff aa(.d(D),.clk(clk),.q(Q1),.qn(Q1n));
 ms_dff bb(.d(Q1),.clk(~clk),.q(Q2),.qn(Q2n));
 initial begin
 #0 clk = 1 ; D = 0 ;
    #5 clk = 0 ; D = 1 ;
    #5 clk = 1 ; D = 1 ; 
    #5 clk = 0 ; D = 0 ; 
    #5 clk = 1 ; D = 0 ; 
    #5 clk = 0 ; D = 0 ;
    #5 clk = 1 ; D = 1 ;
 end
 initial begin 
 $display("Que 4 -- D.K.Venkata Hem -- 2020503007");
 $display("Master Slave D Flip Flop using structural model");
 $monitor("Clk = %b  D = %b  Q = %b  Q' = %b",clk,D,Q2,Q2n);
 end
endmodule
module ms_dff(d,clk,q,qn);
input d, clk;
output q, qn;
wire w1,w2,w3;
 not n1(w1,d); 
 and b1(w2,clk,w1);
 and b2(w3,clk,d); 
 nor c1(q,w2,qn);
 nor c2(qn,w3,q); 
endmodule