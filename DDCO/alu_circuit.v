module samplecircuit(input wire a,b,c,output wire y);
    wire t0,t1;
    and2 a1(a,b,t0);
    invert a2(c,t1);
    or a3(t0,t1,y);
endmodule