section .text
global ft_strcpy

ft_strcpy:
.loop:
    mov al, byte[rsi]
    mov byte[rdi], al     ; AL est un registre en assembleur x86-64. Plus précisément, c'est la partie basse (8 bits) du registre RAX.
    inc rdi
    inc rsi
    test al,al            ; Vérifier si le caractère copié est le caractère nul (\0)
    jnz .loop             ; Si ce n'est pas nul, continuer à copier jnz = jump if not zero
    mov rax, rdi          ; Placer le pointeur de destination dans RAX
    ret                   ; Retourner le pointeur de destination