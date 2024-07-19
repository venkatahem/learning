module D_latch_test;
    wire Q,Qn;
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
    $display("HEM -- 202053007 -- D Latch -- Behavioral");
    $monitor ( "\nClock = %b D = %b Q = %b Q' = %b time = %2d" , clk,D,Q,Qn,$time) ;
    end
endmodule

module D_latch ( q , qn , d , clk ) ;
    output q , qn ;
    input d , clk ;
    reg q , qn ;
    always@ ( clk or d ) 
    begin
        if ( clk ) 
        begin
            if ( d == 1 ) 
            begin
                q <= 1 ;
                qn <= 0 ;
            end
            else if ( d == 0 ) 
            begin
                q <= 0 ;
                qn <= 1 ;
            end
        end
    end
endmodule
