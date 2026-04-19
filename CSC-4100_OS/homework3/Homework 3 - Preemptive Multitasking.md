---
created: 2026-04-07 10:30:13
---

# CSC 4100 Project 3

## Preemptive Multitasking

---

## Skills you will learn

- Programming the timer device  
- Handling the timer interrupt  

---

## Tools you will need

- Use the VM provided for the previous assignment  
- Use the libos.a provided by the previous assignment  
- Use this boot.S  
- Interrup Service Routine  

---

## Description

### Introduction

In this assignment, you will set up a interrupt service routine that task switch your processes, without your processes calling dispatch().  To do so, you must first create your processes as you did in the previous assignment, and then you must set up the exception table so that the hardware knows which handler to call when the timer fires, initialize and enable the timer, and turn on interrupts.  Finally, you will branch to restore_context to start the processes running.  Note that you will need to use the new boot.S provided in the link above for this assignment instead of the boot.S provided in the previous assignment.

---

## The main driver

Below is the main driver for this assignment.  The main() will clear the screen, initialize the exception vector table, initialize a timer device, and then call go to the the processes started.

```plaintext
main:
begin
    clear the screen
    create the four processes
    set up the exception table
    initialize the timer
    jump to restore_context
end
```

The four processes will remain the same as the previous assignment, except that you will remove the call to dispatch() from each. Do not forget to remove the call to dispatch() from your process code (p1(), p2(), p3(0 and p4(0)) or your OS will not work.

---

## Setting up the timer and the EVT

Following is some code to help you set up the exception table and initialize the timer that you will use in the main(). All of these function must be written in assembler:

### Setup Code (Exception Table and Timer)

#### `void setup_EVT()`

Tell the hardware about the exception vector table.

```asm
// set up the exception vector table
adr     x0, vector_table 
msr     VBAR_EL1, x0        // Set the vector base address
ret
```

#### `void init_timer();`

Initialize the timer.

```asm
stp     x29, x30, [sp, -16]!
bl      clear_timer
//route core 0 counter to core 0 irq
ldr     x0, =0x40000040
mov     x1, 0x08
str     w1, [x0]
// enable timer
mov     x0, 1
msr     CNTV_CTL_EL0, x0
ldp     x29, x30, [sp], 16
ret
```

#### `void clear_timer();`

Reset the time to so that it will fire in 1/20 of a second.

```asm
// read count frequency
mrs     x0, CNTFRQ_EL0
mov     x1, 20
udiv    x0, x0, x1
// clear cntv interrupt and set next 1 sec timer.
msr     CNTV_TVAL_EL0, x0
ret
```

---

As you can see from the above code, the setup_EVT() function installs as table that branches to an interrupt handler according to the exception (interrupt) that has occurred. The exception table must be defined as follows:

```asm
vector_table:
 .balign 128
    b unsupported
.balign 128
    b dispatch
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b dispatch    // yes
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b dispatch
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b unsupported
.balign 128
    b dispatch
.balign 128
    b unsupported
.balign 128
    b unsupported
```

The unsupported() exception handler should just print a message such as "Error: unsupported exception!" in the top left corner of the screen and then go into an infinite loop. You can write this function in either C or assembly using the print_to() function from libos.a.

---

## Modifications to dispatch()

You must also modify dispatch() so that it can be called from the timer interrupt. The was that exception levels work for this assignment is that processes execute instructions in what is called EL0 in ARMv8 terminology. Exception handlers themselves run at EL1. Think of these exception levels as similar to kernel mode (EL1) and user mode (EL0). The following is the annotated pseudocode that you will need for your modified version of dispatch to be able to handle the exception levels properly.

```asm
dispatch:
    /* 
        Stack layout:
        x0
        x2
        ...
        x28
        x29
        x30
        PSTATE
        Exception return address
    */

    Disable interrupts                    // How: msr     DAIFSet, #0x2

    // Next, you will save the context of the current process
    // Note that the OS stack is active in EL1 and is different from the
    //   process stack
    // So, we will load a register, in this case x1, with the processes
    //   stack pointer and use it to restore the process context
    
    Save x1 Temporarily so we can use it to reference the process stack
                                        // How? Just use the str instruction
                                        // and sp as the destination like
                                        // normal
                            
    Load the process stack pointer       // How? the process stack pointer is
                                         //  saved in the system register SP_EL0.
                                         //  So: MRS     x1, SP_EL0

    // Now, X1 has the process stack pointer
    Make room for the process context on the process stack
       by subtracting 16*17 from x1

    // Now Save the proces general purpose registers

    Store the process's x0 and x1 onto process stack
                                        // a little tricky, but you can figure it out

    Store the register x2...x30 on the stack
                                        // remember to use x1 as the destination
                                        //    not sp
                                        // example: stp x2, x3, [x1, 16]
    

    Save the process PSTATE              // How? mrs     x0, SPSR_EL1
                                        //      str     x0, [x1, 16*15+8]

    Save the interrupt return address    // How? mrs     x0, ELR_EL1              
                                        //      str     x0, [x1, 16*16]

    Save the value of x1 into the process's PCB
    Enqueue the current process to the ready Q (call enqueue)       

 
restore_context:
    Dequeue the next process to run and set global "Running" to its PCB pointer
    Get the stack pointer from the PCB (at which "Running" points) 
       and put it in x1

    // now that x1 is pointing to the process's stack...
    Restore the PSTATE                   // How? ldr     x0, [x1, 16*15+8]
                                        //      msr     SPSR_EL1, x0

    Restore interrupt return address    // How? ldr     x0, [x1, 16*16]   
                                        msr     ELR_EL1, x0

    Store the new top of stack into the
    System exception register for EL0.        // How? mov     x0, x1           
                                            //      add     x0, x0, 16*17    
                                            //      MSR     SP_EL0, x0          
                                            //   Note: When the handler returns via
                                            //   eret, this will be the value of sp

    Restore process registers x2...x29,     // but do not restore x0,x1 just yet
                                            //   we are going to use them
                                            // Also, do not yet restore x29 and x30
                                            //   we will make a function call, which
                                            //   can wipe them out
                                            // Hint: start like so: 
                                            //   ldp     x2, x3, [x1, 16]
   
 
    // clear counter and reset the timer.
    // This is easy...
    temporarity save x0 and x1
    call clear_timer            // code is given for clear_timer above 
    restore x0 and x1

    restore  x30                // hint: x30 is on the stack at which x1 points plus 
                               //   offset 16*15
                               // ...
    restore x0 and x1            

    enable interrupts           // How? msr     DAIFClr, #0x2
    
    eret
```

---

## Modify create_process

You will need to do a slight modification to spawn_process() because we are putting an extra value on the stack, the interrupt return address. In your create_process code, you should have a FOR loop that places 32 values on the stack. Modify it to place 33 values on the stack. Then, you should have a line after the FOR loop that looks something like:

```c
*(sp+30) = (uint64_t) pfun;
```

Replace that line with the following:

```c
*(sp+32) = (uint64_t) pfun;
```

---

## The complete version

A video of a working program follows:

---

## Submission

To submit, run:

```bash
make clean
```

Then create your tarball with the following command:

```bash
tar -czf your_tech_username_p3.tar.gz your_tech_username
```

Where your_tech_username is your TnTech email without the "@tntech.edu". Your project directory that contains all of your code and the Makefile should be in a directory whose name is the same as your TnTech user name. Remember, the professor will not grade your assignment without a properly working Makefile. Submit your assignment via iLearn.

---

**Due on Apr 19, 2026 11:59 PM**

---

## Debugging tips from professor

- Put break points on dispatch, and see if it breaks on dispatch. If it does, then that means...
	- You set the timer right
	- The interrupt vector is set up right
	- And the registers are right
- A lot of what you find online is wrong. This is because people don't know what preemptive multitasking is and will just do something weird. **Keep this in mind when using AI.**