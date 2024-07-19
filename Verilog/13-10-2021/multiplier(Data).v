module test;
  reg [3:0] a;
  reg [2:0] b;
  wire [6:0] res;
  product m1(.a(a),.b(b),.res(res));
  initial begin
    #0 a=4'b0001; b=3'b001;
    #10 a=4'b0100; b=3'b010;
    #10 a=4'b0101; b=3'b011;
    #10 a=4'b0010; b=3'b111;
  end

  initial begin
    $display("Multiplier -- HEM -- Data Flow -- 2020503007");
    $monitor("\na=%b b=%b res=%b",a,b,res);
  end
endmodule

module product(a,b,res);
  input [3:0] a;
  input [2:0] b;
  output [6:0] res;
  wire [4:0] r1;
  wire [3:0] r2,r3;
  wire [4:0] i1;
   
  assign r1[0]=a[0]&b[0];
  assign r1[1]=a[1]&b[0];
  assign r1[2]=a[2]&b[0];
  assign r1[3]=a[3]&b[0];

  assign r2[0]=a[0]&b[1];
  assign r2[1]=a[1]&b[1];
  assign r2[2]=a[2]&b[1];
  assign r2[3]=a[3]&b[1];

  assign r3[0]=a[0]&b[2];
  assign r3[1]=a[1]&b[2];
  assign r3[2]=a[2]&b[2];
  assign r3[3]=a[3]&b[2];
  
  assign r1[4]=1'b0;
  
  assign res[0]=r1[0];
  fa a1(.a(r1[4:1]),.b(r2),.c(i1[3:0]),.Cout(i1[4]));
  assign res[1]=i1[0];
  fa a2(.a(i1[4:1]),.b(r3),.c(res[5:2]),.Cout(res[6]));
endmodule



module fa(a,b,c,Cout); 
input [3:0] a,b; 
output [3:0] c;
output Cout; 
wire[11:0] w;

ha a1(.a(a[0]),.b(b[0]),.c(c[0]),.out(w[0]));

assign c[0]=a[0]^b[0];
assign w[0]=a[0]&b[0];

// ha a2(.a(a[1]),.b(w[0]),.c(w[1]),.out(w[2]));
// ha a3(.a(w[1]),.b(b[1]),.c(c[1]),.out(w[3]));
// assign w[4] = w[2]|w[3];

assign w[1]=a[1]^w[0];
assign w[2]=a[1]&w[0];
assign c[1]=w[1]^b[1];
assign w[3]=w[1]&b[1];
assign w[4]=w[2]|w[3];

// ha a4(.a(a[2]),.b(w[4]),.c(w[5]),.out(w[6]));
// ha a5(.a(w[5]),.b(b[2]),.c(c[2]),.out(w[7]));
// assign w[8] = w[6]|w[7];

assign w[5]=a[2]^w[4];
assign w[6]=a[2]&w[4];
assign c[2]=w[5]^b[2];
assign w[7]=w[5]&b[2];
assign w[8]=w[6]|w[7];

// ha a6(.a(a[3]),.b(w[8]),.c(w[9]),.out(w[10]));
// ha a7(.a(w[9]),.b(b[1]),.c(c[3]),.out(w[11]));
// assign Cout=w[10]|w[11];

assign w[9]=a[3]^w[8];
assign w[10]=a[3]&w[8];
assign c[3]=w[9]^b[3];
assign w[11]=w[9]&b[3];
assign Cout=w[10]|w[11];

endmodule

module ha(a,b,c,out);
input a,b;
output c,out;

assign c = a^b;
assign out = a&b;

endmodule