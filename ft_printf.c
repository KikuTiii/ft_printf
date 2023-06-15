#include "ft_printf.h"

static int	ft_arg_type(int type, va_list ap)
{
	if (!type)
		return (0);
	if (type == 'd' || type == 'i')
		return (ft_format_decimal(va_arg(ap, int)));
	else if (type == 'c')
		return (ft_format_character(va_arg(ap, int)));
	else if (type == 's')
		return (ft_format_string(va_arg(ap, char *)));
	else if (type == 'p')
		return (ft_format_pointer(va_arg(ap, void *)));
	else if (type == 'x')
		return (ft_format_lowHex(va_arg(ap, int)));
	else if (type == 'X')
		return (ft_format_upperHex(va_arg(ap, int)));
	else if (type == 'u')
		return (ft_format_unsigned(va_arg(ap, size_t)));
	else if (type == '%')
		return (ft_format_percent());
	return (0);
}

static int	ft_handle(const char *print, va_list ap)
{
	int	type;
	int	index;

	type = 0;
	index = 0;
	while (print[index] != '\0')
	{
		if (print[index] == '%')
		{
			type += ft_arg_type(print[index + 1], ap);
			index++;
		}
		else
		{
			ft_putchar_fd(print[index], 1);
			type++;
		}
		index++;
	}
	return (type);
}

int ft_printf(const char *print, ...)
{
	va_list	ap;
	int type;

	if (!print)
		return (0);
	va_start(ap, print);
	type = ft_handle(print, ap);
	va_end(ap);
	return (type);
}

// int main(void)
// {
//     unsigned int number = 20;
//     ft_printf("Unsigned: %u\n", number);
//     return (0);
// }

// int main(void)
// {
//     int num = 42;
//     ft_printf("Decimal: %i\n", num);
//     ft_printf("Hexadecimal Lower: %x\n", num);
//     ft_printf("Hexadecimal Upper: %X\n", num);

//     char name[] = "John Doe";
//     ft_printf("Name: %s\n", name);

//     int positiveNum = 42;
//     int negativeNum = -42;
//     ft_printf("Positive number: %d\n", positiveNum);
//     ft_printf("Negative number: %d\n", negativeNum);

//     char xar[] = "J";
//     char xar2[] = "o";
//     ft_printf("Character: %c\n", xar);
//     ft_printf("Character: %c\n", xar2);

//     unsigned int number = 20;
//     ft_printf("Unsigned: %u\n", number);

//     double percent = 75.5;
//     ft_printf("Percent: %%\n", percent);

//     return (0);
// }