SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

SECTION .data
    prompt db "Enter 2 character string: "
    lenPrompt equ $ - prompt

    outputText db "The swapped-string is: "
    lenOutputText equ $ - outputText

    newline db 10
    lenNewline equ $ - newline

SECTION .bss
    two_char_string: resb 3
    reversed_two_char_string: resb 3

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
    MOV ecx, prompt
    MOV edx, lenPrompt
    int 0x80

    MOV eax, SYS_READ
    MOV ebx, STDIN
    MOV ecx, two_char_string
    MOV edx, 3
    int 0x80
    CALL print_newline

    ; Print answer
    MOV al, BYTE [two_char_string]
    MOV bl, BYTE [two_char_string + 1]

    MOV BYTE [reversed_two_char_string], bl
    MOV BYTE [reversed_two_char_string + 1], al
    MOV BYTE [reversed_two_char_string + 2], 10 ; Newline characters

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, outputText
    MOV edx, lenOutputText
    int 0x80

    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, reversed_two_char_string
    MOV edx, 3
    int 0x80
    CALL print_newline

exit:
    MOV eax, SYS_EXIT
    MOV ebx, 0
    int 0x80
