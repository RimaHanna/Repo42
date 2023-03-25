#include "push_swap.h"
#include <stdio.h>

static int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r'
				|| c == '\t' || c == '\v' || c == ' ');
}

static int ft_is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *s)
{
	unsigned int	i;
	long			res;
	int				sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(s[i]))
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

long int	ft_long_atoi(const char *s)
{
	unsigned int	i;
	long			res;
	int				sign;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(s[i]))
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
