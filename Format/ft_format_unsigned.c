#include "../ft_printf.h"

static char	*ft_unsigned_itoa(unsigned int n)
{
	char buffer[12];
	int index = 11;
	buffer[index--] = '\0';

	if (n == 0)
		buffer[index--] = '0';
	else
	{
		while (n != 0)
		{
			buffer[index--] = n % 10 + '0';
			n /= 10;
		}
	}
	return ft_strdup(&buffer[index+1]);
}

int	ft_format_unsigned(int number)
{
	int		len;
	char	*str;

	str = ft_unsigned_itoa(number);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free (str);
	return (len);
}
