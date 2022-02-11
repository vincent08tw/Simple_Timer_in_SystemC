/*****************************************************************************
[file name]--------------
timer.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-12-06 
[last edit]---
2021-12-06 
*****************************************************************************/ 
#include "timer.h"

void timer::runtimer()
{
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