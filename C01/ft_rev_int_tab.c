#include <stdio.h>
void ft_rev_int_tab(int *tab, int size)
{
	int i = 0;
	int temp;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}

}

int main()
{
	int i = 0;
	int tab[5] = {6, 5, 4, 3, 2};
	ft_rev_int_tab(tab, 5);
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return 0;


}
