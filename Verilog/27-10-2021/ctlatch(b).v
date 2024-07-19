module CT_latch_test;
    wire Q , Qn;
    reg C , T , clk;

    CT_latch aa(.q(Q),.qn(Qn),.c(C),.t(T),.clk(clk));
    initial begin
    #0 clk = 1 ; C = 0 ; T = 1;
    #5 clk = 0 ; C = 1 ; T = 1;
    #5 clk = 1 ; C = 1 ; T = 0;
    #5 clk = 0 ; C = 1 ; T = 1;
    #5 clk = 1 ; C = 0 ; T = 0;
    #5 clk = 0 ; C = 0 ; T = 1;
    #5 clk = 1 ; C = 1 ; T = 1;
    #5 clk = 0 ; C = 0 ; T = 0;
    #5 clk = 1 ; C = 1 ; T = 0;
    end
    
    initial begin
    $display("HEM -- 202053007 -- CT Latch -- Behavioral");
    $monitor ( "\nClock = %b, C = %b, T = %b, Q = %b, Q' = %b, time = %2d",clk,C,T,Q,Qn,$time);
    end
endmodule

module CT_latch (q,qn,c,t,clk);
    output q , qn;
    input c , t , clk;
    reg q , qn;
    always@ ( clk or c or t ) 
    begin
        if ( clk )
         begin
            if ( c == 0 && t == 0 )
            begin
                q <= ~ q;
                qn <= q;
            end
            else if ( c == 0 && t == 1 ) 
            begin
                q <= 0;
                qn <= 1;
            end
            else if ( c == 1 && t == 0 ) 
            begin
                q <= 1;
                qn <= 0;
            end
            else if ( c == 1 && t == 1 ) 
            begin
                q <= q;
                qn <= ~ q;
            end
        end
    end
endmodule
