
#include "ft_printf.h"
#include <unistd.h>

int     ft_size1(long int nb)
{
        long int     size;

        size = 1;
        while (nb / 10 != 0)
        {
                size = size * 10;
                nb = nb / 10;
        }
        return (size);
}

int    ft_unsigned_putnbr(long int n)
{
        long int     div;
		int		print_size;
		
		print_size = 0;
		if (-2147483647 <= n && n <= 2147483647)
		{
		if (n < 0)
		{
			n = (4294967296 - (-n)) ;
		}
        div = ft_size1(n);
        while (div / 10 != 0)
        {
				print_size++;
                ft_putchar((n / div) + '0');
                n = n % div;
                div = div / 10;
        }
		print_size++;
        ft_putchar(n + '0');
		}
		return (print_size);
}
