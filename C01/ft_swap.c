#include <stdio.h>
void ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a;
	int b;

	a = 5;
	b = 8;
	ft_swap(&a, &b);
	printf("la valeur a est mtn: %d\n", a);
	printf("la valeur b est mtn: %d\n", b);
	return 0;
}
