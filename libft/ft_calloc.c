#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nitems, size_t sizeitems)
{
	void	*ptr;

	ptr = (void *)malloc(nitems * sizeitems);
	if (!ptr)
		return (NULL);	
	ft_bzero(ptr, nitems);
	return (ptr);
}
/*
int		main()
{
	char	*str;
	char	*str1;

	str = (char *)ft_calloc(30, sizeof(char));
	printf("str: %s\n", str);
	str1 = (char *)calloc(30, sizeof(char));
	printf("str1: %s\n", str1);
	return (0);
}
*/
