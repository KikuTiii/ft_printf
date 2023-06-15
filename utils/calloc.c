#include "../ft_printf.h"

static void	*ft_memset(void *str, int c, size_t size)
{
	size_t	index;
	char	*src;

	index = 0;
	src = (char *)str;
	while (index < size)
	{
		src[index] = c;
		index++;
	}
	return (src);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*ptr;
	size_t	number;

	number = nitems * size;
	if (nitems != 0 && number / nitems != size)
		return (NULL);
	ptr = malloc(number);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, number);
	return (ptr);
}