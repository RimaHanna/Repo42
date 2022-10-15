#include <unistd.h>
void ft_put_digit(char c)
{
	c = c + '0';
	write (1, &c, 1);
}

void ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	while (a < 10)
	{
		b = a + 1;
		while (b < 10)
		{
			c = b + 1;
			while (c < 10)
			{
				ft_put_digit(a);
				ft_put_digit(b);
				ft_put_digit(c);
				if (a != 7 || b != 8 || c != 9)
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
	write(1, "\n", 1);
}

int main()
{
	ft_print_comb();
	return 0;
}
