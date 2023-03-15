#include "push_swap.h"
/* A sorting for <= 5 numbers, we will be using algorithm for sorting 3 numbers, 4 and 5 numbers. Get_min function will get the smallest number in the list. Get_distance function will get the distance of thi number in order to see if we rotate or reverse rotate.*/


// we are excluding in this function the val which is passed as parameter/ val might be representing the top element

static int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int min;

	head = *stack;
	min = head->index;
	while(head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}	
	return (min);
}

static void	sort_3(t_list **stack_a)
{
	t_list *head;
	int min;
	int	next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	// first case > 0 / 2 / 1
	if ((head->index == min) && (head->next->index != next_min))
	{
		// ra: 2 / 1 / 0
		ra(stack_a);
		// sa: 1 / 2 / 0
		sa(stack_a);
		// rra 0 / 1 / 2
		rra(stack_a);
	}
	// second case: 1 / 0 / 2 ou 1 / 2 / 0
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	// last option: 2 / 1 / 0 ou 2 / 0 / 1 
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

/*The sort_4 function sorts a stack of four elements. It first finds the minimum value in the stack using the get_min function and calculates its distance from the top of the stack. Then it performs the necessary rotations to move the minimum value to the top of the stack. After that, it pushes the minimum value to the second stack and sorts the remaining three elements using the sort_3 function. Finally, it pushes the minimum value back to the first stack.*/
static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

/* The simple_sort function sorts a stack of any size using the previously defined sorting functions. It first checks if the stack is already sorted or if it has less than two elements. If yes, it returns. Otherwise, it checks the size of the stack and calls the appropriate sorting function.*/

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int size;

	if (is_sorted(stack_a) || ft_list_size(*stack_a) < 2)
		return ;
	size = ft_list_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
