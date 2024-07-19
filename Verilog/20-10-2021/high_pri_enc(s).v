module priority_enc4_test;
    wire [1:0] o;
    reg [3:0] i;
    reg enable = 1;
    priority_enc4 aa(.o(o), .i(i), .enable(enable));
    initial begin
        #0 i=4'b0001;
        #10 i=4'b0010;
        #20 i=4'b0100;
        #30 i=4'b1000;
    end
    initial begin
    $display("Priority Encoder(I3 - high) (Structural)\nHem -- 2020503007");
    $monitor("In = %b, Out = %b, Enable = %b",i,o,enable);
    end
endmodule

module priority_enc4(o,i,enable);
    input [3:0] i;
    input enable;
    output [1:0] o;
    wire w1,w2,w3,w4,w5,w6;
    not n1(w1,i[0]);
    not n2(w2,i[1]);
    not n3(w3,i[2]);
    not n4(w4,i[3]);
    and (o[1], w3, w4, enable);
    or( w5, i[2], w2);
    and(o[0], w4, w5, enable);
endmodule
