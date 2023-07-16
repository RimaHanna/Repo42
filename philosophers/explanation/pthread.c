#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void* routine()
{
	printf("Test\n");
	sleep(3);
	printf("ending thread\n");
	return NULL;
}

int main(int ac, char **av)
{
	(void) ac;
	(void) av;
// create a variable
	pthread_t t1;
	pthread_t t2;
// initializing the thread:
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
	{
		return 1;
	} 
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
	{
		return 2;
	}
// wait for the process to finish its execution:
	if (pthread_join(t1, /*pass the return which is nthg here*/ NULL) != 0)
	{
		return 3;
	}
	if (pthread_join(t2, NULL) != 0)
	{
		return 4;
	}
	return 0;
}

