section .bss
    buffer resb 20           ; buffer for input

section .data
    maxSize equ 20           ; maximum characters to read

section .text
    global _start
    global read_loop
    global write_back
    gloabl exit_program
    
_start:
    mov ecx, buffer          ; pointer to buffer
    mov edi, 0               ; index / counter

read_loop:
    ; sys_read one char into ecx + edi
    ; check if char is '\n' or maxSize reached
    ; increment index (edi)
    ; loop back if needed

write_back:
    ; sys_write entire buffer
    ; use edi as number of bytes to write

exit_program:
    ; sys_exit
