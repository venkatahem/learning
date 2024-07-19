module SR_NOR_test;
    wire Q,Qn;
    reg R,S,clk;
    SR_NOR aa(.q(Q),.qn(Qn),.r(R),.s(S),.clk(clk));
    initial begin
    #0 clk = 1 ; S = 1 ; R = 0 ; 
    #5 clk = 0 ; S = 0 ; R = 1 ; 
    #5 clk = 1 ; S = 0 ; R = 1 ; 
    #5 clk = 0 ; S = 1 ; R = 0 ; 
    #5 clk = 1 ; S = 0 ; R = 0 ; 
    #5 clk = 0 ; S = 1 ; R = 0 ; 
    #5 clk = 1 ; S = 1 ; R = 1 ; 
    end
    
    initial begin
    $display("HEM -- 202053007 -- SR Latch NOR-- Structural");
    $monitor ( "\nClock = %b, S = %b, R = %b, Q = %b, Q' = %b, time = %2d",clk,S,R,Q,Qn,$time);
    end
endmodule

module SR_NOR (q,qn,r,s,clk);
    output q,qn;
    input r,s,clk;
    wire r1,s1;
    and a1(r1,r,clk);
    and a2(s1,s,clk);
    nor n1 (q,r1,qn);
    nor n2 (qn,s1,q);
endmodule
