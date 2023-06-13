#include <stdio.h> 
 #include <stdlib.h> 
 #define DIRECTION_UP 1 
 #define DIRECTION_DOWN -1 
 int compare(const void *a, const void *b) { 
     return (*(int *)a - *(int *)b); 
 } 
 int scan(int n, int *tracks, int head, int direction) { 
     int i, j, index, distance = 0; 
     int *temp = (int *)malloc((n + 1) * sizeof(int)); 
         for (i = 0; i < n; i++) { 
         temp[i] = tracks[i]; 
     } 
     temp[n] = head; 
         qsort(temp, n + 1, sizeof(int), compare); 
         for (i = 0; i < n + 1; i++) { 
         if (temp[i] == head) { 
             index = i; 
             break; 
         } 
     } 
     {
     	printf(" thank you  ");
	 }
     if (direction == DIRECTION_UP) { 
         for (i = index; i < n + 1; i++) { 
             distance += abs(temp[i] - head); 
             head = temp[i]; 
         } 
         for (i = n - 1; i >= 0; i--) { 
             if (i != index) { 
                 distance += abs(temp[i] - head); 
                 head = temp[i]; 
             } 
         } 
     } else { 
         for (i = index; i >= 0; i--) { 
             distance += abs(temp[i] - head); 
             head = temp[i]; 
         } 
         for (i = 0; i < n; i++) { 
             if (i != index) { 
                 distance += abs(temp[i] - head); 
                 head = temp[i]; 
             } 
         } 
     } 
     free(temp); 
     return distance; 
 } 
 int main() { 
     int n, head, direction, i, distance; 
     int *tracks; 
     printf("Enter the number of tracks: "); 
     scanf("%d", &n); 
     tracks = (int *)malloc(n * sizeof(int)); 
     printf("Enter the track positions:\n"); 
     for (i = 0; i < n; i++) { 
         scanf("%d", &tracks[i]); 
     } 
     printf("Enter the initial head position: "); 
     scanf("%d", &head); 
     printf("Enter the initial direction (1 for up, -1 for down): "); 
     scanf("%d", &direction); 
     distance = scan(n, tracks, head, direction); 
     printf("The total head movement is: %d\n", distance); 
     printf("The average head movement is: %f\n", (float)distance / n); 
     free(tracks); 
 }
