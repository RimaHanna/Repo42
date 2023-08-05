#include "../include/philo.h"

t_state get_philo_state(t_philo *philo)
{
    t_state state;

    pthread_mutex_lock(&philo->mutex_state);
    state = philo->state; 
    pthread_mutex_unlock(&philo->mutex_state);
    return (state);
}

void    set_philo_state(t_philo *philo, t_state state)
{
    pthread_mutex_lock(&philo->mutex_state);
    if (philo->state != DEAD)
        philo->state = state;
    pthread_mutex_unlock(&philo->mutex_state);
}

// 1 = died / 0 = alive
int    philo_died(t_philo *philo)
{
    t_data *data;

    data = philo->data;
    if (get_time() - get_last_eating_time(philo) > get_die_time(data)
            && get_philo_state(philo) != EATING)
    {
        set_philo_state(philo, DEAD);
        return (1);
    }
    return (0);
}

// 1 = full / 0 = not
int is_philo_full(t_data *data, t_philo *philo)
{
    if (get_nb_of_eated_meals(philo) >= data->nb_of_meals)
    {
        return (1);
    }
    return (0);
}
