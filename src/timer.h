/*****************************************************************************
[file name]--------------
timer.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-12-06 
[last edit]---
2021-12-06 
*****************************************************************************/ 
#ifndef TIMER_H
#define TIMER_H

#include "systemc.h"

SC_MODULE(timer)
{
    // port definition
    sc_in <bool> clock;
    sc_in <bool> start; 
    sc_out<bool> timeout;
    
    
    // data and function members
    int count;
    void runtimer();
    
    // constructor
    SC_CTOR(timer)
    {
        SC_THREAD(runtimer);
        // sensitivity list
        sensitive << clock.pos()
                  << start;
        count = 0;
    }
};

#endif