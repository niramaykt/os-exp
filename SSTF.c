#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sstf(int curr_pos, int requests[], int num_requests) {
    int total_movements = 0;
    int *visited = (int *)calloc(num_requests, sizeof(int));
    int min_distance, min_index, i, j;

    for (i = 0; i < num_requests; i++) {
        min_distance = INT_MAX;
        min_index = -1;
        for (j = 0; j < num_requests; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - curr_pos);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }
        }
        visited[min_index] = 1;
        total_movements += min_distance;
        curr_pos = requests[min_index];
    }

    free(visited);
    return total_movements;
}

int main() {
    int num_requests, curr_pos, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    int *requests = (int *)calloc(num_requests, sizeof(int));

    printf("Enter the disk requests:\n");
    for (i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the current position of the disk head: ");
    scanf("%d", &curr_pos);

    int total_seek_time = sstf(curr_pos, requests, num_requests);
    printf("Total seek time: %d\n", total_seek_time);

    free(requests);

    return 0;
}

