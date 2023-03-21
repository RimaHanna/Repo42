#include "push_swap.h"

// swap the first two elements (the head and the next)
int	swap(t_list **stack)
{
	t_list *head;
	t_list *next;
	int	tmp_val;
	int	tmp_index;

	if (ft_list_size(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head & !next)
		ft_error("Error while swapping");
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	//ft_print_list(*stack_a);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	//ft_print_list(*stack_b);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_list_size(*stack_a) < 2) || (ft_list_size(*stack_b) < 2))
		return (-1);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
//	ft_print_list(*stack_a);
//	ft_print_list(*stack_b);
	return (0);
}

// push the first element from the stack to the top of the other
int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_from;
	t_list	*head_to;

	if (ft_list_size(*stack_from) == 0)
		return (-1);
	head_from = *stack_from;
	head_to = *stack_to;

	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;

	// we will check if the stack_to is empty or not
	// if it is empty "tmp" becomes the new head of stack_to and is assigned to head_to
	// If stack_to is not empty, then tmp is added to the top of the stack by setting its next pointer to point to the previous top node, which is head_to.
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}


int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
//	ft_print_list(*stack_a);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
//	ft_print_list(*stack_b);
	return (0);
}
// the first element become the last
/* list->[a]->[b]->[c]->[d]->NULL
will become
list->[b]->[c]->[d]->[a]->NULL
*/
int	rotate(t_list **stack)
{
	t_list *head;
	t_list	*tail;

	if (ft_list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_list_last(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int ra(t_list **stack_a)
{
	if(rotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
//	ft_print_list(*stack_a);
	return (0);
}
	
int rb(t_list **stack_b)
{
	if(rotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
//	ft_print_list(*stack_b);
	return (0);
}

int rr(t_list **stack_a, t_list **stack_b)
{
	if((ft_list_size(*stack_a) < 2) || (ft_list_size(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
// the last element become the first
/* list->[a]->[b]->[c]->[d]->NULL
will become
list[d]->[a]->[b]->[c]->NULL
*/

int reverseRotate(t_list **stack)
{
	t_list *head;
	t_list *tail;

	if (ft_list_size(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_list_last(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int rra(t_list **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
//	ft_print_list(*stack_a);
	return (0);
}

int rrb(t_list **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
//	ft_print_list(*stack_b);
	return (0);
}

int rrr(t_list **stack_a, t_list **stack_b)
{
	if((ft_list_size(*stack_a) < 2) || (ft_list_size(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
