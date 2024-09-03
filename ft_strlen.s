section .text
global ft_strlen

ft_strlen:
    xor rax, rax            ; Initialiser le compteur (rax = 0)

.loop:
    cmp byte [rdi + rax], 0 ; Comparer chaque byte avec 0 (fin de chaîne)
    je .end                 ; Si zéro, terminer la boucle
    inc rax                 ; Incrémenter le compteur
    jmp .loop               ; Répéter

.end:
    ret                     ; Retourner rax (la longueur)
