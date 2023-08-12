#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int processID;
    int burstTime;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

void sjfScheduling(struct Process processes[], int numProcesses) {
    // Sorting the processes based on burst time using Selection Sort
    for (int i = 0; i < numProcesses - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numProcesses; j++) {
            if (processes[j].burstTime < processes[minIndex].burstTime) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&processes[i], &processes[minIndex]);
        }
    }

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < numProcesses; i++) {
        int completionTime = currentTime + processes[i].burstTime;
        int turnaroundTime = completionTime;
        int waitingTime = currentTime;

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processID, processes[i].burstTime,
               completionTime, turnaroundTime, waitingTime);

        currentTime = completionTime;
    }

    double avgWaitingTime = (double)totalWaitingTime / numProcesses;
    double avgTurnaroundTime = (double)totalTurnaroundTime / numProcesses;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnaroundTime);
}

int main() {
    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    struct Process processes[MAX_PROCESSES];

    for (int i = 0; i < numProcesses; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        processes[i].processID = i + 1;
    }

    sjfScheduling(processes, numProcesses);

    return 0;
}
