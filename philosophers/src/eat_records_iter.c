#include "../include/philo.h"

void    record_nb_of_eated_meals(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_nb_of_eated_meals);
    philo->nb_of_eated_meals++;
    pthread_mutex_unlock(&philo->mutex_nb_of_eated_meals);
}

int get_nb_of_eated_meals(t_philo *philo)
{
    int nb_of_meals_had;
    pthread_mutex_lock(&philo->mutex_nb_of_eated_meals);
    nb_of_meals_had = philo->nb_of_eated_meals;
    pthread_mutex_unlock(&philo->mutex_nb_of_eated_meals);
    return (nb_of_meals_had);
}

bool    is_still_iterating(t_data *data)
{
    bool    keep_iterating;
    
    pthread_mutex_lock(&data->mutex_keep_iterating);
    keep_iterating = data->keep_iterating;
    pthread_mutex_unlock(&data->mutex_keep_iterating);
    return (keep_iterating);
}

void    set_if_keep_iterating(t_data *data, bool set_to)
{
    pthread_mutex_lock(&data->mutex_keep_iterating);
    data->keep_iterating = set_to;
    pthread_mutex_unlock(&data->mutex_keep_iterating);
}

/* 
Record the current time into last_eating_time
*/
// returns 1 if ok, 0 if failed.
int record_last_eating_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex_last_eating_time);
    philo->last_eating_time = get_time();
    if (philo->last_eating_time == 0)
        return (0);
    pthread_mutex_unlock(&philo->mutex_last_eating_time);
    return (1);
}