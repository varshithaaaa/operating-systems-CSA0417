#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 3

int buffer[BUFFER_SIZE];
int itemCount = 0;
int fillIndex = 0;
int useIndex = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;

void* producer(void* arg) {
    int i;
    for (i = 0; i < 4; ++i) 
	{
        pthread_mutex_lock(&mutex);
        while (itemCount == BUFFER_SIZE) {
            printf("Buffer is FULL. Producer is waiting.\n");
            pthread_cond_wait(&bufferNotFull, &mutex);
        }

        buffer[fillIndex] = i;
        printf("Produced item %d\n", buffer[fillIndex]);
        fillIndex = (fillIndex + 1) % BUFFER_SIZE;
        itemCount++;

        pthread_cond_signal(&bufferNotEmpty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
