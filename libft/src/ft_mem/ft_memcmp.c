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

#include "libft.h"

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
/**
 * The ft_memcmp function compares two blocks of memory and returns an 
 * integer representing the difference between the first non-matching bytes.
 * 
 * memcmp don't stops at '\0' it continues following the n size
 * One important feature of ft_memcmp is that it allows you to compare memory 
 * blocks without assuming anything about their contents. This means that it can
 * be used to compare any type of data, including strings, arrays, structures, 
 * and more. The function can also be used to implement other functions that 
 * rely on memory comparison, such as sorting algorithms, binary search 
 * algorithms, and checksum algorithms.
*/
