SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

global add_digits
extern atoi

global is_palindromeASM

section .text

; --- PART 1 --- ;
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

; --- PART 2 --- ;
is_palindromeASM:
    ; Get string (which is at esp + 4)
    ; ESI -> string
    MOV esi, [esp + 4]

    ; Find length
    MOV ecx, 0

length_loop:    
    CMP byte [esi + ecx], 0
    JE length_found
    CMP byte [esi + ecx], 10
    JE length_found
    INC ecx
    JMP length_loop

length_found:
    ; right index of string = length - 1
    DEC ecx
    MOV edi, 0  ; left index

palindrome_loop:
    CMP edi, ecx
    JGE palindrome_success

    ; Close in from both ends
    MOV al, [esi + edi]
    MOV bl, [esi + ecx]
    ; Compare characters
    CMP al, bl
    JNE palindrome_fail

    ; Increase left index, decrease right index
    INC edi
    DEC ecx
    JMP palindrome_loop

palindrome_success:
    MOV eax, 1
    RET
palindrome_fail:
    MOV eax, 0
    RET

; --- PART 3 --- ;
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

; --- PART 4 --- ;
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