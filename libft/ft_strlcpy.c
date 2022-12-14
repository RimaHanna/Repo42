/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:28:02 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 14:01:38 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!size)
		return (srcsize);
	i = 0;
	if (size != 0)
	{
		while (src[i] && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}	
	return (srcsize);
}
/*
//the library of strlcpy takes bsd/string.h and
 when compailing i have to add -lbsd in the end
int main()
{
	char str[] = "rima hanna";
	char src[] = "abc";
	int n = 3;
	int ret = ft_strlcpy(str, src, n);
	printf("%d\n", ret);

	int ret1 = strlcpy(str, src, n);
	printf("%d\n", ret1);

	return 0;
}*/
