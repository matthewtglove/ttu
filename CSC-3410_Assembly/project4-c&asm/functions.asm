SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

SECTION .data
    ; --- PART 2 --- ;
    ; --- PART 3 --- ;
    ; --- PART 4 --- ;

SECTION .bss
    ; --- PART 1 --- ;
    num1 resb 2
    num2 resb 2
    answer resb 1

    ; --- PART 2 --- ;
    ; --- PART 3 --- ;
    ; --- PART 4 --- ;

addstr:
    ; The C driver will prompt and read 
    ; two strings from the user. 
    ; Then the C driver will call the 
    ; addstr() assembly function. 
    ; Finally, the C driver will print the 
    ; results from the assembly function. 
    ; Note, the assemby function must call 
    ; the atoi() C Library function to  
    ; Convert the strings to integers. 

is_palindromeASM:
    ; The C driver will prompt and read a 
    ; string from the user. 
    ; Then the C driver will call the 
    ; is_palindrome function and 
    ; print its results.  You may use the 
    ; is_palindrome() function 
    ; that you wrote in the previous 
    ; assignment.

factstr:
    ; The C driver will prompt and read a 
    ; string from the user. 
    ; The the C driver will call the factstr() 
    ; function.  The factstr() 
    ; function which will  convert the 
    ; string argument to integer by calling 
    ; the atoi() C library function. factstr() 
    ; will then call the C function fact() to  
    ; obtain the factorial of the integer, 
    ; and then pass the answer back to the 
    ; C driver, which will then print it. 

palindrome_check:
    ; The C driver will immediately call 
    ; the assembler function 
    ; palindrome_check. 
    ; This assembler function will then 
    ; prompt and read a string from the 
    ; user. 
    ; Next, palindrome_check() will call 
    ; the is_palindrome() function written 
    ; in C 
    ; to determine if the string is a 
    ; palindrome, and then print the 
    ; results.