module demux1_4_test; 
wire O0,O1,O2,O3; 
reg in; 
reg [1:0] select; 
demux1_4 mux(.in(in),.select(select),.O0(O0),.O1(O1),.O2(O2),.O3(O3)); 
initial begin 
    #0 in=1; select=2'b00; 
    #10 select=2'b01; 
    #10 select=2'b10; 
    #10 select=2'b11;
    end 
    initial begin 
        $display("DeMUX 1:4 -- HEM -- Behavioral(c)-- 2020503007");
        $monitor("\nInput=%b, Select=%b, O[0]O[1]O[2]O[3] = %b%b%b%b",in, select,O0,O1,O2,O3); 
    end
endmodule 

module demux1_4(in,select,O0,O1,O2,O3); 
input in; 
input [1:0] select; 
output O0,O1,O2,O3; 
reg  O0,O1,O2,O3; 
always @(in or select) 
begin
case(select) 
2'b00:begin
O0=in;
O1=0;
O2=0;
O3=0;
end  
2'b01:begin
O0=0;
O1=in;
O2=0;
O3=0;
end  
2'b10:begin
O0=0;
O1=0;
O2=in;
O3=0;
end 
2'b11: begin
O0=0;
O1=0;
O2=0;
O3=in;
end 
default:$display("Invalid inputs");
endcase
end 
endmodule