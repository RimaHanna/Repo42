#include "philo.h"

// get_action_time.c
uint64_t get_eat_time(t_data *data)
{
    uint64_t eat_time;

    pthread_mutex_lock(&data->mutex_time_to_eat);
    eat_time = data->time_to_eat;
    pthread_mutex_unlock(&data->mutex_time_to_eat);
    return (eat_time);
}

// get_action_time.c
uint64_t    get_sleep_time(t_data *data)
{
    uint64_t sleep_time;

    pthread_mutex_lock(&data->mutex_time_to_sleep);
    sleep_time = data->time_to_sleep;
    pthread_mutex_unlock(&data->mutex_time_to_sleep);
    return (sleep_time);
}

// get_action_time.c
uint64_t get_die_time(t_data *data)
{
    uint64_t die_time;

    pthread_mutex_lock(&data->mutex_time_to_die);
    die_time = data->time_to_die;
    pthread_mutex_unlock(&data->mutex_time_to_die);
    return (die_time);
}

// get_action_time.c
uint64_t get_last_eating_time(t_philo *philo)
{
    uint64_t last_eat_time;

    pthread_mutex_lock(&philo->mutex_last_eating_time);
    last_eat_time = philo->last_eating_time;
    pthread_mutex_unlock(&philo->mutex_last_eating_time);
    return (last_eat_time);
}

// get_action_time.c
uint64_t get_starting_time(t_data *data)
{
    uint64_t get_start_time;

    pthread_mutex_lock(&data->mutex_starting_time);
    get_start_time = data->starting_time;
    pthread_mutex_unlock(&data->mutex_starting_time);
    return (get_start_time);
}