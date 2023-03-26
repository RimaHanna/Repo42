/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:53:26 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 12:56:56 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* memcmp n'arrete pas au \0 il  continu a comparer selon le size n donnée */
#include <stddef.h>
#include "libft.h"
#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char str1[] = {-128, 0, 127, 0};
	char str2[] = {-128, 0, 127, 0};
	int i = 333;
	int ret1 = ft_memcmp(str1, str2, i);
	printf("%d\n", ret1);

	int ret2 = memcmp(str1, str2, i);
	printf("%d\n", ret2);

	return 0;
}
*/
