#include <stdio.h>
#include <stdlib.h>
int main() {
    int frame_size, page_size;
    printf("Enter the number of frames in the memory: ");
    scanf("%d", &frame_size);
    printf("Enter the number of pages to be loaded into the memory: ");
    scanf("%d", &page_size);

    int frames[frame_size]; // An array to hold the frames in the memory

    int pages[page_size]; // An array of pages to be loaded

    int page_faults = 0; // A variable to hold the number of page faults

    int page_hits = 0; // A variable to hold the number of page hits

    int i, j;

 

    // Initialize all the frames in the memory to -1

    for (i = 0; i < frame_size; i++) {

        frames[i] = -1;

    }

 

    // Load the pages into the memory

    int next_frame = 0; // A variable to keep track of the next frame to replace

    for (i = 0; i < page_size; i++) {

        printf("Enter page %d: ", i);

        scanf("%d", &pages[i]);

        int page = pages[i];

        int in_memory = 0;

 

        // Check if the page is already in the memory

        for (j = 0; j < frame_size; j++) {

            if (frames[j] == page) {

                in_memory = 1;

                page_hits++;

                break;

            }

        }

 

        // If the page is not in the memory, replace the next frame with the new page

        if (!in_memory) {

            frames[next_frame] = page;

            next_frame = (next_frame + 1) % frame_size; // Update the next frame to replace

            page_faults++;

        }

 

        // Print the frames in the memory after each page is loaded

        printf("Page %d: ", page);

        for (j = 0; j < frame_size; j++) {

            if (frames[j] == -1) {

                printf("_ ");

            } else {

                printf("%d ", frames[j]);

            }

        }

        printf("\n");

    }

 

    // Calculate the page hit ratio and print the results

    float hit_ratio = (float) page_hits / page_size;

    float fault_ratio = (float) page_faults / page_size;

    printf("Total page hits: %d\n", page_hits);

    printf("Total page faults: %d\n", page_faults);

    printf("Page hit ratio: %.2f\n", hit_ratio);

    printf("Page fault ratio: %.2f\n", fault_ratio);

 

    return 0;

}

 
