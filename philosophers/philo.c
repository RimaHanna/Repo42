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

//data_init.c
/* the initialization of these variables will definitly not generate an
exeption (error),the part that initialize the mutex and the part containing 
malloc CAN generate an error, so we seperated in another function, but if this
 function fails, we return its error, else we return 0*/
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

// locks.c
bool    is_still_iterating(t_data *data)
{
    bool    keep_iterating;
    pthread_mutex_lock(&data->mutex_keep_iterating);
    keep_iterating = data->keep_iterating;
    pthread_mutex_unlock(&data->mutex_keep_iterating);
    return (keep_iterating);
}

// locks.c
void set_if_keep_iterating(t_data *data, bool set_to)
{
    pthread_mutex_lock(&data->mutex_keep_iterating);
    data->keep_iterating = set_to;
    pthread_mutex_unlock(&data->mutex_keep_iterating);
}

//print_message.c
void    print_message(t_data *data, int philo_id, char *message)
{
    uint64_t time;

    time = get_time() - get_starting_time(data);
    pthread_mutex_lock(&data->mutex_print_message);
    if (is_still_iterating(data))
        printf("%lu %d %s\n", time, philo_id, message);
    pthread_mutex_unlock(&data->mutex_print_message);
}

//time.c
int ft_min(int a, int b)
{
    if (a < b)
        return (a);
    return (b);
}

/*
We use usleep() to tell the thread to wait for a certain time before doing an
operation, for example, we wait time_to_die before the philo dies. But usleep()
stops all executions of the thread. So if the philo eats while the thread is 
sleeping, we cannot send a message to the thread to inform it that the philo 
should not die.
So we split the total sleeping time into a succession of smaller sleeping times,
between these small sleeping times, the thread is able to receive external 
notifications.
We choose each small sleeping time to be 500ms. If the remaining time is < 500,
the thread will only sleep the remaining time.
*/
//time.c
void    ft_usleep(uint64_t sleep_time)
{
    uint64_t start;

    start = get_time();
    while ((get_time() - start) < sleep_time)
    {
        usleep(ft_min(500, get_time() - start));
    }
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

// locks.c
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

// data_init.c
/* initializing the forks used by the philosophers by initializing 
the mutexes representing the forks and establishing the correct 
pairing of forks for each philosopher in a circular table 
arrangement.*/
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

//locks.c
/*the get_nb_philos is used in the function create_run_threads, 
the data->nb_of_philos will be will be accessed by many thread, 
in order to have a proper synchronization and to safe access to 
the nb_of_philos, we use a mutex_lock, otherwize the shared nb_of_philos data 
without protection could lead to data races, inconsistent values, or other 
undefined behavior.
*/
/* this code might not be needed since nb_of_philos should not be accessed 
by many philos */
/*
int get_nb_of_philos(t_data *data)
{
    int nb_philos;

    pthread_mutex_lock(&data->mutex_nb_of_philos);
    nb_philos = data->nb_of_philos;
    if (nb_philos < 1)
        return (INVALID_ARGUMENT);
    pthread_mutex_unlock(&data->mutex_nb_of_philos);
    return (nb_philos);
}
*/
// state.c
t_state get_philo_state(t_philo *philo)
{
    t_state state;

    pthread_mutex_lock(&philo->mutex_state);
    state = philo->state; 
    pthread_mutex_unlock(&philo->mutex_state);
    return (state);
}

// state.c
void    set_philo_state(t_philo *philo, t_state state)
{
    pthread_mutex_lock(&philo->mutex_state);
    if (philo->state != DEAD)
        philo->state = state;
    pthread_mutex_unlock(&philo->mutex_state);
}

// 1 = died / 0 = alive
// state.c
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

/*-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
------------------------------------------------------------------------------*/

/* Codes registered but not done
philos_alive_routine_check
philos_full_routine_check
 */

//philo.c
int handle_one_philo(t_philo *philo)
{
    take_left_fork(philo);
    ft_usleep(get_die_time(philo->data));
    set_philo_state(philo, DEAD);
    return (1);
}

// actions.c
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

// actions.c
int eat(t_philo *philo)
{
    if (take_forks(philo) != 0)
        return (1);
    set_philo_state(philo, EATING);
    print_message(philo->data, philo->id, EAT);
    record_last_eating_time(philo);
    // usleep_time_to_eat
    // upgrade_last_meal_time
    // upgrade_nb_of_meals
    // drop_forks
    return (0);
}

//routine.c
/*
Start of the philo routine.
The routine function receives a void pointer as its argument, which 
is cast to the type t_philo*
We nominate this void pointer philo_p as p represent a pointer
 */
void    *philo_thread_routine(void *philo_p)
{
    t_philo *philo;

    philo = (t_philo*)philo_p;
    record_last_eating_time(philo);

    while (get_philo_state(philo) != DEAD) // keep iterating
    {
        conditions:
        if (eat(philo) != 0)
            break;
        if (get_philo_state(philo) == DEAD)
            break;
        // sleep;
        // get_philo_state
        // think

    }
    return (NULL);
}

//routine
void    *philos_alive_routine_check(void *philos_p)
{
    t_philo *philos;
    t_data *data;
    int i;

    philos = (t_philo *)philos_p;
    data = philos->data;
    i = 0;

    while (i < data->nb_of_philos && is_still_iterating(data))
    {
        if (philo_died(&philo[i] != 0) && get_philo_state(philo) != DEAD)
        {
            print_message(&data, philos[i].id, DIED);
            set_if_keep_iterating(data, false);
            //notify_other_philos(data);
            break;
        }
        if ()

        i++;
    }
}

//philo.c
/* 
In this function we will create the threads, on creating means running
immediatly
start_time will record the starting time of the simulation
*/
int create_run_threads(t_data *data)
{
    int i;
/*  int number_of_philos; // unusefull code

    number_of_philos = get_nb_of_philos(data);*/
    data->starting_time = get_time();
    i = 0;
    while (i < data->nb_of_philos)
    {
        if (pthread_create(&data->philo_thread[i], NULL,
                &philo_thread_routine, &data->philos[i]) != 0)
            return (PTHREAD_CREATE_FAIL);
        if (pthread_create(&data->monitor_all_alive, NULL,
                &philos_alive_routine_check, data) != 0)
            return (PTHREAD_CREATE_FAIL);
        if (pthread_create(&data->monitor_all_full, NULL,
                    &philos_full_routine_check, data) != 0)
            return (PTHREAD_CREATE_FAIL);
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
    if (ret == 0)
        ret = fork_init(&data);
    if (ret == 0)
        ret = create_run_threads(&data);
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