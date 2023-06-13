#include <stdio.h> 
 #include <stdlib.h> 
 #include <stdbool.h> 
 #define NUM_TRACKS 5 
 int tracks[NUM_TRACKS] = {55, 58, 60, 70, 18}; 
 int compare(const void *a, const void *b) { 
   return (*(int *)a - *(int *)b); 
 } 
 int cscan(int start, int end) { 
   int head_movement = 0; 
   bool direction = true;  
   qsort(tracks, NUM_TRACKS, sizeof(int), compare); 
   head_movement += abs(start - tracks[0]); 
   int i = 0; 
   while (i < NUM_TRACKS && tracks[i] < start) { 
     i++; 
   } 
   while (i < NUM_TRACKS && tracks[i] <= end) { 
     head_movement += abs(tracks[i] - tracks[i-1]); 
     i++; 
   } 
   if (i < NUM_TRACKS) { 
     head_movement += abs(tracks[i-1] - end); 
   } 
   if (i == NUM_TRACKS && direction == true) { 
     head_movement += abs(end - tracks[0]); 
     head_movement += abs(tracks[0] - tracks[NUM_TRACKS-1]); 
   } 
   return head_movement; 
 } 
 int main() { 
   int start = 50; 
   int end = 70; 
   printf("Track positions: "); 
   for (int i = 0; i < NUM_TRACKS; i++) { 
     printf("%d ", tracks[i]); 
   } 
   printf("\n"); 
   int head_movement = cscan(start, end); 
   printf("Average head movement: %d\n", head_movement / NUM_TRACKS); 
 }
