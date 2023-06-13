#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void* signaling_thread(void* arg) {
    // Simulate some work being done by the signaling thread
    printf("Signaling thread is doing some work...\n");
    sleep(2);

    // Signal the waiting thread
    sem_post(&semaphore);

    return NULL;
}

int main() {
    pthread_t signaling_thread_id;
    int ret;

    // Initialize the semaphore
    sem_init(&semaphore, 0, 0);

    // Create the signaling thread
    ret = pthread_create(&signaling_thread_id, NULL, signaling_thread, NULL);
    if (ret != 0) {
        printf("Failed to create the signaling thread.\n");
        return 1;
    }

    // Wait for the signaling thread to complete
    ret = pthread_join(signaling_thread_id, NULL);
    if (ret != 0) {
        printf("Failed to join the signaling thread.\n");
        return 1;
    }

    printf("Waiting thread has been signaled.\n");

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
