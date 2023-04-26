#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    // This will store the block id of the allocated block to a process
    int allocation[proccesses];
    int occupied[blocks];

    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for (int i = 0; i < proccesses; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < proccesses; i++)
    {

        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++)
        {
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;

                // if any future block is smalller than the current block where
                // process is placed, change the block and thus indexPlaced
                // this reduces the wastage thus best fit
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }

        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;

            // make the status of the block as occupied
            occupied[indexPlaced] = 1;
        }
    }

    printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    // This will store the block id of the allocated block to a process
    int allocate[proccesses];
    int occupied[blocks];

    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for (int i = 0; i < proccesses; i++)
    {
        allocate[i] = -1;
    }

    for (int i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }

    // take each process one by one and find
    // first block that can accomodate it
    for (int i = 0; i < proccesses; i++)
    {
        for (int j = 0; j < blocks; j++)
        {
            if (!occupied[j] && blockSize[j] >= processSize[i])
            {
                // allocate block j to p[i] process
                allocate[i] = j;
                occupied[j] = 1;

                break;
            }
        }
    }

    printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocate[i] != -1)
            printf("%d\n", allocate[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    // This will store the block id of the allocated block to a process
    int allocation[processes];
    int occupied[blocks];

    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for (int i = 0; i < processes; i++)
    {
        allocation[i] = -1;
    }

    for (int i = 0; i < blocks; i++)
    {
        occupied[i] = 0;
    }

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < processes; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++)
        {
            // if not occupied and block size is large enough
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;

                // if any future block is larger than the current block where
                // process is placed, change the block and thus indexPlaced
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }

        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;

            // make the status of the block as occupied
            occupied[indexPlaced] = 1;

            // Reduce available memory for the block
            blockSize[indexPlaced] -= processSize[i];
        }
    }

    printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
    for (int i = 0; i < processes; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

// Driver code
int main()
{
    int blockSize[] = {100, 212, 300, 120, 80};
    int processSize[] = {70, 240, 100, 120, 50, 60};
    int blocks = sizeof(blockSize) / sizeof(blockSize[0]);
    int proccesses = sizeof(processSize) / sizeof(processSize[0]);
    printf("\n \t\t\tBest fit");
    implimentBestFit(blockSize, blocks, processSize, proccesses);
    printf("\n \t\t\tFirst Fit");
    implimentFirstFit(blockSize, blocks, processSize, proccesses);
    printf("\n \t\t\tWorst Fit");
    implimentWorstFit(blockSize, blocks, processSize, proccesses);
    return 0;
}
