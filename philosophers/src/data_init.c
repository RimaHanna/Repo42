#include "../include/philo.h"

/* 
The lists of philosophers, forks and threads is not fixed in lenghth,
it is dynamic, it depends on the parameter of the programme, so we must
create it in malloc. Malloc can fail, so we test each malloc and we return
an error code different than 0 if one of them fails
*/
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

int mutex_data_init(t_data *data)
{
/*    if (pthread_mutex_init(&data->mutex_nb_of_philos, NULL) != 0)
        return (INVALID_MUTEX_INIT); */
    if (pthread_mutex_init(&data->mutex_keep_iterating, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_eat, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_sleep, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_time_to_die, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_starting_time, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    if (pthread_mutex_init(&data->mutex_print_message, NULL) != 0)
        return (INVALID_MUTEX_INIT);
    return (0);
}

/* 
The initialization of these variables will definitly not generate an
exeption (error),the part that initialize the mutex and the part containing 
malloc CAN generate an error, so we seperated in another function, but if this
function fails, we return its error, else we return 0
*/
/* 
data->nb_of_meals = -1 
we can choose that the value -1 or 0 or -5 or any invalid value means
there is no parameter for number of meals. We choose to use -1. In coding
for a variable that holds a number of things, 0 is usually an acceptable 
value. So usually we pick a negative value, simply -1.
*/
int data_init(t_data *data, int ac, char **av)
{
    data->nb_of_philos = ft_atoi(av[1]);
    data->keep_iterating = true;
    data->nb_of_meals = -1;
    if (ac == 6)
        data->nb_of_meals = ft_atoi(av[5]);
    data->nb_of_full_philos = 0;
    data->time_to_die = (uint64_t) (ft_atoi(av[2]));
    data->time_to_eat = (uint64_t) (ft_atoi(av[3]));
    data->time_to_sleep = (uint64_t) (ft_atoi(av[4]));
    if (mutex_data_init(data) != 0)
        return (INVALID_MUTEX_INIT);
    if (malloc_data(data) != 0)
        return (MALLOC_ERROR);
    return (0);
}

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
        if(pthread_mutex_init(&philos[i].mutex_last_eating_time, NULL) != 0)
            return (INVALID_MUTEX_INIT);
        if(record_last_eating_time(&philos[i]) == 0)
            return (GETTIMEOFDAY_FAIL);
        i++;
    }
    return (0);
}

/* 
initializing the forks used by the philosophers by initializing 
the mutexes representing the forks and establishing the correct 
pairing of forks for each philosopher in a circular table 
arrangement.
*/
int fork_init(t_data *data)
{
    int i;
    t_philo *philos;

    i = 0;
    philos = data->philos;
    while (i < data->nb_of_philos)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    philos[0].left_fork = &data->forks[0];
    philos[0].right_fork = &data->forks[data->nb_of_philos - 1];
    i = 1;
    while (i < data->nb_of_philos)
    {
        philos[i].left_fork = &data->forks[i];
        philos[i].right_fork = &data->forks[i - 1];
        i++;
    }
    return (0);
}
