#include <unistd.h>
void ft_put_digit(char c)
{
	c = c + '0';
	write(1, &c, 1);
}



void ft_print_alphabet(void)
{
	int i = 0;
	while (i < 10)
	{
		ft_put_digit(i);
		i++;
	}
	write(1, "\n", 1);
}

int main()
{
	ft_print_alphabet();
	return 0;
}
