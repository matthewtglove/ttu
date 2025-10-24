SYS_READ equ 3
SYS_WRITE equ 4
STDIN equ 0
STDOUT equ 1
SYS_EXIT equ 1

SECTION .data
    promptInput db "Please enter a string: "
    lenPromptInput equ $ - promptInput

    msgSuccess db "✅ Hooray! This is a palindrome"
    lenMsgSuccess equ $ - msgSuccess

    msgFail db "❌ Nope, that's not a palindrome"
    lenMsgFail equ $ - msgFail

SECTION .bss
    inputStr 