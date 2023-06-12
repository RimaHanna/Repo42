#include "minitalk_bonus.h"

int    ft_handler_pid(int signal)
{
    static int bit;
    static int client_pid;

    if (signal == SIGUSR1)
        client_pid = client_pid | (0x00000001 << bit);
    bit++;
    if (bit == 32)
    {
        // send signal back to client
        usleep(1000);
        kill(client_pid, SIGUSR1);
        bit = 0;
        client_pid = 0;
        return 0;
    }
    return 1;
}

void    ft_handler(int signal)
{
    static int  bit;
    static int  i;
    static int is_client_pid;

    if(is_client_pid == 1)
    {
        is_client_pid = ft_handler_pid(signal);
        return ;
    }
    if (signal == SIGUSR1)
        i = i | (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        if(i == '\n')
            is_client_pid = 1;
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