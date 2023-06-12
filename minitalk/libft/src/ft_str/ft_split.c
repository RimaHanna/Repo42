/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:16:36 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 18:34:14 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/* count the number of words in the first fonction*/
/* in the second fonction:
call the first fonction and create malloc
 - while running the string:
	1- detect the beginning of each word
	2- have the number of caracteres in each word
	3- put in split the fonction char *ft_substr
		 creating a malloc for each string */
size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	strcount;

	i = 0;
	strcount = 0;
	while (s[i])
	{
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			strcount++;
		i++;
	}
	return (strcount);
}

size_t	ft_calculate_len(const char *s, char c, size_t i, size_t len)
{
	if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
		len = 0;
	if (s[i] != c)
		len++;
	return (len);
}

char	**ft_fill_split(char **split, const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;
	size_t	start;

	i = 0;
	count = 0;
	start = 0;
	len = 0;
	while (s[i])
	{
		len = ft_calculate_len(s, c, i, len);
		if ((s[i] != c) && ((i == 0) || (s[i - 1] == c)))
			start = i;
		if (((s[i] == c) || (s[i + 1] == '\0')) && (len > 0))
		{
			split[count++] = ft_substr(s, start, len);
			len = 0;
		}		
		i++;
	}	
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	count;
	size_t	i;

	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	split = ft_fill_split(split, s, c);
	i = 0;
	while (i < count)
	{
		if (!split[i])
			split[i] = "";
		i++;
	}
	split[count] = NULL;
	return (split);
}
/*
int main()
{
	int i = 0;
	char **str = ft_split("  tripouille  42  ", ' ');
	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
	return 0;
}
*/
