# Simple_Timer_in_SystemC - vincent08tw
###### tags: `SystemC`

## Project Description
Use SystemC to model and test the timer module.

* Environment
	* SystemC 2.3.3
	* Ubuntu 18.04

* Specification  
```
sc_main
1. Create a test suite, i.e. sc_main, for the timer module, that
	i. Instantiate a timer module
	ii. Provide a 100MHz clock to the timer module
	iii. Create a trace file named RESULT.vcd. And trace ports/variable in following order:
		clock
		start
		timeout
		count
2. Feed in a start signal to create a trace which contains a waveform of exactly 30 cycles (300ns, that is.) This 30-cycle waveform should include following scenarios:
	reset the timer for 3 cycles before it is released for counting, during counting reset the timer before count reaches 0, and during counting reset the timer after count reaches 0
```

## Project directory hierachy
```
Simple_Timer_in_SystemC/
    +-- SC_THREAD_version/
    |   +-- src/
    |   |    +-- main.cpp
    |   |    +-- makefile
    |   |    +-- timer.cpp
    |   |    +-- timer.h
    |   README.md
    +-- SC_CTHREAD_version/
    |   +-- src/
    |   |    +-- main.cpp
    |   |    +-- makefile
    |   |    +-- timer.cpp
    |   |    +-- timer.h
    |   README.md
    |
```























