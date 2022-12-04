

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}


/* write the caracter c, cast to "unsigned char" */
