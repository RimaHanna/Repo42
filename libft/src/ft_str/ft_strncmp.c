/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:49:52 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:32:11 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]) && (i < n - 1))
	{
		i++;
	}
	if (s1[i] != s2[i] && (n != 0))
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
int main()
{
	char *s1 = "b";
	char *s2 = "a";
	size_t n = 5;
	int ret = ft_strncmp(s1, s2, n);
	printf("%d\n", ret);
	int ret1 = strncmp(s1, s2, n);
	printf("%d\n", ret1);
	return 0;
}
*/
