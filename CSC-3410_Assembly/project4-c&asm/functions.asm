SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

    ; --- PART 1 --- ;
global add_digits
extern atoi

section .text

; int addstr(char *a, char *b)
addstr:
    ; atoi(a)
    PUSH dword [esp + 4]
    CALL atoi
    ADD esp, 4
    MOV ebx, eax

    ; atoi(b)
    PUSH dword [esp + 8]
    CALL atoi
    ADD esp, 4
    MOV ebx, eax

    ADD eax, ebx

    RET

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