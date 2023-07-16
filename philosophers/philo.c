#include "philo.h"

//utils.c
int ft_atoi(char *str)
{
    int count;
    int result;
    int sign;

    count = 0;
    result = 0;
    sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
    if (str[count] == '-' || str[count] == '+')
    {
        if (str[count] == '-')
            sign = -1;
        count++;
    }
    while ('0' <= str[count] && str[count] <= '9')
    {
        result = result * 10 + str[count] - '0';  
        count++;
    }
    return (result * sign);
}

//parse.c
void    arguments_error_message()
{
    printf("\033[1;31mWRONG INPUT\033[0m\n");
    printf("\033[1;37mType 4 or 5 numerique arguments with spaces \033[0m");
    printf("\033[1;37mbetween them, in the following format: \033[0m\n\n");
    printf("\033[1;33mFirst argument should be between 1 and 200\033[0m\n");
    printf("\033[1;35mSecond, third & forth argument, 60 or above\033[0m\n");
    printf("\033[1;34mFifth argument above 0\033[0m\n\n");
}

//parse.c
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

//parse.c
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

//data_init.c
/* The lists of philosophers, forks and threads is not fixed in lenghth,
it is dynamic, it depends on the parameter of the programme, so we must
create it in malloc. Malloc can fail, so we test each malloc and we return
an error code different than 0 if one of them fails*/
int malloc_data(t_data *data)
{
    data->philos = malloc(sizeof(t_philo) * data->nb_of_philos);
    if (data->philos == NULL)
        return (MALLOC_ERROR);
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_of_philos);
    if (data->forks == NULL)
    {
        free(data->philos);
        return (MALLOC_ERROR);
    }
    data->philo_thread = malloc(sizeof(pthread_t) * data->nb_of_philos);
    if (data->philo_thread == NULL)
    {
        free(data->philos);
        free(data->forks);
        return (MALLOC_ERROR);
    }
    return (0);
}

//data_init.c
int mutex_data_init(t_data *data)
{
    if (pthread_mutex_init(&data->mutex_nb_of_philos, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_keep_iterating, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_eat, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_sleep, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_die, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_start, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_print, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    return (0);
}

//data_init.c
/* the initialization of these variables will definitly not generate an
exeption (error),the part that initialize the mutex and the part containing malloc CAN generate an error, so we 
seperated in another function, but if this function fails, we return
its error,
 else we return 0*/
/* data->nb_of_meals = -1 
we can choose that the value -1 or 0 or -5 or any invalid value means
there is no parameter for number of meals. We choose to use -1. In coding
for a variable that holds a number of things, 0 is usually an acceptable 
value. So usually we pick a negative value, simply -1.*/
int data_init(t_data *data, int ac, char **av)
{
    data->nb_of_philos = ft_atoi(av[1]);
    data->nb_of_meals = -1;
    if (ac == 6)
        data->nb_of_meals = ft_atoi(av[5]);
    data->nb_of_full_philos = 0;
    data->keep_iterating = true;
    data->time_to_die = (uint64_t) (ft_atoi(av[2]));
    data->time_to_eat = (uint64_t) (ft_atoi(av[3]));
    data->time_to_sleep = (uint64_t) (ft_atoi(av[4]));
    if (mutex_data_init(data) != 0)
        return (INVALID_MUTEX_INIT);
    if (malloc_data(data) != 0)
        return (MALLOC_ERROR);
    return (0);
}

// time.c
/* this function returns the number of milliseconds since 1/1/1970 00:00:00.000
until now, so the number is very big and it should be uint64 (unsigned 64 bit)
If the function gettimeofday fails (!= 0), we let the function
get_time return 0 to indicate a problem to its caller (uint so we cannot
return (-1)). The only case that gettimeofday can in fact return 0, is if
we set the date of the computer to 1/1/1970 00:00:00.000 and run the program.
We consider that this will never happen so it is okay to use 0 to indicate a 
problem */
uint64_t get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) != 0)
        return (0);
    return (tv.tv_sec * (uint64_t)1000 + (tv.tv_usec / 1000));
}

// eat.c
/* record the current time into last_eating_time
returns 1 if ok, 0 if failed.
*/
int    record_last_eating_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_last_eating_time);
    philo->last_eating_time = get_time();
    if (philo->last_eating_time == 0)
        return (0);
    pthread_mutex_unlock(&philo->mutex_last_eating_time);
    return (1);
}

// data_init.c
int philo_init(t_data *data)
{
    t_philo    *philos;
    int         i;

    i = 0;
    philos = data->philos;
    while(i < data->nb_of_philos)
    {
        philos[i].data = data;
        philos[i].id = i + 1;
        philos[i].nb_of_eated_meals = 0;
        philos[i].state = INACTIVE;
        if(pthread_mutex_init(&philos[i].mutex_state, NULL) != 0)
            return (INVALID_MUTEX_INIT);
        if(pthread_mutex_init(&philos[i].mutex_nb_of_eated_meals, NULL) != 0)
            return (INVALID_MUTEX_INIT);
        if(pthread_mutex_init(&philos->mutex_last_eating_time, NULL) != 0)
            return (INVALID_MUTEX_INIT);
        if(record_last_eating_time(&philos[i]) == 0)
            return (GETTIMEOFDAY_FAIL);
        i++;
    }
    return (0);
}

//philo.c
/* To manage the errors that MAY return from the init functions,
we catch the return value "ret" of each of these functions.
After calling each function, we check that ret == 0 to call the next function.
This way if one of the functions returns != 0, the following functions
will not be called.
The error returned by each function is a macro.
*/
int philosophers(int ac, char **av)
{
    t_data data;
    int ret;

    ret = data_init(&data, ac, av);
    if(ret == 0)
        ret = philo_init(&data);
    /*
    if(ret == 0)
        ret = something...
    */
    if(ret != 0)
        return ret;
    return (0);
}

//philo.c
int main(int argc, char **argv)
{
    int ret;
    ret = check_args(argc, argv);
    if(ret == 0)
        ret = philosophers(argc, argv);
    /*
    if(ret == 0)
        ret = something...
    */
    if(ret != 0)
    {
        arguments_error_message();
        return (ret);
    }
    printf("all good\n");
    return (0);
}