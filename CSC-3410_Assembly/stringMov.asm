SECTION .bss
    srcPointer RESB 100
    destPointer RESB 100

SECTION .text
    global _start

_start:
    CLD
    MOV esi, srcPointer
    MOV edi, destPointer
    MOV ecx, 50
    REP MOVSB