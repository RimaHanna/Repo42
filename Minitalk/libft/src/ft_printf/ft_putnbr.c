/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:49:34 by rhanna            #+#    #+#             */
/*   Updated: 2022/12/10 11:39:15 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_size(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		nb = -nb;
		size++;
	}
	while (nb / 10 != 0)
	{
		size++;
		nb = nb / 10;
	}
	size++;
	return (size);
}

int	ft_putnbr(long int n)
{
	int	print_len;

	print_len = 0;
	print_len = ft_size(n);
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar ((n % 10) + '0');
	return (print_len);
}

/*
int main()
{
	int len = ft_putnbr(-1212334);
	printf("\n %d\n", len);
	return 0;
}*/
