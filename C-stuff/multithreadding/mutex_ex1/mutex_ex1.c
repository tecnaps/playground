#include <pthread.h>
#include <stdio.h>
#include "bank.h"

void *deposit(void *amount);

pthread_mutex_t mutex;

int main(){

int before = read_balance();
printf("original balance: %d\n", before);

int deposit1 = 200;
int deposit2 = 350;

pthread_t thread1;
pthread_t thread2;

pthread_mutex_init(&mutex, NULL);       //! initializes the mutex

pthread_create(&thread1, NULL, deposit, (void *) &deposit1);
pthread_create(&thread2, NULL, deposit, (void *) &deposit2);

pthread_join(thread1, NULL);
pthread_join(thread2, NULL);

pthread_mutex_destroy(&mutex);          //! destroys the mutex

int after = read_balance();
printf("new balance: %d\n", after);

return 0;
}

void *deposit(void *amount){


    pthread_mutex_lock(&mutex);

    //! start of the critical section 

    int account_balance = read_balance();

    account_balance += *((int *) amount);
    
    write_balance(account_balance);

    //! end of the critical section

    pthread_mutex_unlock(&mutex);

    return NULL;
}