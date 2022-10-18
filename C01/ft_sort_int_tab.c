#include <stdio.h>
void ft_sort_int_tab(int *tab, int size)
{
	int i = 0;
	int temp;
	int j;
	while(i < size)
	{
		j = i + 1;
		while (tab[j] < size - i)
		{
			if (tab[i] > tab[j])
				{
					temp = tab[i];
					tab[i] = tab[j];
					tab[j] = temp;
				}
			j++;
		}
		i++;
	}	
}

int main()
{
	int tab[] = {5, 3, 4, 2, 1, 7, 9};
	ft_sort_int_tab(tab, 7);
	int i = 0;
	while(i < 7)
	{
		printf("%d", tab[i]);
		i++;
	}
	return 0;
}
