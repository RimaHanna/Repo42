#include <pthread.h>
#include <stdio.h>
/*
pthread_mutex_t mutex; // Mutex variable

void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex); // Acquire the mutex
    
    // Critical section
    printf("Hello from the thread!\n");
    
    pthread_mutex_unlock(&mutex); // Release the mutex
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex
    
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, thread_function, NULL);
    
    pthread_mutex_lock(&mutex); // Acquire the mutex in the main thread
    
    // Critical section
    printf("Hello from the main thread!\n");
    
    pthread_mutex_unlock(&mutex); // Release the mutex in the main thread
    
    // Wait for the thread to finish
    pthread_join(thread_id, NULL);
    
    pthread_mutex_destroy(&mutex); // Destroy the mutex
    
    printf("Main thread exiting.\n");
    return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine()
{
    int i = 0;
    while ( i < 10000000)
    {
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
        i++;
    }
}

int main(int argc, char* argv[]) {
    pthread_t p1, p2, p3, p4;
    pthread_mutex_init(&mutex, NULL);
    if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&p2, NULL, &routine, NULL) != 0) {
        return 2;
    }
    if (pthread_create(&p3, NULL, &routine, NULL) != 0) {
        return 3;
    }
    if (pthread_create(&p4, NULL, &routine, NULL) != 0) {
        return 4;
    }
    if (pthread_join(p1, NULL) != 0) {
        return 5;
    }
    if (pthread_join(p2, NULL) != 0) {
        return 6;
    }
    if (pthread_join(p3, NULL) != 0) {
        return 7;
    }
    if (pthread_join(p4, NULL) != 0) {
        return 8;
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}
