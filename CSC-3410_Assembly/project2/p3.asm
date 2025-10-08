SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

; Assumption: expects only a single digit input and answer. And a non-zero second digit.

SECTION .data
    prompt1 db "Enter a digit: "
    lenPrompt1 equ $ - prompt1

    prompt2 db "Enter a second digit: "
    lenPrompt2 equ $ - prompt2

    outputText1 db "The quotient is: "
    lenOutputText1 equ $ - outputText1

    outputText2 db "The remainder is: "
    lenOutputText2 equ $ - outputText2

    newline db 10
    lenNewline equ $ - newline

SECTION .bss
    num1 resb 2
    num2 resb 2
    quotient resb 1
    remainder resb 1

SECTION .text
    global _start

print_newline:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, newline
    MOV edx, lenNewline
    int 0x80
    RET

_start: 
    ; Get input

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, prompt1
    MOV edx, lenPrompt1
    int 0x80

    MOV eax, SYS_READ
    MOV ebx, STDIN
    MOV ecx, num1
    MOV edx, 2
    int 0x80

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, prompt2
    MOV edx, lenPrompt2
    int 0x80
    CALL print_newline

    MOV eax, SYS_READ
    MOV ebx, STDIN
    MOV ecx, num2
    MOV edx, 2
    int 0x80
    CALL print_newline

    ; Print answer

    XOR ax, ax
    XOR bx, bx

    MOV al, [num1]
    SUB al, '0'
    MOV ah, 0

    MOV bl, [num2]
    SUB bl, '0'
    MOV bh, 0

    ; Here's what we've been waiting for!
    IDIV bl

    ; Converting back to text
    ADD al, '0'
    MOV [quotient], al

    ADD ah, '0'
    MOV [remainder], ah

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, outputText1
    MOV edx, lenOutputText1
    int 0x80

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, quotient
    MOV edx, 2
    int 0x80
    CALL print_newline

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, outputText2
    MOV edx, lenOutputText2
    int 0x80

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, remainder
    MOV edx, 2
    int 0x80
    CALL print_newline

exit:
    MOV eax, SYS_EXIT
    MOV ebx, 0
    int 0x80
