#include "philo.h"

void    arguments_error_message()
{
    printf("\033[1;31mWRONG INPUT\033[0m\n");
    printf("\033[1;37mType 4 or 5 numerique arguments with spaces \033[0m");
    printf("\033[1;37mbetween them, in the following format: \033[0m\n\n");
    printf("\033[1;33mFirst argument (number of philosophers) \033[0m");
    printf("\033[1;33mshould be between 1 and 200\033[0m\n");
    printf("\033[1;35mSecond argument time_to die, 60 or above\033[0m\n");
    printf("\033[1;35mThird argument time_to eat, 60 or above\033[0m\n");
    printf("\033[1;35mForth argument time_to sleep, 60 or above\033[0m\n");
    printf("\033[1;34mFifth argument above 0\033[0m\n\n");

}

int check_numerics(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while(i < argc)
    {
        j = 0;
        while(argv[i][j])
        {
            if (argv[i][j] < '0' || argv[i][j] > '9')
                return (INVALID_ARGUMENT);
            j++;
        }
        i++;
    }
    return (0);
}

int check_args(int ac, char **av)
{
    if (ac != 5 && ac != 6)
        return (INVALID_ARGUMENT);
    if (check_numerics(ac, av) != 0)
        return (INVALID_ARGUMENT);
    if (ac == 6 && ft_atoi(av[5]) <= 0)
        return (INVALID_ARGUMENT);
    if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
        return (INVALID_ARGUMENT);
    if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
        return (INVALID_ARGUMENT);
    return (0);
}