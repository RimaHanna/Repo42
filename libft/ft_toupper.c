/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:02:27 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/14 17:05:46 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int main()
{
	char r = 'A';
	int ret = ft_toupper(r);
	printf("%d\n", ret);

	int ret1 = toupper(r);
	printf("%d\n", ret1);
	return 0;
}
*/

