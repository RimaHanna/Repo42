#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_list
{
	int val;
	int val2;
	struct s_list *next;
}	t_list;


void	list_print(t_list *list)
{
	t_list *p;

	p = list;
	printf("list: \n");
	while (p)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
}
// Ajouter un element a la fin de la liste 
// Cette liste va seulement ajouter l'element, elle ne renvoie rien
// Pour ajouter cet element, elle a besoin de la liste et de l'element
// Maintenant on est seulement en train de preparer l'action
void	list_add_end(t_list **list_p, t_list *element)
{
	t_list **p;

	p = list_p;
	element->next = NULL;
	while (*p)
		p = &((*p)->next);
	*p = element;
}

// le debut de la liste
void	list_add_beginning(t_list **list, t_list *element)
{
	element->next = *list;
	*list = element;
}

// enlever le dernier element (head) de la liste et le retourner
t_list	*list_remove_end(t_list **list_ptr)
{
	t_list	*elt;
	t_list	**p;
	if (*list_ptr == NULL)
		return NULL;
	p = list_ptr;
	while ((*p)->next)
		p = &((*p)->next);
// ici, p est egale a l'avant denier next, donc c'est l'address du dernier element.
	elt = *p;
// p est le next de l'avant dernier element, on le met a NULL.
	*p = NULL;
	return (elt);
}

// enlever le premier element et le recuperer
t_list	*list_remove_start(t_list **list_ptr)
{
	t_list	*elt;
	if (!(*list_ptr))
		return NULL;
	elt = *list_ptr;
	list_ptr = &((*list_ptr)->next);
	return (elt);	
}

//swap on the last element and the one before
void	swap_elements(t_list **list_ptr)
{
	t_list	**p;
	t_list	**prev_p;
	t_list	*tmp;
// On doit avoir au moins 2 elements dans la liste
// check si le 1er element existe
	if (!(*list_ptr))
		return ;
// check si le 2eme element existe (si le 1er element reference un 2eme element)
	if (!((*list_ptr)->next))
		return ;
	p = list_ptr;
	prev_p = NULL;
	while ((*p)->next)
	{
		prev_p = p;
		p = &((*p)->next);
	}
	tmp = *prev_p;
	*prev_p = *p;
	(*p)->next = tmp;
	(tmp)->next = NULL;

}

int main()
{
	t_list *list;
	t_list *e1;
	t_list *e2;
	t_list *e3;


	list = NULL;

	e1 = (t_list *)malloc(sizeof(t_list));
	e1->val = 1;
	e1->next = NULL; 
	list_add_end(&list, e1);

	
	e2 = (t_list *)malloc(sizeof(t_list));
	e2->val = 2;
	e2->next = NULL; 
	list_add_end(&list, e2);

	e3 = (t_list *)malloc(sizeof(t_list));
	e3->val = 3;
	e3->next = NULL; 
	list_add_beginning(&list, e3);

	list_print(list);
	t_list *tmp; 
	tmp = list_remove_end(&list);
	printf("tmp: %d\n", tmp->val);

	list_print(list);
	list_add_beginning(&list, tmp);
	list_print(list);
	swap_elements(&list);
	list_print(list);

	free(e1);
	free(e2);
	free(e3);

	return 0;

}

