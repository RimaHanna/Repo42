#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>

// creating the structure for the stack

typedef struct s_list
{
	int	value;
	int	index;
	struct	s_list *next;
}	t_list;

// create the prototypes:
// UTILS:
// t_list.c
t_list	*ft_new_node(int data);
void	ft_list_add_front(t_list **stack, t_list *new);
t_list	*ft_list_last(t_list *head);
void	ft_list_add_last(t_list **stack, t_list *new);
int		ft_list_size(t_list *head);
void	ft_print_list(t_list *head);

// utils.c
void	ft_error(char *msg);
int	is_sorted(t_list **stack);
int	get_distance(t_list **stack, int index);

// SRC
// instruction.c
int	swap(t_list **stack);
int	sa(t_list **stack_a);
int	sb(t_list **stack_b);
int	ss(t_list **stack_a, t_list **stack_b);

int	push(t_list **stack_to, t_list **stack_from);
int	pa(t_list **stack_a, t_list **stack_b);
int	pb(t_list **stack_a, t_list **stack_b);

int	rotate(t_list **stack);
int	ra(t_list **stack_a);
int	rb(t_list **stack_b);
int	rr(t_list **stack_a, t_list **stack_b);

int	reverseRotate(t_list **stack);
int	rra(t_list **stack_a);
int	rrb(t_list **stack_b);
int	rrr(t_list **stack_a, t_list **stack_b);

// radix.c
void	radix_sort(t_list **stack_a, t_list **stack_b);

// simple.c
void	sort_5(t_list **stack_a, t_list **stack_b);
void	simple_sort(t_list **stack_a, t_list **stack_b);

// LIBFT
// ft_putendl_fd.c
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);



#endif
