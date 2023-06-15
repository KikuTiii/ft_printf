#include "../ft_printf.h"

int	ft_format_character(char character)
{
	ft_putchar_fd(character, 1);
	return (1);
}
