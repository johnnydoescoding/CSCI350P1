# CSCI 350 Project 1 Design Document & FRQ

## Modified Files

* `.gitignore`
created this file to avoid committing files that i dont want to commit like `.DS_Store` and `gdbinit.tmpl`

* `README.md`
modified this file to record important student and setup information as required by the assignment.


* `xv6-public-master/Makefile`
modified this file to add `_test_project1\` and `_date\` under `UPROGS=\` to tell xv6 to build these files so we can run it later in the xv6 shell. 

* `xv6-public-master/proc.h`
modified this file to add member variables `int tracing` and `int tracing_cnt` to the proc data structure in order to record whether a process is currently being traced and the total number of traced system calls in each process. 

* `xv6-public-master/proc.c`
modified this file to add the following lines of code `p->tracing=0` and `p->tracing_cnt=0` inside the `allocproc(void)` function to initialize these tracing variables when a process is first creaetd.

* `xv6-public-master/syscall.h`
modified this file to add the following macros `#define SYS_trace 22` and `#define SYS_date 23` in order to be used in `syscall.c`.


* `xv6-public-master/syscall.c`
- modified this file to add external declarations of the following functions `int sys_trace(void)` and `int sys_date(void)`. 
- added new entries to syscalls[] array that maps unique system call ids to system call handlers. As apart of the trace system call implementation, I also created another array called `static char* sys_call_names[]` that maps the unique system call ids to their string names. 
- lastly, in the `void syscall(void)` function I made it so that, before a system call handler is called, the kernel will print the tracing information to the console and increment the tracing_cnt variable inside the current process. 

* `xv6-public-master/sysproc.c`
modified this file to add the implementations of the kernel-side system call handlers `int sys_trace(void)` and `int sys_date(void)`

* `xv6-public-master/user.h`
modified this file to add the following function declarations `int trace(int)` and `int date(struct rtcdate*)` so that user level programs have something to call if they want to use the trace and date system calls. 

* `xv6-public-master/usys.S`
modified this file to add `SYSCALL(trace)` and `SYSCALL(date)` user stubs so that the `int trace(int)` and `int date(struct rtcdate*)` declared in `user.h` have an implementation.
a
## New Files

* `xv6-public-master/date.c`
created this file as a user-level program to use the newly implemented date system call, which includes printing out the current UTC time and date to the console. 


* `DESIGNDOC.md`
created this file to document my changes made to the CSCI350 project repo and xv6 repo for project 1, as required by the instructions. 
