fonction obligatoire à utilisé:
	fork
	execve

voir comment trouver des leaks

functions explanation
1. `readline`:
   - Explanation: A library function used for reading lines of text from an input source.
    It provides line editing capabilities, including history management and command-line editing.
   - Prototype: `char *readline(const char *prompt);`

2. `rl_clear_history`:
   - Explanation: This function is used in conjunction with the `readline` library
    to clear the history of previously entered commands.
   - Prototype: `void rl_clear_history(void);`

3. `rl_on_new_line`:
   - Explanation: A function from the `readline` library that moves the cursor to a new line.
   - Prototype: `void rl_on_new_line(void);`

4. `rl_replace_line`:
   - Explanation: Another `readline` function that replaces the current input line with a new string.
   - Prototype: `void rl_replace_line(const char *text, int clear_undo);`

5. `rl_redisplay`:
   - Explanation: This function, part of the `readline` library, is used to redisplay 
   the current input line, typically after modifying it using other `readline` functions.
   - Prototype: `void rl_redisplay(void);`

6. `add_history`:
   - Explanation: A function provided by the `readline` library to add a line 
   to the history of entered commands.
   - Prototype: `void add_history(const char *line);`

7. `printf`:
   - Explanation: A standard C library function used to format and print text 
   to the standard output (usually the terminal).
   - Prototype: `int printf(const char *format, ...);`

8. `malloc`:
   - Explanation: A C library function that dynamically allocates memory 
   on the heap for a specified size.
   - Prototype: `void *malloc(size_t size);`

9. `free`:
   - Explanation: A C library function used to release memory that
    was previously allocated using `malloc`.
   - Prototype: `void free(void *ptr);`

10. `write`:
    - Explanation: A system call that writes data to a file descriptor,
     typically used to output data to the console or files.
    - Prototype: `ssize_t write(int fd, const void *buf, size_t count);`

11. `access`:
    - Explanation: A system call that checks the accessibility of a file or
     path based on specified permissions.
    - Prototype: `int access(const char *pathname, int mode);`

12. `open`:
    - Explanation: A system call that opens a file, creating a file
     descriptor that can be used for subsequent read and write operations.
    - Prototype: `int open(const char *pathname, int flags, mode_t mode);`

13. `read`:
    - Explanation: A system call used to read data from a file descriptor into a buffer.
    - Prototype: `ssize_t read(int fd, void *buf, size_t count);`

14. `close`:
    - Explanation: A system call that closes a file descriptor.
    - Prototype: `int close(int fd);`

15. `fork`:
    - Explanation: A system call that creates a new process
     by duplicating the current process. The new process is referred to as the child process.
    - Prototype: `pid_t fork(void);`

16. `wait`, `waitpid`, `wait3`, `wait4`:
    - Explanation: These are system calls used to wait for child 
    processes to terminate and collect their exit status.
    - Prototypes: `pid_t wait(int *status);`, `pid_t waitpid(pid_t pid, int *status, int options);`, `pid_t wait3(int *status, int options, struct rusage *rusage);`, `pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);`

17. `signal`, `sigaction`:
    - Explanation: Functions used to manage signal handling in a program.
     Signals are used to notify processes about various events, like errors or user interrupts.
    - Prototypes: `void (*signal(int signum, void (*handler)(int)))(int);`, `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);`

18. `sigemptyset`, `sigaddset`:
    - Explanation: Functions used to manipulate sets of signals.
    - Prototypes: `int sigemptyset(sigset_t *set);`, `int sigaddset(sigset_t *set, int signum);`

19. `kill`:
    - Explanation: A function used to send signals to processes or process groups.
    - Prototype: `int kill(pid_t pid, int sig);`

20. `exit`:
    - Explanation: A function used to terminate a process and return an exit status to the parent process.
    - Prototype: `void exit(int status);`

21. `getcwd`:
    - Explanation: A function that retrieves the current working directory.
    - Prototype: `char *getcwd(char *buf, size_t size);`

22. `chdir`:
    - Explanation: A function used to change the current working directory.
    - Prototype: `int chdir(const char *path);`

23. `stat`, `lstat`, `fstat`:
    - Explanation: Functions used to retrieve information about a file, such as its size and permissions.
    - Prototypes: `int stat(const char *pathname, struct stat *buf);`, `int lstat(const char *pathname, struct stat *buf);`, `int fstat(int fd, struct stat *buf);`

24. `unlink`:
    - Explanation: A function used to delete a file.
    - Prototype: `int unlink(const char *pathname);`

25. `execve`:
    - Explanation: A system call used to execute a program.
    threwing away the calling program but not the calling process
    it always return (-1)
    - Prototype: `int execve(const char *filename /*pathname*/, char *const argv[], char *const envp[]);`
    pathname: the pathname of the command to execute
    argv: the argument to pass to the new program
    env: the enviroment list
	if the command typed by the user is not a builtin command, then we consider
	it is a program, andwe search in PATHS to find this program and execute it with
	execve. If nothing is found i display an error message

26. `dup`, `dup2`:
    - Explanation: Functions used to duplicate file descriptors.
    - Prototypes: `int dup(int oldfd);`, `int dup2(int oldfd, int newfd);`

27. `pipe`:
    - Explanation: A system call used to create a pipe, which is a
     unidirectional communication channel between processes.
    - Prototype: `int pipe(int pipefd[2]);`

28. `opendir`, `readdir`, `closedir`:
    - Explanation: Functions used to manipulate directories and their contents.
    - Prototypes: `DIR *opendir(const char *name);`, `struct dirent *readdir(DIR *dirp);`, `int closedir(DIR *dirp);`

29. `strerror`:
    - Explanation: A function that returns a string describing an error code.
    - Prototype: `char *strerror(int errnum);`

30. `perror`:
    - Explanation: A function that prints a descriptive error message to the standard error stream.
    - Prototype: `void perror(const char *s);`

31. `isatty`:
    - Explanation: A function that checks if a file descriptor refers to a terminal.
    - Prototype: `int isatty(int fd);


links: 
link explaning the interface
https://www.youtube.com/watch?v=hMSByvFHOro&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW

link explaning shell in C
https://www.youtube.com/watch?v=4jYFqFsu03A&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW&index=5

link explaning fork
https://www.youtube.com/watch?v=hKA3wJtyDo4&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW&index=26

link explaining exec
https://www.youtube.com/watch?v=iq7puCxsgHQ 

easy explanation to parsing, tokens
https://www.youtube.com/watch?v=r6vNthpQtSI&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW&index=29


Moi j'ai identifie les parties suivantes dans le project:
- la mecanique qui va ecouter les evenement du clavier (signal) (...)
- la partie qui interprete les commandes quand le clavier envoie ENTER. (parsing)
- la partie qui appelle chaque commande (ou qui affiche une erreure si la commande
est fausse) (parsing)
- la partie commands history (parsing)
- la partie qui contient les fonctions des commandes built-in
- la partie qui execute des programmes externes (execve) (en cherchant dans le 
cwd et les PATHS)
- la partie pipe et redirect (< > << >>)
- la partie set/unset env variables

&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


Moi j'ai identifie les parties suivantes dans le project:
- la mecanique qui va ecouter les evenement du clavier (signal) (...)
	> créer les events qui écoutent le clavier.
	> boucle while infinie qui envoie les chars des events par signal
	> partie qui écoute les signals envoyés par le event.
		> cette partie va afficher les chars un par un, et les garde dans une string (la commande)
		(ce sera probablement une liste chainée car on ne connait pas la taille)
		> si le char est ENTER, alors on rajoute la commande au history, et on va interpréter la commande

- la partie qui interprete les commandes quand le clavier envoie ENTER. (parsing)
	> on voit la string de la commande comment elle est formée
	> si elle correspond à une commande built-in, on l'exécute
	> sinon, on considère que c'est un programme externe, on appelle execve	
		> execve va chercher dans le cwd et les PATHS si ce programme existe.
         si oui, on execute le programme. Si non il faut envoyer une erreur
	> pour les commandes built-in et les programmes externes, 
		il aussi envoyer les pipe et redirections.

- la partie qui appelle chaque commande (ou qui affiche une erreure si la commande
est fausse) (parsing)
	> si la commande n'est pas une commande built-in, on appelle la partie qui exécute
		les programmes externe. Si cette partie renvoie que le programme n'est pas trouvé
		(dans cwd et les PATHS), alors on doit afficher un message d'erreur (command / program not found)
	> si c'est une commande built-in, on doit appeler la fonction correspondante (partie exécution)
		et afficher le résultat.
		> est-ce que le résultat sera la valeur de return? est-ce qu'on passe à la commande un
			paramètre buff qui sera rempli par la commande?
	> si la commande est un programme externe à exécuter, il faut voir comment le programme
		peut afficher des choses dans la console, et s'il fait return, qu'est-ce qui se passe?
		> la personne qui va utiliser notre minishell, a peut-être un programme a.out. Ce programme
			va afficher des choses avec printf ou write. 
		> Normalement, printf et write affichent dans le shell de Ubuntu. Dans notre cas, il faut afficher
			dans minishell. Donc comment ça va se passer?
		> dans le shell de Ubuntu, si on exécute a.out, et si a.out fait "return -1", 

- la partie commands history (parsing)
	> une liste chainée.
    > notes: il faut sauvegarder tout les string ecris dans la ligne de commande
    et non seulement executes
	
- la partie qui contient les fonctions des commandes built-in
- la partie qui execute des programmes externes (execve) (en cherchant dans le 
cwd et les PATHS)
- la partie pipe et redirect (< > << >>)
- la partie set/unset env variables


$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$4

- je commence a travailler la fonctions qui gere les quotes:
    - si c'est une single quote ou double quote non fermes: le programme renvoie
        que le syntax est faux
    - si il y a une single quote ou double alors les caracterer wildcard (* ou ? ou \) qui existe
        a l'interieure des quotes seront consideres comme un string