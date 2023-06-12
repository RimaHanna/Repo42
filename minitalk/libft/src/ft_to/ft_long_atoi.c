/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:45:00 by rhanna            #+#    #+#             */
/*   Updated: 2023/05/03 10:04:21 by rhanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *s, int i)
{
	char c = s[i];
	return (c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v' || c == ' ' 
		|| ((c == '0') && (s[i + 1] != '\0')));
}

static int ft_is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int ft_strlen_num(const char *s)
{
	int	i;
	int j;

	i = 0;
	while (ft_isspace(s, i))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	j = 0;
	while (ft_is_digit(s[i]))
	{
		i++;
		j++;
	}
	return j;
}

long int	ft_long_atoi(const char *s)
{
	unsigned int	i;
	long			res;
	int				sign;

	res = 0;
	if(ft_strlen_num(s) < 1 || ft_strlen_num(s) > 10)
		return ((long int)INT_MAX + 1);
	sign = 1;
	i = 0;
	while (ft_isspace(s, i))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && ft_is_digit(s[i]))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

/**
 * This function was used in the project push_swap, the aim of this function
 * was to allow the return of a number bigger of long int in order to assest in
 * and return on the output "error".
 * 
 * the added purpose of the added condition for ft_strlen_num > 10 , is to detect
 * that if the number is much bigger the long long int to return it to lont int, cause other 
 * wise it is returning a small number. 
*/