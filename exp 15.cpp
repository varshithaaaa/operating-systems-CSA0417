#include<stdio.h>
#include<math.h>

int main() {
    int n = 9;
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int head = 50;
    int total_head_movement = 0;
    
    printf("Initial Head Position: %d\n", head);
    
    for(int i=0; i<n; i++) {
        int distance = abs(head - tracks[i]);
        printf("Move from %d to %d, Distance = %d\n", head, tracks[i], distance);
        total_head_movement += distance;
        head = tracks[i];
    }
    
    printf("Total Head Movement: %d\n", total_head_movement);
    printf("Average Head Movement: %.2f\n", (float)total_head_movement/n);
    
    return 0;
}
