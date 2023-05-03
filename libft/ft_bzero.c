/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:07:54 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 15:05:13 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strings.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
int main()
{
	char str[] = "rima hanna";
	int i = 42;
	ft_bzero(str, i);
	printf("%s\n", str);

	char str1[] = "rima hanna";
	bzero(str1, i);
	printf("%s\n", str1);
	return 0;
}
*/

/**
 * ft_bzero is a function that sets a block of memory to zero. 
 * It is commonly used to clear out memory before initializing it with new data.
*/