SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

SECTION .data
    promptInput db "Please enter a string (blank to exit): "
    lenPromptInput equ $ - promptInput

    msgSuccess db "✅ Hooray! This is a palindrome", 10
    lenMsgSuccess equ $ - msgSuccess

    msgFail db "❌ Nope, that's not a palindrome", 10
    lenMsgFail equ $ - msgFail

    msgGoodbye db "👋 Goodbye", 10
    lenMsgGoodbye equ $ - msgGoodbye

SECTION .bss
    buffer resb 1024

SECTION .text
    global _start

is_palindrome:
    ; Save the old base pointer to the stack
    PUSH ebp
    ; And now set the new base pointer
    MOV ebp, esp

    ; ESI -> buffer
    MOV esi, [ebp + 8]
    ; ECX -> length
    MOV ecx, [ebp + 12]
    MOV edi, 0
    DEC ecx

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
    POP ebp
    RET
palindrome_fail:
    MOV eax, 0
    POP ebp
    RET

; --- Main program --- ;
_start:
    ; Get input
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, promptInput
    MOV edx, lenPromptInput
    int 0x80
    MOV eax, SYS_READ
    MOV ebx, STDIN
    MOV ecx, buffer
    MOV edx, 1024
    int 0x80

    ; Check exit
    CMP byte [buffer], 10
    JE exit

    ; String length (ignore newline at end)
    DEC eax
    MOV esi, eax

    ; Call palindrome check
    PUSH esi
    PUSH buffer
    CALL is_palindrome
    ADD esp, 8

    ; Print result
    CMP eax, 1
    JE print_palindrome_success
    JMP print_palindrome_fail

print_palindrome_success:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, msgSuccess
    MOV edx, lenMsgSuccess
    int 0x80
    JMP _start

print_palindrome_fail:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, msgFail
    MOV edx, lenMsgFail
    int 0x80
    JMP _start

exit:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, msgGoodbye
    MOV edx, lenMsgGoodbye
    int 0x80

    MOV eax, SYS_EXIT
    MOV ebx, 0
    int 0x80