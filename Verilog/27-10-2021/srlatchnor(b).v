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
    $display("HEM -- 202053007 -- SR Latch NOR-- Behavioral");
    $monitor ( "\nClock = %b, S = %b, R = %b, Q = %b, Q' = %b, time = %2d",clk,S,R,Q,Qn,$time);
    end
endmodule

module SR_NOR ( q , qn , r , s , clk ) ;
    output q , qn ;
    input r , s , clk ;
    reg q , qn ;
    always@ ( clk or r or s ) 
    begin
        if ( clk ) 
        begin
            if ( s == 0 && r == 0 ) 
            begin
                q <= q ;
                qn <= ~ q ;
            end
            else if ( s == 0 && r == 1 ) 
            begin
                q <= 0 ;
                qn <= 1 ;
            end
            else if ( s == 1 && r == 0 ) 
            begin
                q <= 1 ;
                qn <= 0 ;
            end
            else if ( s == 1 && r == 1 ) 
            begin
                q <= 0 ;
                qn <= 0 ;
            end
        end
    end
endmodule
