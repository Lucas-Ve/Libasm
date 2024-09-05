section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
    push rdi
    call ft_strlen
    add rax, 1
    mov rdi, rax
    call malloc
    test rax,rax
    jz .error
    mov rdi, rax         ; L'adresse de la mémoire allouée est dans RDI (destination)
    pop rsi
    call ft_strcpy       ; Copier la chaîne source dans la nouvelle zone de mémoire
    ret

.error:
    xor rax, rax             ; Retourner NULL pour signaler une erreur
    ret