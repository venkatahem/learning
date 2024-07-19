module hi_test();
reg a;
wire b;
hi oo(.a(a),.b(b));
initial begin
    #0 a=1;
    #10 a=0;
end
initial begin
  $monitor("A = %b\tB = %b\tHI",a,b);
end
endmodule

module hi(a,b);
input a;
output b;
assign b = ~a;
endmodule