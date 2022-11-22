/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:06:03 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/14 17:08:43 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c <= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
int main()
{
	char r = 'a';
	int ret = ft_tolower(r);
	printf("%d\n", ret);

	int ret1 = tolower(r);
	printf("%d\n", ret1);
	return 0;
}*/

