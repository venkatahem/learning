module mux8_test;
wire out;
reg i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2;
mux8 aa(.i0(i0),.i1(i1),.i2(i2),.i3(i3),.i4(i4),.i5(i5),.i6(i6),.i7(i7),.s0(s0),.s1(s1),.s2(s2),.out(out));
initial begin
  #0 i0=1; i1=0; i2=0; i3=1; i4=1; i5=0; i6=1; i7=1; s0=0; s1=0; s2=0;
  #10 s0=0; s1=0; s2=1;
  #10 s0=0; s1=1; s2=0;
  #10 s0=0; s1=1; s2=1;
  #10 s0=1; s1=0; s2=0;
  #10 s0=1; s1=0; s2=1;
  #10 s0=1; s1=1; s2=0;
  #10 s0=1; s1=1; s2=1;
end
initial begin
  $display("8:1 MUX (Behavioural) -- HEM -- 2020503007");
  $monitor("\nIn = %b%b%b%b%b%b%b%b S0 = %b, S1 = %b, S2 = %b, out = %b",i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,out);
end
endmodule

module mux8(i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2,out);
input  i0,i1,i2,i3,i4,i5,i6,i7,s0,s1,s2;
output out;
reg out;
always@(s0 or s1 or s2)
begin
  case({s0,s1,s2})
  3'b000:out=i0;
  3'b001:out=i1;
  3'b010:out=i2;
  3'b011:out=i3;
  3'b100:out=i4;
  3'b101:out=i5;
  3'b110:out=i6;
  3'b111:out=i7;
  default:$display("Invalid");
  endcase
end
endmodule