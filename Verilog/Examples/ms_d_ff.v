module D_latch_test;
    wire Q1,Q1n,Q2,Q2n;
    reg D,clk;
    D_latch aa(.q(Q),.qn(Qn),.d(D),.q1(Q2),.qn1(Q2n),.clk(clk)) ;
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
    $display("HEM -- 202053007 -- D Latch -- Structural");
    $monitor ( "\nClock = %b D = %b Q = %b Q' = %b time = %2d" , clk,D,Q2,Q2n,$time) ;
    end
endmodule

module D_latch ( q , qn , d ,q1,qn1, clk ) ;
    output q,qn,q1,qn1;
    input d,clk;
    wire r,s,w,s1,r1,clk1;
    not o1(w,d);
    not o2(clk1,clk);
    and a1(r,w,clk);
    and a2(s,d,clk);
    nor n1 (q,s,qn);
    nor n2 (qn,r,q);
    and a3(r1,q,clk1);
    and a4(s1,qn,clk1);
    nor n3 (q1,r1,qn1);
    nor n4 (qn1,s1,q1);
endmodule
