#include "minitalk.h"

void    ft_handler(int signal)
{
    static int  bit;
    static int  i;

    if (signal == SIGUSR1)
        i = i | (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main(int argc, char **argv)
{
    (void) argv;
    int pid;    
    struct sigaction sa;

    if (argc != 1)
    {
        ft_printf("\033[31mError: wrong format.\033[0m\n");
        ft_printf("Try: ./server\n");
        return (0);
    }
    pid = getpid();
    ft_printf("\033[33m%d\033[0m\n", pid);
    ft_printf("\033[34mWaiting for a message...\033[0m\n");
    sa.sa_handler = ft_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    while (argc == 1)
    {
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGUSR2, &sa, NULL);
        pause ();
    }
    return (0);
}