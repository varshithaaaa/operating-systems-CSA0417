#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;
    int i;

   
    pid1 = fork();
    if (pid1 == 0) {
       
        printf("Child process 1 (pid=%d): odd numbers\n", getpid());
        for (i = 1; i <= 10; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
    
        pid2 = fork();
        if (pid2 == 0) {
           
            printf("Child process 2 (pid=%d): even numbers\n", getpid());
            for (i = 2; i <= 10; i += 2) {
                printf("%d ", i);
            }
            printf("\n");
        } else {
     
            pid3 = fork();
            if (pid3 == 0) {
               
                printf("Child process 3 (pid=%d): multiples of 3\n", getpid());
                for (i = 3; i <= 30; i += 3) {
                    printf("%d ", i);
                }
                printf("\n");
            } else {
                
                pid4 = fork();
                if (pid4 == 0) {
                    
                    printf("Child process 4 (pid=%d): multiples of 5\n", getpid());
                    for (i = 5; i <= 50; i += 5) {
                        printf("%d ", i);
                    }
                    printf("\n");
                } else {
                    
                    int status;
                    waitpid(pid1, &status, 0);
                    waitpid(pid2, &status, 0);
                    waitpid(pid3, &status, 0);
                    waitpid(pid4, &status, 0);
                    printf("Parent process (pid=%d): all children finished\n", getpid());
                }
            }
        }
    }

    return 0;
}
