#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_even(void *arg) {
    int i;
    for (i = 0; i <= 10; i += 2) {
        printf("Even: %d\n", i);
        usleep(500000); // Sleep for 500 milliseconds
    }
    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    int i;
    for (i = 1; i <= 10; i += 2) {
        printf("Odd: %d\n", i);
        usleep(500000); // Sleep for 500 milliseconds
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_even, thread_odd;

    // Create the even thread
    if (pthread_create(&thread_even, NULL, print_even, NULL) != 0) {
        fprintf(stderr, "Error creating even thread.\n");
        return 1;
    }

    // Create the odd thread
    if (pthread_create(&thread_odd, NULL, print_odd, NULL) != 0) {
        fprintf(stderr, "Error creating odd thread.\n");
        return 1;
    }

    // Wait for both threads to finish
    pthread_join(thread_even, NULL);
    pthread_join(thread_odd, NULL);

    return 0;
}
