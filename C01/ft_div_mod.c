#include <stdio.h>
void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main()
{
	int a = 6;
	int b = 3;
	int div; 
	int mod;
	ft_div_mod(a, b, &div, &mod);
	printf("div est %d\n", div);
	printf("mod est %d\n", mod);
	return 0;
}
