/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_hex_putnbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:24 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/05 18:02:24 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_size(unsigned int nb)
{
	long int	size;

	size = 1;
	while (nb / 16 != 0)
	{
		size = size * 16;
		nb = nb / 16;
	}
	return (size);
}

int	ft_min_hex_putnbr(unsigned int n)
{
	unsigned int	div;
	int				print_size;

	print_size = 0;
	div = ft_size(n);
	while (div / 16 != 0)
	{
		print_size++;
		ft_putchar((n / div) + '0');
		n = n % div;
		div = div / 16;
	}
	print_size++;
	ft_putchar(n + '0');
	return (print_size);
}

// int    ft_unsigned_putnbr(unsigned int n)
// {
// 	if (n >= 10)
// 	{
// 			ft_putnbr(n / 10);
// 			ft_putnbr(n % 10);
// 	}
// 	else
// 			ft_putchar(n + 48);
// 	return(ft_size1(n));
// }
