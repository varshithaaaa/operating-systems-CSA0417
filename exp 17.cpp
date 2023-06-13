#include<stdio.h>

int main() {
    int n = 3;
    int burst_times[] = {24, 3, 3};
    int waiting_times[n], turnaround_times[n];
    int quantum_time = 4;
    int remaining_burst_times[n];
    int time = 0;
    int flag = 0;
    
    
    for(int i=0; i<n; i++) {
        waiting_times[i] = 0;
        remaining_burst_times[i] = burst_times[i];
    }
    
    while(1) {
        flag = 0;
        for(int i=0; i<n; i++) {
            if(remaining_burst_times[i] > 0) {
                flag = 1;
                if(remaining_burst_times[i] > quantum_time) {
                    time += quantum_time;
                    remaining_burst_times[i] -= quantum_time;
                }
                else {
                    time += remaining_burst_times[i];
                    waiting_times[i] = time - burst_times[i];
                    remaining_burst_times[i] = 0;
                    turnaround_times[i] = time;
                }
            }
        }
        if(flag == 0) {
            break;
        }
    }
    
    
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_times[i];
        avg_turnaround_time += turnaround_times[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
   
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i+1, burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
