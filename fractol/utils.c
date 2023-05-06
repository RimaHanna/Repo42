#include "fractol.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] || s2[i]) && (i < n - 1))
		i++;
	if (s1[i] != s2[i] && (n != 0))
		return ((char)s1[i] - (char)s2[i]);
	return (0);
}

int	ft_str_equal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (s1[i] == '\0' && s2[i] == '\0');
}

static int	ft_isdigit(int value)
{
	if (value >= 48 && value <= 57)
	{
		return (1);
	}
	return (0);
}

int	is_number(char *s)
{
	int		dots;

	if (!s)
		return (0);
	dots = 0;
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			s++;
			continue ;
		}
		if (*s == '.')
			dots++;
		else
			return (0);
		if (dots > 1)
			return (0);
		s++;
	}
	return (1);
}