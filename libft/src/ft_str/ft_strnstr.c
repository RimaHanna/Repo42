/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:58:22 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 19:35:10 by rhanna           ###   ########.fr       */
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
	if (!s1 && len == 0)
		return (NULL);
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

	char	*s1 = NULL;
	char	s2[] = "coucou";
	char	*res;
	char	*ft_res;

	res = strnstr(s1, s2, 0);
	if (!res)
		write(1, "str NULL\n", 9);
	else
		printf("%s\n", res);
	ft_res = ft_strnstr(s1, s2, 0);
	if (!ft_res)
		write(1, "ft NULL\n", 8);
	else
		printf("%s\n", ft_res);
	return 0;
}*/
