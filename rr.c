#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int processID;
    int burstTime;
    int remainingTime;
};

void roundRobinScheduling(struct Process processes[], int numProcesses, int timeQuantum) {
    int currentTime = 0;
    int completedProcesses = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    printf("Process\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completedProcesses < numProcesses) {
        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0) {
                int executionTime = (processes[i].remainingTime > timeQuantum) ? timeQuantum : processes[i].remainingTime;

                currentTime += executionTime;
                processes[i].remainingTime -= executionTime;

                if (processes[i].remainingTime == 0) {
                    int turnaroundTime = currentTime;
                    int waitingTime = turnaroundTime - processes[i].burstTime;

                    totalTurnaroundTime += turnaroundTime;
                    totalWaitingTime += waitingTime;

                    printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
                           processes[i].processID, processes[i].burstTime,
                           turnaroundTime, turnaroundTime, waitingTime);

                    completedProcesses++;
                }
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
    int timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    struct Process processes[MAX_PROCESSES];

    for (int i = 0; i < numProcesses; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        processes[i].processID = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    roundRobinScheduling(processes, numProcesses, timeQuantum);

    return 0;
}
