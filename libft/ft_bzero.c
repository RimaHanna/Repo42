/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:07:54 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/14 12:28:58 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return ;
	i = 0;
	str = (unsigned char *)s;
	while (str[i] && i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
int main()
{
	char str[] = "rima hanna";
	int i = 5;
	ft_bzero(str, i);
	printf("%s\n", str);

	char str1[] = "rima hanna";
	bzero(str1, i);
	printf("%s\n", str1);
	return 0;
}
*/
