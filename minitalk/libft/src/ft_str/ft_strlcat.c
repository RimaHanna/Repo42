/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:49:21 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 18:55:34 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	if ((!dst || !src) && size == 0)
		return (0);
	dstlen = ft_strlen((char *)dst);
	srclen = ft_strlen((char *)src);
	if (size <= dstlen || size == 0)
		return (size + srclen);
	i = 0;
	while ((src[i] != '\0') && (size - 1 > dstlen + i))
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (size > i)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
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
