Vous devez réaliser un programme de communication sous la forme d’un client et
d’un serveur.

Le serveur doit être lancé en premier et doit, après le lancement,
afficher son PID.
    je dois:
        1-  Creer un fichier source exemple : server.c
        2-  Include les bibliotheques necessaires
        3-  Definissez la fonction main
        4-  Developper une fonction globale pour stocker le PID 
                ex: pid-t  server-pid
        5-  Creer une fonction de gestionnaire de signal pour chaque signal que je veux traiter
                ex: void    sigusr1_handler(int signum)
        6-  Dans la fonction main utiliser getpid() pour obtenir le PID du 
            serveur et stocker le variable
                ex: server-pid = getpid();
        7-  Associez les gestionnaires de signal aux signaux correspondants en 
            en utilisant la fonction (signal) ou (sigaction)
                ex: signal(SIGUSR1, sigusr1-handler)
        8-  Utilisez une boucle infini pour maintenir le serveur en cours d'execution
            Utiliser (pause) pour mettre le processus en attente jusqu'a la reception
            d'un signal.
        9- complier / executer

Explication de chaque fonction:

- sigemptyset: initializes the signal set given by set to empty, 
            with all signals excluded from the set.
                Return 0 on success and -1 on error.
- sigaddset: add signal signum from set
                Return 0 on success and -1 on error.
- sigaction: The sigaction() system call is used to change the action taken 
                by a process on receipt of a specific signal. 
- kill: La fonction kill() est utilisée pour envoyer un signal à un processus 
        spécifié par son ID de processus (PID)
        int kill(pid_t pid, int sig);
- getpid: La fonction getpid() ne prend aucun paramètre. 
          Elle renvoie le PID du processus qui l'appelle en tant que valeur de retour.
- Pause: La fonction pause() est utilisée pour suspendre l'exécution d'un 
         processus jusqu'à ce qu'un signal soit reçu. 
- Sleep: La fonction sleep() prend en paramètre le nombre de secondes pendant
         lesquelles le processus doit être suspendu. Après le délai spécifié,
         le processus reprend son exécution à partir du point où il s'était arrêté.

Le client prend deux paramètres :
◦ Le PID du serveur.
◦ Une chaîne de caractères à transmettre.
1- on creer un programme pour le client qui prend deux parametre
    le pid du serveur et une chaine de caractere a transmettre

Le client doit communiquer au serveur la chaîne passée en paramètre.
Une fois la chaîne entièrement reçue, le serveur doit l’afficher.

Le serveur doit être capable d’afficher la chaîne rapidement. Par rapidement, on
entend que si vous pensez que c’est trop long, alors c’est sûrement trop long.

Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans
nécessiter d’être relancé.

La communication entre vos programmes doit se faire uniquement à l’aide de
signaux UNIX.

Vous ne pouvez utiliser que les deux signaux suivants : SIGUSR1 et SIGUSR2.

the function ft_handler in server.c:
{
    it is receiving signals from client (SIGUSR1 or 2)
    it will receive a character which is one byte (8 bits)
    each signal (SIGUSR1 or 2) will be one bit
    at start i contains 0.
    if SIGUSR1 is received it means bit 0, so we advance to the next bit.
    if SIGUSR2 is received it means bit 1, we mark it in i (i | (0x01 << bit)) and
    we advance to the next bit
    static int i and static int bit means they retain their value between calls.
    By default, static variables are initialized to 0.  
}

the function ft_send_bits in client.c
{
    Kill send a signal to a process, by default thesignal i TERM (terminate)
    
}