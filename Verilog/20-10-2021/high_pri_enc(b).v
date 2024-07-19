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
    $display("Priority Encoder(I3 - high) (Behavioral)\nHem -- 2020503007");
    $monitor("In = %b, Out = %b, Enable = %b",i,o,enable);
    end
endmodule

module priority_enc4(o,i,enable);
    input [3:0] i;
    input enable;
    output [1:0] o;
    reg [1:0] o;
    always @(i or enable) 
    begin
        o[1] = ~i[3] & ~i[2];
        o[0] = ~i[3] & (i[2] | ~i[1]);
    end
endmodule
