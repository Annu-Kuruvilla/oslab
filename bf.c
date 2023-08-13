#include <stdio.h>
#include <limits.h>

#define MAX_BLOCKS 10

void allocateMemory(int blocks[], int numBlocks, int processSize) {
    int bestFitIndex = -1;
    int bestFitDifference = INT_MAX;

    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i] >= processSize) {
            int difference = blocks[i] - processSize;
            if (difference < bestFitDifference) {
                bestFitDifference = difference;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        blocks[bestFitIndex] -= processSize;
        printf("Process allocated to block %d\n", bestFitIndex);
    } else {
        printf("No suitable block found for allocation\n");
    }
}

int main() {
    int numBlocks;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    int blocks[MAX_BLOCKS];
    for (int i = 0; i < numBlocks; i++) {
        printf("Enter size of block %d: ", i);
        scanf("%d", &blocks[i]);
    }

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        int processSize;
        printf("Enter size of process %d: ", i);
        scanf("%d", &processSize);
        allocateMemory(blocks, numBlocks, processSize);
    }

    return 0;
}
