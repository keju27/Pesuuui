module adder(input wire a,b,c,output wire sum,carry);
wire [4:0]t;
xor1 a1(a,b,t[0]);
xor1 a3(t[0],c,sum);
and1 a2(a,b,t[1]);
and1 a4(b,c,t[2]);
and1 a5(a,c,t[3]);
or1 y1(t[1],t[2],t[4]);
or1 y2(t[4],t[3],carry);
endmodule
module mux_2_1(input wire d0,d1,s,output wire y);
and1 x1(~s,d0,o1);
and1 x2(s,d1,o2);
or1 x3(o1,o2,y);
endmodule
module add_sub(input wire a,b,c,m,output wire sum,carry);
wire d;
xor1 q1(b,m,d);
adder q2(a,d,c,sum,carry);
endmodule
module alu2(input wire i0,i1,cin,input wire [1:0]op,output wire o,cout);
wire [3:0]t;
add_sub x8(i0,i1,cin,op[0],t[0],cout);
and1 x3(i0,i1,t[1]);
or1 x4(i0,i1,t[2]);
mux_2_1 x5(t[1],t[2],op[0],t[3]);
mux_2_1 x6(t[0],t[3],op[1],o);
endmodule
module alu(input wire [1:0]op,input wire [15:0]i0,i1,output wire [15:0]o,output wire cout);
wire [14:0]c;
alu2 t1(i0[0],i1[0],op[0],op,o[0],c[0]);
alu2 t2(i0[1],i1[1],c[0],op,o[1],c[1]);
alu2 t3(i0[2],i1[2],c[1],op,o[2],c[2]);
alu2 t4(i0[3],i1[3],c[2],op,o[3],c[3]);
alu2 t5(i0[4],i1[4],c[3],op,o[4],c[4]);
alu2 t6(i0[5],i1[5],c[4],op,o[5],c[5]);
alu2 t7(i0[6],i1[6],c[5],op,o[6],c[6]);
alu2 t8(i0[7],i1[7],c[6],op,o[7],c[7]);
alu2 t9(i0[8],i1[8],c[7],op,o[8],c[8]);
alu2 t10(i0[9],i1[9],c[8],op,o[9],c[9]);
alu2 t11(i0[10],i1[10],c[9],op,o[10],c[10]);
alu2 t12(i0[11],i1[11],c[10],op,o[11],c[11]);
alu2 t13(i0[12],i1[12],c[11],op,o[12],c[12]);
alu2 t14(i0[13],i1[13],c[12],op,o[13],c[13]);
alu2 t15(i0[14],i1[14],c[13],op,o[14],c[14]);
alu2 t16(i0[15],i1[15],c[14],op,o[15],cout);
endmodule
