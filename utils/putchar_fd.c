#include "../ft_printf.h"

void ft_putchar_fd(char c, int fd)
{
    write(fd,&c,1);  // escreve o caractere 'c' no descritor de arquivo 'fd'
}