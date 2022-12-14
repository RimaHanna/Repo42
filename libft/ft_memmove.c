/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:10:27 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 15:02:23 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}	
	return (dest);
}

/*
// !dest  cad il n y a pas d'address dans ce pointeur, il est null
int main()
{
	char dest[] = "rima hanna";
	char *src = dest + 2;
	int n = 5;
	ft_memmove(dest, src, n);
	printf("dest: %s, src: %s\n", dest, src);

	char dest1[] = "rima hanna";
	char *src1 = dest1 + 2;
	memmove(dest1, src1, n);
	printf("dest1: %s, src1: %s\n", dest1, src1);

	char dest2[] = "rima hanna";
	char *src2 = dest2 + 2;
	memcpy(dest2, src2, n);
	printf("dest2: %s, src2: %s\n", dest2, src2);

	char str1[] = "foo-bar";
	memmove(&str1[3],&str1[4],4); //fine	
	printf("str1: %s\n", str1);
	return 0;
}
*/
