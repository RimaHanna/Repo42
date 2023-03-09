
void	ft_lstclear(t_list **lst, void (*del)(void*))i
{
	t_list *tmp;
	
	if (!lst)
		return (NULL);
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdone(*lst, del);
		*lst = tmp;
	}
}
