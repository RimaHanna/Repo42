/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:28:02 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/14 15:48:00 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (size != 0)
	{
		while (dst[i] && src[i] && (i < size - 1))
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
#include <bsd/string.h>
#include <stdio.h>
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

