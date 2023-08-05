#include "../include/philo.h"

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

/* 
This function returns the number of milliseconds since 1/1/1970 00:00:00.000
until now, so the number is very big and it should be uint64 (unsigned 64 bit)
If the function gettimeofday fails (!= 0), we let the function
get_time return 0 to indicate a problem to its caller (uint so we cannot
return (-1)). The only case that gettimeofday can in fact return 0, is if
we set the date of the computer to 1/1/1970 00:00:00.000 and run the program.
We consider that this will never happen so it is okay to use 0 to indicate a 
problem 
*/
uint64_t get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) != 0)
        return (0);
    return (tv.tv_sec * (uint64_t)1000 + (tv.tv_usec / 1000));
}