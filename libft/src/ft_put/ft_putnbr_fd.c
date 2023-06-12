/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:51:17 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:52:03 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int	ft_size(int nb)
{
	int	size;

	size = 1;
	while (nb / 10 != 0)
	{
		size = size * 10;
		nb = nb / 10;
	}
	return (size);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	div;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}	
	div = ft_size(n);
	while (div / 10 != 0)
	{
		ft_putchar_fd((n / div) + '0', fd);
		n = n % div;
		div = div / 10;
	}
	ft_putchar_fd(n + '0', fd);
}
/*
int main()
{
	int nb = -254;
	ft_putnbr_fd(nb, 2);
	return 0;

}
*/
