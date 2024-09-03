#ifndef LIBASM_H
# define LIBASM_H

#include <stddef.h> // Pour size_t, NULL
#include <unistd.h> // Pour ssize_t, read, write
#include <stdio.h>
#include <string.h>

size_t  fr_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
ssize_t ft_read(int fd, void *buf, size_t count);
int     ft_strcmp(const char *str1, const char *str2);
char    *ft_strdup(const char *str);
ssize_t ft_write(int fd, const void *buf, size_t count);

#endif