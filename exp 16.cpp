#include<stdio.h>

int main() {
    int n = 3;
    int burst_times[] = {10, 15, 25};
    int waiting_times[n], turnaround_times[n];
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
   
    waiting_times[0] = 0;
    turnaround_times[0] = burst_times[0];
    for(int i=1; i<n; i++) {
        waiting_times[i] = waiting_times[i-1] + burst_times[i-1];
        turnaround_times[i] = waiting_times[i] + burst_times[i];
    }
    

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
