#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

int main()
{
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int i, j, min, index;
    int allocated[MAX_PROCESSES] = {0};
    
    printf("Memory Partitions:\n");
    for(i = 0; i < MAX_PARTITIONS; i++)
        printf("%d KB ", partitions[i]);
    printf("\n\n");
    
    for(i = 0; i < MAX_PROCESSES; i++)
    {
        min = 999999;
        index = -1;
        for(j = 0; j < MAX_PARTITIONS; j++)
        {
            if(partitions[j] >= processes[i] && partitions[j] < min)
            {
                min = partitions[j];
                index = j;
            }
        }
        if(index != -1)
        {
            allocated[i] = partitions[index];
            partitions[index] -= processes[i];
        }
    }
    
    printf("Allocation:\n");
    for(i = 0; i < MAX_PROCESSES; i++)
    {
        printf("Process %d: ", i);
        if(allocated[i] != 0)
            printf("%d KB\n", allocated[i]);
        else
            printf("Not allocated\n");
    }
    
    return 0;
}


