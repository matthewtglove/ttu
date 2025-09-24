section .bss
    inputStrMaxBytes equ 10 ; does not need to be in a section
    inputStr resb inputStrMaxBytes

section .text
    GLOBAL _start
_start:
    ; read from stdin (eax=3)
    mov eax, 3
    mov ebx, 0
    mov ecx, inputStr
    mov edx, inputStrMaxBytes
    int 0x80

    ; sys_write (eax=4)
    mov edx, eax ; bytes of inputStr
    mov eax, 4
    mov ebx, 1
    mov ecx, inputStr
    int 0x80

    ; sys_exit
    mov eax, 1
    mov ebx, 0
    int 0x80