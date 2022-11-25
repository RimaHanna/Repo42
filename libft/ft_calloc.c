/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:46:35 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 15:46:35 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (size > SIZE_MAX / nmemb)
		return (0);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int		main()
{
	char	*str;
	char	*str1;

	str = (char *)ft_calloc(30, sizeof(char));
	printf("str: %s\n", str);
	str1 = (char *)calloc(30, sizeof(char));
	printf("str1: %s\n", str1);
	return (0);
}
*/
