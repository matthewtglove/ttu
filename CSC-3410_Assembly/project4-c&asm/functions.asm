SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

global addstr
extern atoi

global is_palindromeASM

global factstr
extern fact

global palindrome_check
extern is_palindromeC

SECTION .data
    promptInput db "Please enter a string: "
    lenPromptInput equ $ - promptInput

    msgSuccess db "✅ Hooray! This is a palindrome", 10
    lenMsgSuccess equ $ - msgSuccess

    msgFail db "❌ Nope, that's not a palindrome", 10
    lenMsgFail equ $ - msgFail

SECTION .bss
    buffer resb 1024

section .text

; --- PART 1 --- ;
; int addstr(char *a, char *b)
addstr:
    PUSH ebp
    MOV ebp, esp
    ; preserve ebx (callee-saved)
    PUSH ebx

    ; atoi(a)
    PUSH dword [ebp + 8]
    CALL atoi
    ADD esp, 4
    MOV ebx, eax

    ; atoi(b)
    PUSH dword [ebp + 12]
    CALL atoi
    ADD esp, 4

    ADD eax, ebx
    ; return is now in eax (sum of integers)

    ; restore ebx
    POP ebx
    MOV esp, ebp
    POP ebp
    RET

; --- PART 2 --- ;
; int is_palindromeASM(char *s)
is_palindromeASM:
    PUSH ebp
    MOV ebp, esp
    PUSH esi
    PUSH edi
    ; preserve ebx (callee-saved)
    PUSH ebx

    ; Get string (which is at esp + 4)
    ; ESI -> string
    MOV esi, [ebp + 8]

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
    ; left index
    MOV edi, 0 

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
    ; return is now in eax (holds 1 for palindrome)
    JMP palindrome_done
palindrome_fail:
    MOV eax, 0
    ; return is now in eax (holds 0 for not palindrome)
    JMP palindrome_done

palindrome_done:
    ; restore ebx
    POP ebx
    POP edi
    POP esi
    MOV esp, ebp
    POP ebp
    RET

; --- PART 3 --- ;
; int factstr(char *s)
factstr:
    PUSH ebp
    MOV ebp, esp

    ; atoi(s)
    PUSH dword [ebp + 8]
    CALL atoi
    ; eax now holds the integer value

    ; cleanup argument
    ADD esp, 4

    ; Push eax as argument to fact
    PUSH eax
    CALL fact

    ; cleanup argument
    ADD esp, 4

    ; return is now in eax (holds the factorial result)

    MOV esp, ebp
    POP ebp
    RET

; --- PART 4 --- ;
; void palindrome_check()
palindrome_check:
    ; preserve ebx (callee-saved)
    PUSH ebx

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

    ; Call palindrome check (passing in the pointer "buffer" to the string)
    PUSH buffer
    CALL is_palindromeC
    ADD esp, 4

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

    ; restore ebx
    POP ebx

    RET

print_palindrome_fail:
    MOV eax, SYS_WRITE
    MOV ebx, STDOUT
    MOV ecx, msgFail
    MOV edx, lenMsgFail
    int 0x80

    ; restore ebx
    POP ebx

    RET
