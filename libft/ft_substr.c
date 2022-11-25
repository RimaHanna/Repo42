/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:53:23 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:53:33 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dup;

	i = 0;
	j = 0;
	while (s[start + i] && j < len)
	{
		i++;
		j++;
	}
	dup = (char *)malloc(sizeof(char) * (j + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup[i] = s[start + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int main()
{
	char str[] = "rima hanna";
	int start = 4;
	int size = 15;
	char *dup = ft_substr(str, start, size);
	printf("dup: %s\n", dup);
	return 0;
}
*/
