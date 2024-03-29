/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:45:00 by rhanna            #+#    #+#             */
/*   Updated: 2022/11/24 10:04:21 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return (c == '\r' || c == '\f' || c == '\n'
		|| c == ' ' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i]) && (ft_isdigit(str[i])))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
/*
int main(int argc, char **argv)
{
	(void)argc;
	printf("Atoi --> %i\n", atoi(argv[1]));
	printf("mon atoi --> %i\n", ft_atoi(argv[1]));
	return 0;
}
*/

/**
 * atoi is a function in the standard library of the C programming language
 * that allows you to convert a string of characters representing a number 
 * into an integer value of type int.
 * 
 * atoi does not perform any error checking, so if the input string is not a 
 * valid representation of an integer, the result of the function call will be undefined.
 * 
 * two plus or two minus aren't considered part of the number. 
 * 
 * We use long int because it is guaranteed to 
 * be able to store, at the very least, values that lie within the range of
 * -2147483647 and 2147483647.
*/