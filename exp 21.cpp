#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5            
#define LEFT (i + 4) % N 
#define RIGHT (i + 1) % N    
#define THINKING 0      
#define HUNGRY 1        
#define EATING 2        

int state[N];          
pthread_mutex_t mutex;  
pthread_cond_t cond[N]; 

void *philosopher(void *arg);
void take_forks(int i);
void put_forks(int i);
void test(int i);

int main()
{
    int i;
    pthread_t tid[N];

    
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < N; i++)
        pthread_cond_init(&cond[i], NULL);

    
    for (i = 0; i < N; i++)
        pthread_create(&tid[i], NULL, philosopher, (void *)i);

     for (i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    
    pthread_mutex_destroy(&mutex);
    for (i = 0; i < N; i++)
        pthread_cond_destroy(&cond[i]);

    return 0;
}

void *philosopher(void *arg)
{
    int i = (int)arg;

    while (1) {
        printf("Philosopher %d is thinking\n", i);
        sleep(rand() % 5);  

        take_forks(i);     
        printf("Philosopher %d is eating\n", i);
        sleep(rand() % 5);  
        put_forks(i);      
    }
}

void take_forks(int i)
{
    pthread_mutex_lock(&mutex);        
    state[i] = HUNGRY;                 
    test(i);                          
    while (state[i] != EATING)       
        pthread_cond_wait(&cond[i], &mut
}

void put_forks(int i)
{
    pthread_mutex_lock(&mutex);        
    state[i] = THINKING;                
    test(LEFT);                    
    test(RIGHT);                         
    pthread_mutex_unlock(&mutex);      
}

void test(int i)
{
    if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond[i]);  e
    }
}
