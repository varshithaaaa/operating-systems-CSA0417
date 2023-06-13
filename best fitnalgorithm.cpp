#include <stdio.h>

#define NUM_PARTITIONS 6
#define NUM_PROCESSES 5

int main() {
    int partitions[NUM_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[NUM_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[NUM_PROCESSES] = {-1, -1, -1, -1, -1};  
    
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int best_fit_index = -1;
        for (int j = 0; j < NUM_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                if (best_fit_index == -1 || partitions[j] < partitions[best_fit_index]) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index != -1) {
            allocation[i] = best_fit_index;
            partitions[best_fit_index] -= processes[i];
        }
    }
    
    printf("Process\tSize\tPartition\n");
    for (int i = 0; i < NUM_PROCESSES; i++) {
        printf("%d\t%d\t", i+1, processes[i]);
        if (allocation[i] != -1) {
            printf("%d\n", allocation[i]+1);
        } else {
            printf("Not allocated\n");
        }
    }
    
    return 0;
}
