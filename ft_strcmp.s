section .text
global ft_strcmp

ft_strcmp:
    xor rax, rax
    
.loop:
    cmp byte [rdi], 0
    je .end                 
    cmp byte [rsi], 0
    je .end
    mov al, byte [rdi]
    cmp byte [rsi], al
    jne .end           
    inc rsi                 
    inc rdi                 
    jmp .loop

.end:
    movzx rax, byte [rdi]
    movzx rdx, byte [rsi]
    sub rax, rdx
    ret


