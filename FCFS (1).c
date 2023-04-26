#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fcfs(int curr_pos, int requests[], int num_requests) {
    int total_movements = 0;
    int i;

    for (i = 0; i < num_requests; i++) {
        int distance = abs(requests[i] - curr_pos);
        total_movements += distance;
        curr_pos = requests[i];
    }

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

    int total_seek_time = fcfs(curr_pos, requests, num_requests);
    printf("Total seek time: %d\n", total_seek_time);

    free(requests);

    return 0;
}

