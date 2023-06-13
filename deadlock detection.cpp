#include <stdio.h>
#include <stdbool.h>

#define N_PROCESSES 3
#define N_RESOURCES 3

int max[N_PROCESSES][N_RESOURCES] = {{3, 6, 8}, {4, 3, 3}, {3, 4, 4}};
int allocation[N_PROCESSES][N_RESOURCES] = {{3, 3, 3}, {2, 0, 3}, {1, 2, 4}};
int need[N_PROCESSES][N_RESOURCES];
int available[N_RESOURCES] = {1, 2, 0};

bool finish[N_PROCESSES];

void calculate_need() {
    for (int i = 0; i < N_PROCESSES; i++) {
        for (int j = 0; j < N_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

bool is_less_than_or_equal(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

bool find_safe_sequence(int* sequence) {
    int work[N_RESOURCES];
    for (int i = 0; i < N_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < N_PROCESSES; i++) {
        finish[i] = false;
    }
    int count = 0;
    while (count < N_PROCESSES) {
        bool found = false;
        for (int i = 0; i < N_PROCESSES; i++) {
            if (!finish[i] && is_less_than_or_equal(need[i], work, N_RESOURCES)) {
                for (int j = 0; j < N_RESOURCES; j++) {
                    work[j] += allocation[i][j];
                }
                sequence[count] = i;
                count++;
                finish[i] = true;
                found = true;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

bool is_deadlock() {
    int sequence[N_PROCESSES];
    if (!find_safe_sequence(sequence)) {
        return true;
    }
    for (int i = 0; i < N_PROCESSES; i++) {
        if (!finish[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    calculate_need();
    if (is_deadlock()) {
        printf("The system is in a deadlock state.\n");
        printf("The following processes are deadlocked:\n");
        for (int i = 0; i < N_PROCESSES; i++) {
            if (!finish[i]) {
                printf("Process %d\n", i);
            }
        }
    } else {
        printf("The system is not in a deadlock state.\n");
    }
    return 0;
}
