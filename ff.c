#include <stdio.h>

#define MAX_BLOCKS 10

void allocateMemory(int blocks[], int numBlocks, int processSize) {
    for (int i = 0; i < numBlocks; i++) {
        if (blocks[i] >= processSize) {
            blocks[i] -= processSize;
            printf("Process allocated to block %d\n", i);
            return;
        }
    }
    printf("No suitable block found for allocation\n");
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
