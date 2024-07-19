module ha_test;
reg a,b;
wire s,o;
ha oo(.a(a),.b(b),.s(s),.o(o));
initial begin
  #0 a=0; b=0;
  #10 a=0; b=1;
  #10 a=1; b=0;
  #10 a=1; b=1;
end
initial begin
$display("Half Adder (Structural) -- HEM -- 2020503007\n");
    $monitor("a = %b b = %b sum = %b carry = %b",a,b,s,o);
end
endmodule

module ha(a,b,s,o);
input a,b;
output s,o;
xor (s,a,b);
and (o,a,b);
endmodule