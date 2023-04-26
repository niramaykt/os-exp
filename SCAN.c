#include <stdio.h>
#include <stdlib.h>

int scan(int curr_pos, int requests[], int num_requests, int max_cylinder) {
    int total_movements = 0;
    int direction = 1; // 1: moving towards higher numbered cylinders; -1: moving towards lower numbered cylinders
    int i, j, temp;

    // Sort the requests in ascending order
    for (i = 0; i < num_requests; i++) {
        for (j = i + 1; j < num_requests; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }

    // Find the closest request in the current direction
    for (i = 0; i < num_requests; i++) {
        if (requests[i] >= curr_pos) {
            break;
        }
    }

    if (i == num_requests) {
        // All requests are below the current position
        direction = -1;
        i = num_requests - 1;
    }

    while (i >= 0 && i < num_requests) {
        int distance = abs(requests[i] - curr_pos);
        total_movements += distance;
        curr_pos = requests[i];
        i += direction;
    }

    // Add the distance to the end of the disk
    total_movements += abs(max_cylinder - curr_pos);
    curr_pos = max_cylinder;

    // Move back towards the closest request in the opposite direction
    direction *= -1;
    i += direction;
    while (i >= 0 && i < num_requests) {
        int distance = abs(requests[i] - curr_pos);
        total_movements += distance;
        curr_pos = requests[i];
        i += direction;
    }

    return total_movements;
}

int main() {
    int num_requests, curr_pos, max_cylinder, i;

    printf("Enter the number of disk requests: ");
    scanf("%d", &num_requests);

    int *requests = (int *)calloc(num_requests, sizeof(int));

    printf("Enter the disk requests:\n");
    for (i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the current position of the disk head: ");
    scanf("%d", &curr_pos);

    printf("Enter the maximum cylinder number of the disk: ");
    scanf("%d", &max_cylinder);

    int total_seek_time = scan(curr_pos, requests, num_requests, max_cylinder);
    printf("Total seek time: %d\n", total_seek_time);

    free(requests);

    return 0;
}
