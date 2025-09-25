
SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

SECTION .data
    prompt1 db "Enter a digit: "
    lenPrompt1 equ $ - prompt1

    prompt2 db "Enter a second digit: "
    lenPrompt2 equ $ - prompt2

    outputText db "The sum is: "
    lenOutputText equ $ - outputText

    newline db 10
    lenNewline equ $ - newline

SECTION .bss
    num1 resb 2
    num2 resb 2
    answer resb 1

print_newline:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, newline
    MOV edx, lenNewline
    int 0x80
    RET

SECTION .text
    global _start

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

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, outputText
    MOV edx, lenOutputText
    int 0x80

    MOV eax, [num1]
    MOV ebx, [num2]

    ; Converting to number ('0' = 64)
    SUB eax, '0'
    SUB ebx, '0'

    ; Here's what we've been waiting for!
    ADD eax, ebx

    ; Converting back to text
    ADD eax, '0'

    MOV [answer], eax

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, answer
    MOV edx, 2
    int 0x80
    CALL print_newline

exit:
    MOV eax, SYS_EXIT
    MOV ebx, 0
    int 0x80
