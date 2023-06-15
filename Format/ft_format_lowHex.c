#include "../ft_printf.h"

int	ft_format_lowHex(unsigned int num)
{
	int		len;
	char	*str;

	str = ft_itoa_base(num, HEX_BASE_LOWER);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}
