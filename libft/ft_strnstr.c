/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:58:22 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:32:32 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>

char	*ft_strnstr(const char *s1, const char *toFind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*toFind == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (toFind[j] && s1[i + j] && (j < len) && ((i + j) < len))
		{
			if (s1[i + j] != toFind[j])
				break ;
			j++;
		}
		if ((j > 0) && (toFind[j] == '\0'))
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
/*
int main()
{
	char s1[] = "rimahanna";
	char toFind[] = "";
	int n = 3;
	char *ret = ft_strnstr(s1, toFind, n);
	printf("%s\n", ret);
	char *res = strnstr(s1, toFind, n);
	printf("%s\n", res);
	return 0;
}
*/
