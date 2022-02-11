/*****************************************************************************
[file name]--------------
main.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-12-18
[last edit]---
2021-12-18 
*****************************************************************************/ 
#include "timer.h"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> start;
    sc_signal<bool> timeout;
    
    sc_time clkPrd(10, SC_NS); // 100MHz
    sc_time clkDly( 0, SC_NS);
    // sc_clock(name, period, duty_cycle, start_time, pos_edge_first)
    sc_clock clock("clock", clkPrd);
    
    // timer instantiation
    timer tm1("timer");
    tm1.clock(clock);
    tm1.start(start);
    tm1.timeout(timeout);
    
    
    // tracing:
    // trace file creation, with VCD type output
    sc_trace_file *tf = sc_create_vcd_trace_file("simplex");
    // External signals
    sc_trace(tf, clock, "clock" );
    sc_trace(tf, start, "start");
    sc_trace(tf, timeout, "timeout");
    sc_trace(tf, tm1.count, "count");
    
    //reset the timer for 3 cycles before it is released for counting
    sc_start(0, SC_NS);
    start.write(1);
    sc_start(3*clkPrd); // for 3 cycle
    start.write(0);
    // during counting reset the timer before count reaches 0
    sc_start(3*clkPrd); // for 3 cycle
    start.write(1);
    sc_start(3*clkPrd); // for 3 cycle
    start.write(0);
    // during counting reset the timer after count reaches 0
    sc_start(10*clkPrd); // for 3 cycle
    start.write(1);
    
    sc_start(11*clkPrd); // for 3 cycle
    
    sc_close_vcd_trace_file(tf);
    /*
    // simulate for 30ns
    // default is ps
    sc_start(30000);
    */
    return (0);
    
}