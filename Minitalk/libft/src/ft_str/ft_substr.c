/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:53:23 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 10:58:22 by rhanna           ###   ########.fr       */
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
	size_t	sizes;

	sizes = ft_strlen(s);
	i = 0;
	j = 0;
	while (((start + i) < sizes) && s[start + i] && j < len)
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
	char str[] = "tribouille";
	int start = 100;
	int size = 1;
	char *dup = ft_substr("tripouille", 100, 1);
	printf("dup:%s\n", dup);
return 0;
	printf("sizeofdup%ld\n", sizeof(dup));
	printf("sizeofchar:%ld\n", sizeof(char));
	char *s = "";
if (strcmp(dup, ""))
	printf("if\n");
else
	printf("else\n"); 
	return 0;
}
*/
