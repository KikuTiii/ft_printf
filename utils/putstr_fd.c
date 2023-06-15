#include"../ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char	index;

	if (s == 0)
		return ;
	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}