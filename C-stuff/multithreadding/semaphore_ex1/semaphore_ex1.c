#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


#define THREAD_NUM 4
sem_t semaphore;
int *cnt;

void *computation(void* args);

int main(int argc, char *argv[]) {

    pthread_t threads[THREAD_NUM];
    sem_init(&semaphore, 0, 1);
    cnt = malloc(sizeof(int));          //! remember to allocate...
    *cnt = 0;

    for(int i = 0; i < THREAD_NUM; i++) {
        int* id = malloc(sizeof(int));
        *id = i;
        if (pthread_create(&threads[i], NULL, &computation, id)!= 0)
            perror("Failed to create thread");
    }

    for (int i = 0; i < THREAD_NUM; i++) {
        if(pthread_join(threads[i], NULL) != 0)
            perror("Failed to join thread");
    }
    
    sem_destroy(&semaphore);

    return 0;
}

void *computation(void *args){

    sem_wait(&semaphore);
    for(int i = 0; i < 5; i++){
        ++(*cnt);
        printf("Thread %d: %d\n", *(int *) args, *cnt);
    }
    free(args);
    sem_post(&semaphore);

}