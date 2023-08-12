#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int processID;
    int burstTime;
    int remainingTime;
};

void srtfScheduling(struct Process processes[], int numProcesses) {
    int currentTime = 0;
    int completedProcesses = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completedProcesses < numProcesses) {
        int shortestIndex = -1;
        int shortestBurst = INT_MAX;

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0 && processes[i].burstTime < shortestBurst) {
                shortestIndex = i;
                shortestBurst = processes[i].burstTime;
            }
        }

        if (shortestIndex != -1) {
            int executionTime = 1;
            currentTime += executionTime;
            processes[shortestIndex].remainingTime -= executionTime;

            if (processes[shortestIndex].remainingTime == 0) {
                int completionTime = currentTime;
                int turnaroundTime = completionTime;
                int waitingTime = turnaroundTime - processes[shortestIndex].burstTime;

                totalTurnaroundTime += turnaroundTime;
                totalWaitingTime += waitingTime;

                printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
                       processes[shortestIndex].processID, processes[shortestIndex].burstTime,
                       completionTime, turnaroundTime, waitingTime);

                completedProcesses++;
            }
        }
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
        processes[i].remainingTime = processes[i].burstTime;
    }

    srtfScheduling(processes, numProcesses);

    return 0;
}
