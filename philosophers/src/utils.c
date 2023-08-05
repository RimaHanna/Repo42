#include "../include/philo.h"

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

void    print_message(t_data *data, int philo_id, char *message)
{
    uint64_t time;

    time = get_time() - get_starting_time(data);
    pthread_mutex_lock(&data->mutex_print_message);
    if (is_still_iterating(data))
    {
        printf("%s", MAGENTA_COLOR);
        printf("%lu %d %s\n", time, philo_id, message);
        printf("%s", RESET_COLOR);
    }
    pthread_mutex_unlock(&data->mutex_print_message);
}

void ft_log(t_data *data, char *msg)
{
    uint64_t time;

    time = get_time() - get_starting_time(data);
    printf("%lu %s\n", time, msg);
}