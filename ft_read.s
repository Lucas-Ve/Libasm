section .text
global ft_read
extern	__errno_location

ft_read:
    mov rax, 0
    syscall
    test rax, rax       ; Vérifier si la valeur de retour est négative
    js .error           ; Si négatif (erreur), aller à la gestion d'erreur
    ret                 ; Si pas d'erreur, retourner (RAX contient le nombre d'octets écrits)

.error:
    mov rdi, rax
    neg rdi
    call __errno_location   ; Appeler errno_location pour obtenir l'adresse de errno
    mov [rax], edi          ; Stocker la valeur d'erreur dans errno
    mov rax, -1             ; Retourner -1 pour signaler une erreur
    ret