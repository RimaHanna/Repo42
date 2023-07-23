#ifndef PHILO_H
# define PHILO_H

/* For functions: write / usleep / */
# include <unistd.h>

/* For functions: printf/ */
# include <stdio.h>

/* For functions: pthread_create / pthread_detach / pthread_join /
                    pthread_mutex_lock / pthread_mutex_unlock /
                    pthread_mutex_init / pthread_mutex_destroy*/
# include <pthread.h>

/* For functions: malloc / */
# include <stdlib.h>

/* Functions for manipulating strings: memset */
# include <string.h>

/* Functions for time_related operations: gettimeofday / */
# include <sys/time.h>

/* Functions to define integer types and to use the unsigned integer of 64 bits
unit64_t */
# include <stdint.h>

/* Library header file that provide a definition for the Boolean data in C*/
# include <stdbool.h>

/* Functions that doesn't require a library: free / */

/* Creating a macro with the value 1, so when the processor encouters the macro
"INVALID_ARGUMENT" in the code, it replaces it with the corresponding value before
the actual compilation takes place. */
# define INVALID_ARGUMENT 1

/* Creating a macro with the value 2, so when the processor encounters the macro
"MALLOC_ERROR" in the code, it replaces it with the corresponding value before
the actual compilation takes place. */
# define MALLOC_ERROR 2

/* Mutex initialisation error */
# define INVALID_MUTEX_INIT 3

/* gettimeofday failure */
# define GETTIMEOFDAY_FAIL 4

/* Failure in creating a thread*/
# define PTHREAD_CREATE_FAIL 5

/* define macro messages*/
# define TAKE_FORKS "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"


/* List of possible values for the state of a philosopher
    The state of a philoseopher will not be philo.state = 1
    It will be philo.state = s_state.sleeping
    This allows me to work with meaningful symbolic names instead of plain 
    integers, making my code more readable and easier to understand.
    Enumeration is used to define a list of constants (an unchangeable value)
    that can be assigned to a variable */
typedef enum e_state
{
    EATING = 0,
    SLEEPING = 1,
    THINKING = 2,
    DEAD = 3,
    FULL = 4,
    INACTIVE = 5
}t_state;

/* what do we need for each philosopher*/
/* pthread_mutex_fork: Access and lock each fork, so the type pthread_mutex_t 
allows synchronization and coordination between philosophers when accessing
these forks .*/
/* When we can have several entities accessing the same variable, we use
a mutex as a system of lock to make sure that only one entity can access that
variable at the one given time */
typedef struct s_philo
{
    t_state         state; //
    struct s_data   *data; //
    int             id;//
    int             nb_of_eated_meals; //nb_meals_had
    uint64_t        last_eating_time; // last_eat_time
    pthread_mutex_t *left_fork; // *left_f
    pthread_mutex_t *right_fork; // *right_f
    pthread_mutex_t mutex_state; //mut_state
    pthread_mutex_t mutex_nb_of_eated_meals; //mut_nb_meals_had
    pthread_mutex_t mutex_last_eating_time; //mut_last_eat_time;
}t_philo;

/* What do we need as data */
/* for the number of meals, we don't need a mutex for it, because the 
philosopher won't be affecting the data of another user while using it */
typedef struct s_data
{
    int             nb_of_philos; // nb_philos
    int             nb_of_meals; // nb_meals
    int             nb_of_full_philos; // nb_full_p
    bool            keep_iterating; 
    uint64_t        time_to_die; // die_time
    uint64_t        time_to_eat; // eat_time
    uint64_t        time_to_sleep; // sleep_time
    uint64_t        starting_time; //start_time
//    pthread_mutex_t mutex_nb_of_philos; // mut_nb_philos
    pthread_mutex_t mutex_keep_iterating; // mut_keep_iterating
    pthread_mutex_t mutex_time_to_eat; // mut_eat_time
    pthread_mutex_t mutex_time_to_sleep; // mut_sleep_time
    pthread_mutex_t mutex_time_to_die; // mut_die_time
    pthread_mutex_t mutex_starting_time; // mut_start_time
    pthread_mutex_t mutex_print_message; // mut_print
    pthread_t       monitor_all_alive; // monit_all_alive
    pthread_t       monitor_all_full; // monit_all_full
    struct s_philo  *philos;
    pthread_mutex_t *forks;
    pthread_t       *philo_thread; // *philo_ths
}t_data;

//print_message.c
void    print_message(t_data *data, int philo_id, char *message);

//utils.c
int ft_atoi(char *str);

//data_init.c
int malloc_data(t_data *data);
int mutex_data_init(t_data *data);
int data_init(t_data *data, int ac, char **av);
int philo_init(t_data *data);
int fork_init(t_data *data);


//time.c
uint64_t get_time(void);
void    ft_usleep(uint64_t sleep_time);
int ft_min(int a, int b);

//state.c
void    set_philo_state(t_philo *philo, t_state state);
t_state get_philo_state(t_philo *philo);
int    philo_died(t_philo *philo);


//locks.c
int    record_last_eating_time(t_philo *philo);
bool    is_still_iterating(t_data *data);
void    set_if_keep_iterating(t_data *data,bool set_to);

//get_action_time.c
uint64_t    get_eat_time(t_data *data);
uint64_t    get_sleep_time(t_data *data);
uint64_t    get_die_time(t_data *data);
uint64_t    get_last_eating_time(t_philo *philo);
uint64_t    get_starting_time(t_data *data);

//actions.c
int take_forks(t_philo *philo);
int eat(t_philo *philo);

//routine.c
void    *philo_thread_routine(void *philo_p);


//parce.c
void    arguments_error_message();
int check_numerics(int argc, char **argv);
int check_args(int ac, char **av);

//lockforks.c
int take_left_fork(t_philo *philo);
void    drop_left_fork(t_philo *philo);
int take_right_fork(t_philo *philo);
void    drop_right_fork(t_philo *philo);

int handle_one_philo(t_philo *philo);

//philo.c
int create_run_threads(t_data *data);
int philosophers(int ac, char **av);
int main(int argc, char **argv);


#endif