/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:23:54 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:13:43 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* l18:i need to manipulate s as an array of chars, so i will cast it into s1*/
/* l28: i am casting s into the type of s1*/
/* l23: (!s) means that s is null*/
#include <string.h>
#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	if (!s)
		return (NULL);
	if (n == 0)
		return (s);
	i = 0;
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		s1[i] = c1;
		i++;
	}
	return (s1);
}
/*
int main()
{
	char str[10] = "rima hanna";
	char c = '$';
	int i = 5;
	ft_memset(str, c, i);
	printf("new string: %s\n", str);

	char str1[10] = "rima hanna";
	memset(str1, c, i);
	printf("system test: %s\n", str1);
	return 0;
}
*/
