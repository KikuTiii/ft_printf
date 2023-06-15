#include"../ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	unit;

	if (n < 0)
	{
		write(fd, "-", 1);
		unit = (n % 10) * -1 + '0';
	}
	else
		unit = (n % 10) + '0';
	n /= 10;
	if (n < 1)
		n *= -1;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	write(fd, &unit, 1);
}