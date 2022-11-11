//#include "libft.h"
#include <stddef.h>
int ft_strlen(const char *str)
{
	size_t i = 0;
	while (str[i])
		i++;
	return i;
}

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t i;
	size_t d;
	size_t s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (destsize == 0)
		return (s);
	if (destsize - 1 <= d)
		return (s + destsize);
	while (src[i] && (d + i <destsize - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

#include <stdio.h>
int    main()
{
    char    dest[] = "hello";
    char    src[] = "saluttt";

    printf("%s\n%s\n%li\n", dest, src, ft_strlcat(dest, src, 10));
    return (0);
}
