#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (dest);	
	while (i < n)
	{
	((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

#include <stdio.h>
int main()
{
	char dest[] = "rima hanna";
	char *src = dest + 2;
	int n = 4;
	ft_memcpy(dest, src, n);
	printf("%s.\n", dest);
	return 0; 
}

