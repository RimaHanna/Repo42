

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(NULL)", 6); //i believe i should just return empty;
		return (6);
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

