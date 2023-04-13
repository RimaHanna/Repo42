#include "push_swap.h"
#include <stdio.h>
#include <limits.h>

// cet fonction c'est pour etre sur que il n y a pas un nombre qui se repete 2 fois.
static int	is_double(int tmp, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == tmp)
			return (1);
		i++;
	}
	return (0);
}

// cet fonction c'est pour s'assurer que tous les arguments recus sont numerique.
static int	is_num(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!('0' <= argv[i] && argv[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_clean_exit(int argc, char **args, char *msg)
{
	if (argc == 2)
		ft_free(args);
	ft_error(msg);
}


// si je n'ai pas que 2 arguments le main et un autre (c a d que cet argument est donné tous dans un seul text séparé oar des espaces)/ je fais split pour cet argument, si non alors j'ai plusieurs arguments/ ensuite je fais le tests sur ces arguments, ou bien sur le truc qu on la fait split ou sur les autres arguments. a la fin, dans la fonction split on ne free pas c'est alors ou on appel cet fonction ft_free pour faire free.
void	ft_check_args(int argc, char **argv)
{
	char **args;
	int	i;
	long	tmp;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
	 	i = 1;
		args = argv;	
	}
//printf("argc> %d\n", argc);
	while (args[i] != NULL)
	{
//printf("i> %d\n", i);
		tmp = ft_long_atoi(args[i]);
//printf("tmp> %ld\n", tmp);
		if (!is_num(args[i]))
			ft_clean_exit(argc, args, "Error");
		if (is_double(tmp, args, i))
			ft_clean_exit(argc, args, "Error");
		if (tmp < INT_MIN || tmp > INT_MAX)
			ft_clean_exit(argc, args, "Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
