#include "libft.h"
#include <unistd.h>

void ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);// esque je ne peux pas utiliser deux fichier avec fd
		i++;
	}
}

/*
 *This function is exactly the same as our ft_putstr function except that we
 * are requiring a file descriptor in the parameter along with the desired
 * string to be to be written. As we do in our ft_putchar_fd function, we use
 * a file descriptor obtained from the open system call, or we can use 0, 1, or
 * 2, to refer to the standard input, standard output, or standard error. We
 * use the fd parameter as the first parameter in our write function. We then
 * place our string as write's next parameter. Last we use ft_strlen on our
 * string so we know how many bytes will need to be written, which is the same
 * as the length of the given string. Write will then write string s to the
 * desired output.

void		ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}


int main()
{
	char str[] = "rima";
	ft_putstr_fd(str, 2);
	return 0;
}
*/

