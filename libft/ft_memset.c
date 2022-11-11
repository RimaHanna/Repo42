#include <string.h>
void *ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	// i need to manipulate s as an array of chars, so i will cast it into s1
	unsigned char* s1;
	unsigned char c1; 

	if (!s) // si s est null
		return NULL;
	if (n == 0)
		return s;

	i = 0;
	s1 = (unsigned char*)s; //i am casting s into the type of s1
	c1 = (unsigned char)c;
	while (i < n)
	{
		s1[i] = c1;
		i++;
	}
	return s1;
}
/*
#include <stdio.h>
int main()
{
	char str[10] = "rima hanna";
	char c = '$';
	int i = 4;
	ft_memset(str, c, i);
	printf("new string: %s", str);
	return 0;
}
*/
