/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:10:19 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/14 17:11:50 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On ne vérifie pas si s est NULL pour avoir le même comportement
 que la fonction strchar  qui donne une segmentation fault si s est NULL 

	if (s == NULL)
		return (0);
*/
#include <stddef.h>
#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char *)&s[i]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char *str = "rima";
	char c = 'x';
	char *dest = ft_strchr(str, c);
	if (dest)
		printf("%s\n", dest);
	else
		printf("null\n");
	char *test = strchr(str, c);
	if (test)
		printf("%s\n", test);
	else
		printf("NULL\n");
	return 0;
}
*/

