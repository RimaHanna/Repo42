#include "../include/philo.h"

int handle_one_philo(t_philo *philo)
{
    take_left_fork(philo);
    ft_usleep(get_die_time(philo->data), philo->data);
    set_philo_state(philo, DEAD);
    return (1);
}

/* 
In this function we will create the threads, on creating means running
immediatly
start_time will record the starting time of the simulation
*/
    int create_run_threads(t_data *data)
{
    int i;

    data->starting_time = get_time();
    i = 0;
    while (i < data->nb_of_philos)
    {
        if (pthread_create(&data->philo_thread[i], NULL,
                &philo_thread_routine, &data->philos[i]) != 0)
            return (PTHREAD_CREATE_FAIL);
    
        i++;
    }
    if (pthread_create(&data->monitor_all_alive, NULL,
                &philos_are_alive_routine_check, data) != 0)
            return (PTHREAD_CREATE_FAIL);
    if ((data->nb_of_meals > 0) && 
            (pthread_create(&data->monitor_all_full, NULL,
                &philos_are_full_routine_check, data) != 0))
            return (PTHREAD_CREATE_FAIL);
    return (0); 
}

int join_threads(t_data *data)
{
    int i;

    i = 0;
    if (pthread_join(data->monitor_all_alive, NULL))
        return (1);
    if ((data->nb_of_meals > 0) && (pthread_join(data->monitor_all_full, NULL)))
        return (1);
    while (i < data->nb_of_philos)
    {
        ft_log(data, "join_threads l: 51");
        printf("data->philo_thread[%d]\n", i);
        if (pthread_join(data->philo_thread[i], NULL))
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int free_data(t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->nb_of_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philos[i].mutex_state);
        pthread_mutex_destroy(&data->philos[i].mutex_nb_of_eated_meals);
        pthread_mutex_destroy(&data->philos[i].mutex_last_eating_time);
        i++;
    }
    pthread_mutex_destroy(&data->mutex_keep_iterating);
    pthread_mutex_destroy(&data->mutex_time_to_eat);
    pthread_mutex_destroy(&data->mutex_time_to_sleep);
    pthread_mutex_destroy(&data->mutex_time_to_die);
    pthread_mutex_destroy(&data->mutex_starting_time);
    pthread_mutex_destroy(&data->mutex_print_message);
    free(data->philos);
    free(data->forks);
    free(data->philo_thread);
    return (0);
}

/* 
To manage the errors that MAY return from the init functions,
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
    if (ret == 0)
        ret = fork_init(&data);
    if (ret == 0)
        ret = create_run_threads(&data);
    if (ret == 0)
        ret = join_threads(&data);
    if (ret == 0)
        ret = free_data(&data);
    if(ret != 0)
        return ret;
    return (0);
}

int main(int argc, char **argv)
{
    int ret;

    ret = check_args(argc, argv);
    if(ret == 0)
        ret = philosophers(argc, argv);
    if(ret != 0)
    {
        arguments_error_message();
        return (ret);
    }
    return (0);
}