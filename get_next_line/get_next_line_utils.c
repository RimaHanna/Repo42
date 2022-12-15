//#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!*str && !c)
		return ((char *)str);
	return (NULL);
}

int main()
{
        char *str = "rima";
        char c = 'i';
        char *dest = ft_strchr(str, c);
        printf("%s\n", dest);
        return 0;
}
