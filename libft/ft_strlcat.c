/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:49:21 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 14:27:21 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (destsize == 0)
		return (s);
	while (src[i] && (d + i < destsize - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	if (d > destsize)
		return (s + destsize);
	return (d + s);
}

/*
void    ft_print_result(int n)
{
        char c;

        if (n >= 10)
                ft_print_result(n / 10);
        c = n % 10 + '0';
        write (1, &c, 1);
}

int             main(int argc, const char *argv[])
{
        char    *dest;
        if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
                return (0);
        memset(dest, 0, 15);
        memset(dest, 'r', 6);
                memset(dest, 'r', 15);
        ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
        write(1, "\n", 1);
               write(1, dest, 15);
        write(1, "\n", 1);
}*/
