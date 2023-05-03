/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:51:12 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 14:12:05 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}	
	return (0);
}
/*
int main()
{
	char str[] = "rimahnaa";
	char c = 'm';
	int n = 4;
	char *s = memchr(str, c, n);
	display(s);
	s = ft_memchr(str, c, n);
	display(s);
	return 0;
} */

/**
 * memchr searches for the first occurrence of a specific 
 * character in a block of memory. 
 * 
 * The implementation of memchr starts by initializing a counter i to
 * zero and a pointer str to the memory location s. 
 * It then enters a loop that iterates over the first n bytes of 
 * the memory block, checking each byte to see if it matches the character c.
 * If a match is found, the function returns a pointer to the matching byte,
 * cast to a void pointer. If no match is found within the first n bytes,
 * the function returns NULL.
 * */