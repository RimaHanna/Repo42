/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:01:18 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/29 19:34:53 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	while (i < n)
	{
	((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*int main()
{
	char dest[] = "rima hanna";
	char *src = dest + 2;
	int n = 0;
	ft_memcpy(dest, src, n);
	printf("%s.\n", dest);

	char dest1[] = "rima hanna";
	char *src1 = dest1 + 2;
	memcpy(dest1, src1, n);
	printf("%s.\n", dest1);

	write(1, "mem\n", 4);
	memcpy(NULL, NULL, 3);
	write(1, "ft_mem\n", 7);
	ft_memcpy(NULL, NULL, 3);
	return 0; 
}*/
