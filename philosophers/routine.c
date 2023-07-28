#include "philo.h"


// NOTIFY_ALL_PHILOS (missing)

/* All functions called from create_run_threads in philo.c*/

/*
Start of the philo routine.
The routine function receives a void pointer as its argument, which 
is cast to the type t_philo*
We nominate this void pointer philo_p as p represent a pointer
 */
void    *philo_thread_routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo*) philo_p;
    record_last_eating_time(philo);
    while (get_philo_state(philo) != DEAD) // keep iterating
    {
        if (eat_action(philo) != 0)
        {
            usleep(100);
            continue;
        }
        sleep_action(philo);
        think_action(philo);
    }
    return (NULL);
}

/* 
is_still_iterating indicates if the simulation is still on going or not
We check each philo if it is dead, if we find one we set is_still_iterating
to false, and we break out of while.
After checking each philo, we repeat checking all philos again, until the
simulation must stop (infinite loop)) 
*/
void    *philos_are_alive_routine_check(void *data_p)
{
    t_philo *philos;
    t_data *data;
    int i;

    data = (t_data *)data_p;
    philos = data->philos;
    i = 0;
    while (i < data->nb_of_philos && is_still_iterating(data))
    {
        if (philo_died(&philos[i]) != 0 && is_still_iterating(data))
        {
            print_message(data, philos[i].id, DIED);
            set_if_keep_iterating(data, false);
            break;
        }
        if (i == data->nb_of_philos - 1)
            i = -1;
        usleep(500);
        i++;
        }
    return (NULL);
}

void    *philos_are_full_routine_check(void *data_p)
{
    t_data *data;
    int i;

    data = (t_data *)data_p;
    i = 0;
    while (i < data->nb_of_philos && is_still_iterating(data))
    {
        usleep(1000);
        if (is_philo_full(data, &data->philos[i]) == 0)
            i = -1;
        i++;
    }
    if (is_still_iterating(data) == true)
    {
        ft_log(data, "philos_are_full_routine_check set_if_keep_iterating(data, false)");
        set_if_keep_iterating(data, false);
    }
    return (NULL);
}   