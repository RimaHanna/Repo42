#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*start;
	start = *lst;
	if (*lst == NULL)//If the list is empty, make 'new' the first element
		*lst = new;
	else
	{
		while(start->next)// Traverse the list to find the last element
			start = start->next;
		start->next = new;
	}
}
