module Decoder; 
wire [7:0] D; 
reg [2:0] a; 
reg enable; 
    decoder3to8 De(.a(a),.enable(enable),.D(D)); 
        initial begin 
        #0 enable=1;  
        #0  a=3'b000;  
        #10 a=3'b001;  
        #10 a=3'b010; 
        #10 a=3'b011; 
        #10 a=3'b100; 
        #10 a=3'b101; 
        #10 a=3'b110; 
        #10 a=3'b111; 
        end 
        initial begin
          $display("3:8 Decoder (Behavioral) -- HEM -- 2020503007");
          $monitor("Enable=%b select=%b D0=%b D1=%b D2=%b D3=%b D4=%b D5=%b D6=%b D7=%b",enable ,a ,D[0],D[1],D[2],D[3],D[4],D[5],D[6],D[7]); 
        end 
endmodule 

module decoder3to8(a,enable,D); 
input [2:0] a;  
input enable; 
integer i; 
output [7:0] D; 
reg [7:0] D; 
always@(a or enable) 
begin 
if(enable==1) 
begin 
  for(i=0; i<8; i=i+1) 
  begin 
    if(a==i) 
      D[i]=1; 
    else 
      D[i]=0; 
   end 
end    
else 
 D=00000000; 
end  
endmodule 