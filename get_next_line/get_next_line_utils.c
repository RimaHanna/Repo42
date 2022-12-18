#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_bzero(void *s, size_t n)
{
        size_t  i;
        char    *str;

        i = 0;
        str = (char *)s;
        while (i < n)
        {
                str[i] = '\0';
                i++;
        }
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char    *str;
	size_t  i;
	size_t  j;

	i = 0;
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
	if ((char)c == str[i])
		return ((char *)&str[i]);
	return (NULL);
}
