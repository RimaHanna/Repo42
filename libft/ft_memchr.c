/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:51:12 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/15 10:51:46 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>
/*
void display(char *str)
{
	if (str == 0)
	{
		write(1, "<NULL>\n", 7);
		return;
	}
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;	
	}
	write(1, "\n", 1);
}
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (str[i] && i < n)
	{
		if (str[i] == (char)c)
			return ((unsigned char *)&str[i]);
		i++;
	}	
	return (0);
}
/*
int main()
{
	char str[] = "rimahnaa";
	char c = 'm';
	int n = 4;
	char *s = memchr(str, c, n);
	display(s);
	s = ft_memchr(str, c, n);
	display(s);
	
	return 0;
}
*/

