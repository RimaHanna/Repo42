#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0); //it is used to immediately terminate the program if an error occurs
}


int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while(head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_list **stack, int index)
{
	t_list *head;
	int distance;

	head = *stack;
	distance = 0;
	while(head)
	{
		if (head->index == index)
			break;
		distance++;
		head = head->next;
	}
	return (distance);
}

// c'est une array de string, on voit la taille de cette array de string, puis on fait free pour chaque element
void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}


