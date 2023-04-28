section .data
    hello db "Hello, Holberton", 0xa ; Define a null-terminated string containing the message to be printed

section .text
    global main

main:
    ; Call the printf function to print the message
    mov rdi, hello ; Set the first argument (format string) to the address of the hello string
    mov rax, 0     ; Clear rax to indicate that no floating point arguments are being passed
    call printf    ; Call the printf function to print the message

    ; Exit the program with a return value of 0
    mov rax, 60    ; Set the syscall number for exit to 60
    xor rdi, rdi   ; Set the first argument to 0 to indicate a successful exit
    syscall        ; Call the exit system call

