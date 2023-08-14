//Priority
#include <limits.h>
#include <stdio.h>
struct Process {
  int id;
  int at;
  int bt;
  int remaining_time;
  int priority;
  int ct;
  int wt;
  int tat;
};

struct Process done[100];
int num = 0;

void priority_preemptive(struct Process a[], int n)
{
  int current_time = 0;
  int completed = 0;

  printf("\nGantt Chart:\n");
  printf("--------------------------------------------------------\n");
  
  while (completed < n) 
  {
    int highest_priority = -1;
    int highest_priority_value = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      if (a[i].at <= current_time &&
          a[i].priority < highest_priority_value &&
          a[i].remaining_time > 0)
           {
            highest_priority_value = a[i].priority;
            highest_priority = i;
      }
    }

    if (highest_priority == -1) 
     {
      printf("|  Idle\t");
      current_time++;
     } 
    else 
    {
      printf("|  P%d\t", a[highest_priority].id);
      a[highest_priority].remaining_time--;
      done[num] = a[highest_priority];
      num++;
      current_time++;

      if (a[highest_priority].remaining_time == 0)
       {
        completed++;
        a[highest_priority].ct = current_time;
        a[highest_priority].tat = current_time - a[highest_priority].at;
        a[highest_priority].wt = a[highest_priority].tat - a[highest_priority].bt;
      }
    }
  }
  
  printf("|\n");
  printf("--------------------------------------------------------\n");
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process a[n];
  for (int i = 0; i < n; i++) {
    a[i].id = i + 1;
    printf("Enter arrival time for Process %d: ", i + 1);
    scanf("%d", &a[i].at);
    printf("Enter burst time for Process %d: ", i + 1);
    scanf("%d", &a[i].bt);
    printf("Enter priority for Process %d: ", i + 1);
    scanf("%d", &a[i].priority);
    a[i].remaining_time = a[i].bt;
  }

  printf("\nPreemptive Priority Scheduling:\n");
  priority_preemptive(a, n);

  return 0;
}