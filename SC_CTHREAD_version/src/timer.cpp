/*****************************************************************************
[file name]--------------
timer.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-12-18
[last edit]---
2021-12-18 
*****************************************************************************/ 
#include "timer.h"

void timer::runtimer()
{
    // reset
    count = 0;
    // computation
    while(1)
    {
        if(start.read() )
        {
            cout << "Timer: timer start detected"
                 << endl;
            count = 5;
            timeout.write(0);
        }
        else
        {
            if(count == 0)
            {
                timeout.write(1);
            }
            else
            {
                count--;
                timeout.write(0);
            }
        }
        wait();
    }
}