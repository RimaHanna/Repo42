#include "fractol.h"

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