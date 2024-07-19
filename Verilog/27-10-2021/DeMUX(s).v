module demux1_4_test;
reg in,s0,s1;
wire [3:0] out;
demux1_4 aa(.in(in),.s0(s0),.s1(s1),.out(out));
initial begin
  #0 in=1; s0=0; s1=0;
  #10 s0=0; s1=1;
  #10 s0=1; s1=0;
  #10 s0=1; s1=1;
end
initial begin
$display("DeMUX 1:4 -- HEM -- Structural-- 2020503007");
    $monitor("\nIn = %b, S0 = %b, S1 = %b, O[0]O[1]O[2]O[3] = %b",in,s0,s1,out);
end
endmodule

module demux1_4(in,s0,s1,out);
input in,s1,s0;
output [0:3] out;
wire w1,w2;
not n1(w1,s0);
not n2(w2,s1);
and a1(out[0],w1,w2,in);
and a2(out[1],w1,s1,in);
and a3(out[2],s0,w2,in);
and a4(out[3],s0,s1,in);
endmodule