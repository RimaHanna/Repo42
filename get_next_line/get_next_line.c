#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
	In get_line str has the data in the string until after /n
	in this fonction we are retrieving the data until /n
*/
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

/*
	in left_str we will have the data remaining in str after the
	back slach n
*/
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
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	return (str);
}

/*
	read(int fd, char *buf, int buffer_size)
	read will returns the number of octects
	read is already savng the data inside of buf

	the fonction of read will read from fd and
	return the full string str
	buf is already registring everytime while in the string
	the string that it is reading
	I am using a temp string to free the memory everytime and keep
	the location of the pointer.
*/
char	*get_next_line(int fd)
{
	int			i;
	char		*buf[BUFFER_SIZE + 1];
	char		*temp;
	char		*line;
	static char	*str = NULL;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while (i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
//printf("GNL------------------------------\n");
//printf("....Buffer-size is:\n%d\n", i);
		if (i == -1)
			return NULL;
		buf[i] = '\0';
//printf("....Buf is:\n%s\n", (char *)buf);
		temp = str;
//printf("....Temp is:\n%s\n", temp);
		str = ft_strjoin(temp, (char *)buf);
//printf("....Str is:\n%s\n", str);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
//----------------------
	line = get_line(str);
//printf("....line is:\n%s\n", line);
	temp = str;
//printf("....Temp2 is:\n%s\n", temp);
	str = left_str(temp);
//printf("....Str2 is:\n%s\n", str);
	free(temp);
	return (line);
}

/*
        The main fonction purpose is to show the result
        of the fonction gnl, so i am printing the result
        of gnl, in order to do so, i will do a loop that will turn
        as long as there is still data to show.
        To get data from a file, we will open this file and read from it.
        The file is represented by a number the we register in int just to see.
        The gnl is a string. So we catch the fonction in a str, and we free it each time
        to be able to get the next line.
        open("const char *pathname", int flags)
                  const char *pathname: put the file location and name
        Don't forget that with open there is close;
        And a boucle while(1) mean it infinite
        but we stop it with the if condition when there is no more
        sentences in the file.
*/
int main()
{
        int fd;
        char *gnl;

        fd = open("texts/text1.txt", O_RDONLY);
/*gnl = get_next_line(fd);
printf("MAIN-----------------------------------\n");
printf("GetNextLine:\n%s\n", gnl);
*/
        while(1)
        {
                gnl = get_next_line(fd);
printf("Main, GetNextLine:\n%s\n", gnl);
                if (gnl == NULL)
                {
                        break ;
                        free (gnl);
                }
        }
        close(fd);
        return 0;
}
