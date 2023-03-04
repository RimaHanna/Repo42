#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*min;
	t_list	*head;
	int	has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || (head->value < min->value)))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}


void	index_stack(t_list	**stack)
{
	int	index;
	t_list	*head;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index;
		head = get_next_min(stack);
		index++;
	}
}
