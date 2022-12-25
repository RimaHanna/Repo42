#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_line(char *str)
{	
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free (left_str);
		return(NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}

char	*read_line(char *str, char *buf, int fd)
{
	int	i;

	i = 1;	
	while (i > 0 && !ft_strchr(str, '\n'))
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return NULL;
		}
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*str = 	NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	str = read_line(str, buf, fd);
	if (!str)
		return (NULL); 
	free(buf);
	if (ft_strlen(str) == 0)
		return NULL;
	line = get_line(str);
	str = left_str(str);
	return (line);
}

/*
Avant division de la fonction -----
char	*get_next_line(int fd)
{
	int			i;
	char		*buf;
	char		*line;
	static char	*str = 	NULL;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL); 
	while (i > 0 && !ft_strchr(str, '\n'))
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return NULL;
		}
		str = ft_strjoin(str, buf);
	}
	free(buf);
	if (ft_strlen(str) == 0)
		return NULL;
	line = get_line(str);
	str = left_str(str);
	return (line);
}
*/
/*
int main()
{
        int fd;
        char *gnl;

        fd = open("texts/text1.txt", O_RDONLY);
        while(1)
        {
                gnl = get_next_line(fd);
                if (gnl == NULL)
                {
                        break ;
                }
printf("Main, GetNextLine:\n%s\n", gnl);
        }
        close(fd);
        return 0;
}*/
