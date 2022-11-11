#include "libft.h"
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while (dst[i] && src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (srcsize);
}
