
#include <fcntl.h>
#include <stdio.h>

// a fonction that readthe next line
char *ft_read()



// a fonction that register the next line //take into consideration if fd is negatif or size is nul
char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return 0;
	
	
	return (line);
}


// main fonction that give the text and open it and register the data
int main()
{
	int fd1;
	char *line;


	fd1 = open("textx/text1.txt", O_RDONLY);

	printf("fd1:	%d\n", fd1);
	printf("fd2:	%d\n", fd2);

	//je cré une boucle infinie quand je renvoie 1 ou
	//je peux créer une boucle sur i et mettre < 7 ligne
	while (1) 
	{
		line = get_next_line(fd1);

		//je vais sortir de la boucle quand mon fichier sera entierement lu
		//line va envoyer un zero quand il sera completement lu
		if (line == NULL)
			break;
		printf("line fd1: %s", buf);

		//i have to free the line each time after calling so i use free
		//if i don't use the pointer will be crashed
		free(line);

	}
	close(fd1);
	return 0;
}
