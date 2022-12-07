/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:01:24 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/05 16:06:01 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_size(unsigned int nb)
{
	long int	size;

	size = 0;
	while (nb / 10 != 0)
	{
		size++;
		nb = nb / 10;
	}
	size++;
	return (size);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int print_len;

	print_len = 0;
	print_len = ft_size(n);

	if (n >= 10)
	{
		ft_unsigned_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
	return (print_len);
}

/*
int main()
{
	int ret = ft_unsigned_putnbr(-1234567);
	printf("\n%d\n", ret);
	return 0;
}
*/
