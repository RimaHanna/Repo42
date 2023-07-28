#include "philo.h"

int take_forks(t_philo *philo)
{
    if (philo->data->nb_of_philos == 1)
        return (handle_one_philo(philo));
    if (philo->id % 2 == 0)
    {
        if (take_right_fork(philo) != 0)
            return (1);
        if (take_left_fork(philo) != 0)
        {
            drop_right_fork(philo);
            return (1);
        }
    }
    else
    {
        if (take_left_fork(philo) != 0)
            return (1);
        if (take_right_fork(philo) != 0)
        {
            drop_left_fork(philo);
            return (1);
        }
    }
    return (0);
}

/*
Actions called form philo_thread_routine in routine.c
*/

int eat_action(t_philo *philo)
{
    if (take_forks(philo) != 0)
        return (1);
    set_philo_state(philo, EATING);
    print_message(philo->data, philo->id, EAT);
    record_last_eating_time(philo);
    ft_usleep(get_eat_time(philo->data));
    record_nb_of_eated_meals(philo);
    drop_both_forks(philo);
    return (0);
}

int sleep_action(t_philo *philo)
{
    set_philo_state(philo, SLEEPING);
    if (get_philo_state(philo) == DEAD)
        return (1);
    print_message(philo->data, philo->id, SLEEP);
    ft_usleep(get_sleep_time(philo->data));
    return (0);
}

int think_action(t_philo *philo)
{
    set_philo_state(philo, THINKING);
    if (get_philo_state(philo) == DEAD)
        return (1);
    print_message(philo->data, philo->id, THINK);
    return (0);
}
