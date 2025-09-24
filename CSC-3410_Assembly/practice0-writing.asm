section .data
    str db "Hello, Test!"
    len equ $ - str

section .text
    GLOBAL _start

_start: 
    ; sys_write (eax=4)
    mov eax, 4
    mov ebx, 1
    mov ecx, str
    mov edx, len
    int 0x80

    ; sys_exit (eax=1)
    mov eax, 1
    mov ebx, 0
    int 0x80
    