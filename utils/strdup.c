#include"../ft_printf.h"

char	*ft_strdup(char *src)
{
	unsigned int		index;
	char				*dest;

	index = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (dest == 0)
		return (0);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

// int main(void)
// {
//     char src[] = "GeeksForGeeks";

//     char *target = ft_strdup(src);
//     char *target1 = strdup(src);

//     printf("%s\n", target);
//     printf("%s\n", target1);
//     return 0;
// }