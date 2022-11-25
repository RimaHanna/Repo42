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
int    main()
{
    char    dest[] = "hello";
    char    src[] = "saluttt";
    printf("%s\n %s\n %li\n", dest, src, ft_strlcat(dest, src, 10));


    char    dest1[] = "hello";
    char    src1[] = "saluttt";
    printf("%s\n %s\n %li\n", dest1, src1, strlcat(dest1, src1, 10));
    return (0);
}*/
