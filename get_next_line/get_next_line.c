#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int get_size_line(int fd, char *line)
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	char		*temp;
	static char *str;
	
	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <=0)
		return -1;
	if (!buf)
		return (0);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		free (temp);
		if (ft_strchr(str, '\n'))
			break;
	}
	return ret;	
}

char *get_next_line(int fd)
{
	char *line;
	static char *left_line;

	left_line = get_size_line(fd, line);
	if (!left_line)
		return NULL;
	line = ft_get_line(left_line);
	left_line = ft_new_left_str(left_str);
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
	char *line;

	fd = open("textx/text1.txt", O_RDONLY);
	printf("The number of the File: %d\n", fd);
	while (1) 
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("GetNextLine: %s", line);
		free(line);
	}
	close(fd);
	return 0;
}
