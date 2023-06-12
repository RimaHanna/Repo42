#include "minitalk.h"

void    ft_send_bits(int pid, char i)
{
    int bit;

    bit = 0;
    while (bit < 8)
    {
        if ((i & (0x01 << bit)) != 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        while (argv[2][i])
        {
            ft_send_bits(pid, argv[2][i]);
            i++;
        }
        ft_send_bits(pid, '\n');
    }
    else
    {
        ft_printf("\033[31mError: wrong format.\033[0m\n");
        ft_printf("Try: ./client <PID> <Message>\n");
    }
    return (0);
}