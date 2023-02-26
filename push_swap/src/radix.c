#include "push_swap.h"

// we are using index instead of values because the C operator >> will change the value of the number, so we reserve the number in value and index, and change the index.
// max_bits is the number of bits in one number, so we will finding the biggest one
// the C operator >> directly change the number to bits and shift to the right
// we will have 2 functions (one that will bring the max bits of the number)(the second radix.c will turn on all the numbers and put the one ending with 0 in stack_b )

static int get_max_bits(t_list **stack)
{
	t_list	*head;
	int	max_bits;
	int max;

	head = *stack;
	max = head->index;
	max_bits = 0;
	// we are bringing the highest number
	while(head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	// shifting max to the right until it reach zero, and with everyshift we increment max_bits
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int	i;
	int	j;
	int	lst_size;
	int	max_bits;

	head_a = *stack_a;
	i = 0;
	lst_size = ft_list_size(head_a);
	max_bits = get_max_bits(stack_a);
// if the last bits is equal to 1 we keep in stack_a else we push to b, when we check all the numbers followinf the size of the list and we end pushing to b/ we repush to a everything
	while(i < max_bits)
	{
		j = 0;
		while(j < lst_size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while(ft_list_size(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
