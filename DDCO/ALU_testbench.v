module tb;
reg t_a;//flip flop or latch element for memory
reg t_b;
reg t_c;
wire P;

//instantiate
samplecircuit s1(.a(t_a),.b(t_b),.c(t_c),.y(P));
initial begin $dumpfile("dump3.vcd");
$dumpvars(0,tb);
end

initial begin $monitor(t_a,t_b,t_c,P);
t_a=1'b0;
t_b=1'b0;
t_c=1'b0;
#10
t_a=1'b0;
t_b=1'b0;
t_c=1'b1;
#10
t_a=1'b0;
t_b=1'b1;
t_c=1'b0;
#10
t_a=1'b0;
t_b=1'b1;
t_c=1'b1;
#10
t_a=1'b1;
t_b=1'b0;
t_c=1'b0;
#10
t_a=1'b1;
t_b=1'b0;
t_c=1'b1;
#10
t_a=1'b1;
t_b=1'b1;
t_c=1'b0;
#10
t_a=1'b1;
t_b=1'b1;
t_c=1'b1;
#10;

end
endmodule