module D_latch_test;
    wire Q1,Q1n,Q2,Q2n;
    reg D,clk;
    D_latch aa(.q(Q),.qn(Qn),.d(D),.clk(clk)) ;
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
    $monitor ( "\nClock = %b D = %b Q = %b Q' = %b time = %2d" , clk,D,Q,Qn,$time) ;
    end
endmodule

module D_latch ( q , qn , d , clk ) ;
    output q,qn;
    input d,clk;
    wire r,s,w;
    not (w,d);
    and a1(r,w,clk);
    and a2(s,d,clk);
    nor n1 (q,r,qn);
    nor n2 (qn,s,q);
endmodule
