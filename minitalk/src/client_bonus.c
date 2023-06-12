#include "minitalk_bonus.h"

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

void    ft_send_int(int pid, int n)
{
    int bit;

    bit = 0;
    while (bit < 32)
    {
        if ((n & (0x00000001 << bit)) != 0)
        {
            kill(pid, SIGUSR1);
        }
        else
        {
            kill(pid, SIGUSR2);
        }
        usleep(100);
        bit++;
    }
}

void    ft_handler(int signal)
{
    if (signal == SIGUSR1)
    {
        ft_printf("\033[33mReply received\033[0m\n");
        exit (0);
    }
}

void    check_arguments(int ac, char *str1, char *str2)
{
    int pid;
    int i;
    int self_pid;

    i = 0;
    if (ac == 3)
    {
        pid = ft_atoi(str1);
        while (str2[i])
        {
            ft_send_bits(pid, str2[i]);
            i++;
        }
        ft_send_bits(pid, '\n');
        // get client pid
        self_pid = getpid();
        // send clientPId to server after the message + \n
        ft_send_int(pid, self_pid);
    }
    else
    {
        ft_printf("\033[31mError: wrong format.\033[0m\n");
        ft_printf("Try: ./client <PID> <Message>\n");
        exit (1);
    }
}

int main(int argc, char **argv)
{
//    int pid;
//    int i;
//    int self_pid;
    struct sigaction sa;

//    i = 0;
    check_arguments(argc, argv[1], argv[2]);
    // if (argc == 3)
    // {
    //     pid = ft_atoi(argv[1]);
    //     while (argv[2][i])
    //     {
    //         ft_send_bits(pid, argv[2][i]);
    //         i++;
    //     }
    //     ft_send_bits(pid, '\n');
    //     // get client pid
    //     self_pid = getpid();
    //     // send clientPId to server after the message + \n
    //     ft_send_int(pid, self_pid);
    // }
    // else
    // {
    //     ft_printf("\033[31mError: wrong format.\033[0m\n");
    //     ft_printf("Try: ./client <PID> <Message>\n");
    //     return (1);
    // }
    // boucle while that waits for a signal
    sa.sa_handler = ft_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    while (argc == 3)
    {
        ft_printf("\033[32mWaiting for reply...\033[0m\n");
        // when signal is received, break; from the while
        sigaction(SIGUSR1, &sa, NULL);
        pause ();
    }
    return (0);
}