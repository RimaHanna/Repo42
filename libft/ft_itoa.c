#include <stdio.h>
#include <stdlib.h>

int	ft_nb_of_digit(int n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	i++;
	return i;
}

char	*ft_nb_to_str(int n, int negative, int size, int div)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + negative + 1));
	if (!str)
		return (NULL);
	if (negative)
		str[i] = '-';
	i += negative;
	while (div / 10 != 0)
	{
		str[i] = (n / div) + '0';
		n = n % div;
		div = div / 10;	
		i++;		
	}
	str[i] = n + '0';
	i++;
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	int 	div;
	int 	negative;

	negative = n < 0;
	div = 1;
	if (negative)
		n = -n;
	size = ft_nb_of_digit(n);
	while (size-- > 1)
		div = div * 10;
	return (ft_nb_to_str(n, negative, size, div));
}

int main()
{
	int n = -1234;
	char *ret = ft_itoa(n);
	printf("string: %s\n", ret);

		return 0;
}
