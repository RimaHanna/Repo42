#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char ft_transform1(unsigned int i, char c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return c;
}
// des methodes de cryptage
char ft_transform2(unsigned int i, char c)
{
	return ++c;
}

char ft_transform3(unsigned int i, char c)
{
	int key[4] = {1, 5, 5, 7};
	c = c + key[i % 4];
	return c;
}

// clé rotative (pour crypter au max)
char ft_transform4(unsigned int i, char c)
{
	int key[4] = {1, 5, 5, 7};

	c = c + key[(i % 4) + (i / 4) % 4];
// pour savoir comment il est en train de faire les calculs,ecrit
// sur un papier les numero de 1 jusqu'a 30 par exemple et fais les calucls.
// a chaque fois qu il tourne il va avoir +1 pour la boucle jusqu'a ce qu'il arrive a 
// 4, il reprend de zero.
	return c;
}

int main()
{
	char *str = "It is a good day to die";
	char *str1 = ft_strmapi(str, ft_transform1);
	printf("str1: %s\n", str1);

	char *str2 = ft_strmapi(str, ft_transform2);
	printf("str2: %s\n", str2);

	char *str3 = ft_strmapi(str, ft_transform3);
	printf("str3: %s\n", str3);
 
	char *str4 = ft_strmapi(str, ft_transform4);
	printf("str4: %s\n", str4);
	return 0; 
}
*/
