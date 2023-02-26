#include "push_swap.h"

/* The ft_new_node function creates a new node for the linked list and returns a pointer to the newly created node.
The function takes an integer value as a parameter and sets that value as the value of the newly created node.
It also sets the index to -1 and the next pointer to NULL*/
t_list	*ft_new_node(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if(!new)
		return (NULL);
	new->value = data;
	new->index = -1; // cause we don't know the assigned index yet
	new->next = NULL;// it represents the end of the linked list
					 /*This makes it easier to add more nodes to the linked list in the future,
					   as the code can simply change the next pointer of the last node
					   to point to the newly added node. */
	return (new);
}
/*
The ft_list_add_front function adds the specified node to the front of the linked list.
The function takes a pointer to the head of the linked list and a pointer to the new node as parameters.
The function sets the next pointer of the new node to the current head of the linked list and
makes the new node the head of the linked list by changing the value of the head pointer*/
void	ft_list_add_front(t_list **stack, t_list *new)
{
	// the new element will have its "next" pointing to the first element of the list, this first element is referenced by stack
	new->next = *stack; 
	// stack must reference the first element of the list. Now "new" is the first element of the list. 
	*stack = new;
}

/* The ft_lstlast function returns a pointer to the last node of the linked list.
The function takes the head of the linked list as a parameter and uses a loop to traverse the linked list until it reaches the end,
at which point it returns a pointer to the last node.
Head is a pointer, if we changed its value inside the function,it will also change outside the function, so we put the intial value of head in variable tmp, so we can change tmp as much as we want */
t_list	*ft_list_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while(tmp->next)
	{
		tmp = tmp->next;
		if(tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

/*The ft_list_add_last function adds the specified node to the end of the linked list.
The function takes a pointer to the head of the linked list and a pointer to the new node as parameters.
The function uses the ft_list_last function to find the last node of the linked list and
sets the next pointer of the last node to the new node.*/
void	ft_list_add_last(t_list **stack, t_list *new)
{
	t_list	*last;

	if (*stack)
	{
		last = ft_list_last(*stack);
		last->next = new;
		new->next = NULL;
	}
	else // if the list is empty no need to call the above function
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

/*The ft_lstsize function returns the size of the linked list, i.e., the number of nodes in the linked list.
The function takes the head of the linked list as a parameter and uses a loop to traverse the linked list,
counting the number of nodes as it goes.*/
int	ft_list_size(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	i = 0;
	tmp = head;
	while(tmp)
	{
		tmp = tmp-> next;
		i++;
	}
	return (i);
}

/*
The printList function is used to print the contents of the linked list.
The function takes the head of the linked list as a parameter and uses a loop to traverse the linked list,
printing the value of each node as it goes.*/

void	ft_print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while(tmp)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

