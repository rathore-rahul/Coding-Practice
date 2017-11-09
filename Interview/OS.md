#### Operating System
* Collection of Library to allow application to use the underlying hardware.

#### One large programm Problmes
* Theoritically such OS is possible
* Update to one part means update to whole programm
* Truest Issue -- One part of programm may be malicious
* Maintainance Issue

#### File discriptor
Each table has a file discriptor table which is hidden from programm. when programm call open the os looks for not use entry in table and return the file descriptor location.
0 1 2 are reserved for STDIN, STDOUT, STDERR.
each descriptor points to where is resource and what is current offset.

#### Fork
return pid of child in parent and pid = 0 in child. so exec system call is done accordingly.
exitcode = wait(0) call in parent make parent to wait for a child to exit(exitcode) and collect it's return output. FD table will also get copied by using shared pointers. (File sharing).

#### sharing stdout and stderr
close(1); open(foo); close(2); dup(1);
dup will make stdout and stderr pointers to point to same same offset value.

#### Count unique elements in file
1. sort < file.txt > tmp1.   
uniq < tmp1 > tmp2 <br>
wc < tmp2 <br>
rm tmp1 tmp2

#### Pipe
int fdarray[2];
pipe(fdarray); <br>
take first two available file descriptor points them to input and output end of a pipe.This can be used for inter process Communication between parent and child, since they have the same copy of fd table. implemented using memory.

##### Process
A programm which is running. The address space of process is private.

#### Signals
Used for event driven programm. It amounts to an Asynchronous function call. When a process is signalled by Os the signal handler execute in address space of process can touch process data.Every process will have its own signal handler.
> signal(int signum, void (* handler)(int signum)). <br>
> Kill(int pid, int signum) sending the signal to another process

Some unix signal. <br>
* SIGINT - interrupt signal ctrr+c
* SIGSTOP - stop process ctrl+z
* SIGSEGV - Sementation fault
* SIGFPE - Floating Point Exception
* SIGCHILD - generate when a child exit
* SIGKILL - killing a programm


#### Zombie Process
Suppose a process P1 spawn a new process P2 and P2 exits.but P1 hasn't called wait yet thus Operating system may preserve some data like return code so that when parent call wait it cout be return.

#### /proc Pseudo File system
Subdirectory are the process ids. Contains information about process which the OS wants to expose to its applications. Like what is the current working directory of the process, memory mapping for process. change number of active CPUs.
This way filesystem abstraction to get and set values in os.


#### Copy on Demand


#### Inter Process Communication
1. exitcode (parent-child)
2. PIPE
3. signal (make system calls which are costly)
4. Sharing address space



#### Paging
* Advantages
> Less internal fragmentation
> Less unused programm in memory

* Disadvantages
> Programm need many pages larger page table

#### Difference bewteen Cache and TLB
Cache is kind of faster memory to speed up performance, so that next access to same information is faster.
TLB is used to convert virtual page address into physical page address by caching the page table


#### Difference between Thread and process
Thread is a execution flow. A process is a thread + private address space as oppose to two threads within a process using same address space.
* User Threads - application simulates threads. Os has no idea. if one thread call exit whole application exit. if one thread block on a disk access whole process block because cpu has no idea.
* Kernel Level Thread - OS knows about the threads. One thread gets block on network while other can run.

#### PREEMPTION
OS will had a timer and when a timer is generated cpu can take necessary actions like scheduling, context switch.

#### MMU
sits between the memory cpu want to access and actual physical memory address. Translate the address.

#### Some important register
* SP - stack pointer
* BP - base pointer
* PC - programm counter or instruction pointer
* CS - code segment
* DS - Data segment
* SS - stack segment
* ES -
* GS -


#### Polling vs interrupt
Polling is loop to keep checking for some condition.

#### Segmentation in 32 bit
Way to implement process private address space.
virtual address -> MMU -> physical address
virtual address (segment selector(CS,DS), offset);
top 13 bits of selector register is used to index into Global descriptor table (GDT) which Contains base and limit values. <br>
physical address = base + offset (if its less than limit else Segmentation fault) not need to worry where is the process is put in runtime. it can assume it is place at index 0. <br>
GDTR - points to base GDT in memory. process should not be able to set value in GDTR.
* privilige mode (God mode) - lgdt which is used to load gdt can be run in only in god mode. modifies gdt at time of context switch so process can not take others address space.
* Unprivileged mode (peasant mode)-
Mode is set in last 2 bits of cs register. ljmp instruction is used to set CS register. no process can jump from low privilige to high privilige mode. GDT is lived in OS memory so no process can modify the GDT table.


#### Big Endian and Little Endian
Big Endian -> most significant byte at small address
Little Endian -> least significant byte at small address

#### Static Library vs Shared Library
Library are just like EXEs but they are not directly executable.
* Static Library -- Used at compile time. Compiler copies the code from the static lib into our app and build the app. Once used no need to keep it. application size will increase.
* Dynamic Link Library or Shared Library -- Used at run time. Functions or resource refered are loaded. DLL can be changed and application will perform accordingly without even building app again. DLL are required every time the application refer the lib. application size is small.

#### Difference Between Semaphore and mutex
#### Why is cache needed? What happens when we watch the video? Who allocates memory to process?
CPU cache is static ram. No need to constantly refresh to hold data.DRAM(use capacitors) need to refresh to compensate the leakage of charge from the capacitors.
