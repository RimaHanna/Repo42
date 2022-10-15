#include <stdio.h>
void ft_ultimate_div_mod(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *a / *b;
	*b = temp % *b;
}

int main()
{
	int a = 6;
	int b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("a est %d\n", a);
	printf("b est %d\n", b);
	return 0;
}
