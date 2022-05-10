# Operating-System-CPU_scheduling


The Operating system schedules the processes on the CPU to have the maximum utilization of it and this procedure is called CPU scheduling.
There is a body of software, in fact, that is responsible for making it easy to run programs (even allowing you to seemingly run many at the same time), 
allowing programs to share memory, enabling programs to interact with devices, and other fun stuff like that. That body of software is called the operating system (OS).


CONCEPT OF VIRTUALIZATION....

The primary way the OS does this is through a general technique that we call "virtualization". 
That is, The OS takes a physical resource (such as the processor, or memory) and transforms it into a more general, powerful, and easy-to-use virtual form of itself. 
Thus, we sometimes refer to the operating system as a virtual machine


CPU SCHEDULING...

A typical process involves both Input/Output time(I/O) and CPU time. In a uni-programming system like MS-DOS, time spent waiting for I/O is wasted and CPU is free during this time. In multi programming systems, one process can use CPU while another is waiting for I/O. This is possible only with process scheduling or CPU scheduling.


Objectives of Process Scheduling Algorithm...

    Max CPU utilization.
    Fair allocation of CPU.
    Max throughput.
    Min turnaround time.
    Min response time.
    Min waiting time.

Different Scheduling Algorithms....

     * First-Come-First-Serve (FCFS)
     * Shortest Job First (SJF)
     * Round-Robin Scheduling.
     * Priority Queuing.
     * Multilevel Queue Scheduling.
     * Multi level Feedback Queue (MLFQ).
