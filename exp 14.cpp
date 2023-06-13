#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPagePresent(int page, int* frames, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int findPageToReplace(int* pages, int num_pages, int* frames, int num_frames, int start_index) {
    int farthest_index = -1;
    int farthest_page = -1;

    for (int i = 0; i < num_frames; i++) {
        bool page_found = false;
        for (int j = start_index; j < num_pages; j++) {
            if (frames[i] == pages[j]) {
                page_found = true;
                if (j > farthest_index) {
                    farthest_index = j;
                    farthest_page = frames[i];
                }
                break;
            }
        }
        if (!page_found) {
            return i;
        }
    }

    if (farthest_page == -1) {
        
        fprintf(stderr, "Error: No page found to replace\n");
        exit(EXIT_FAILURE);
    }

    return findPageToReplace(pages, num_pages, frames, num_frames, farthest_index + 1);
}

int main() {
    int num_frames = 3;
    int num_pages = 20;
    int pages[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int frames[num_frames];
    int num_page_faults = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < num_pages; i++) {
        if (isPagePresent(pages[i], frames, num_frames)) {
            printf("Page %d is already present in memory\n", pages[i]);
        }
        else {
            int page_to_replace = findPageToReplace(pages, num_pages, frames, num_frames, i + 1);
            printf("Page %d is not present in memory, replacing page %d\n", pages[i], frames[page_to_replace]);
            frames[page_to_replace] = pages[i];
            num_page_faults++;
        }
    }

    printf("Number of page faults = %d\n", num_page_faults);

    return 0;
}
