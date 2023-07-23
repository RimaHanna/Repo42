#include "philo.h"

int take_left_fork(t_philo *philo)
{
    if ((philo_died(philo) != 0) || (get_philo_state(philo) == DEAD))
        return (1); 
    pthread_mutex_lock(philo->left_fork);
    print_message(philo->data, philo->id, TAKE_FORKS);
    return (0);
}

void    drop_left_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->left_fork);
}

int take_right_fork(t_philo *philo)
{
    if ((philo_died(philo) != 0) || (get_philo_state(philo) == DEAD))
        return (1);
    pthread_mutex_lock(philo->right_fork);
    print_message(philo->data, philo->id, TAKE_FORKS);
    return (0);    
}

void    drop_right_fork(t_philo *philo)
{
    pthread_mutex_unlock(philo->right_fork);
}