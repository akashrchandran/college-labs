#include <stdio.h>

struct process
{
  int pid;
  int btime;
  int btimeleft;
} p[10];

int main()
{

  int i, n, remain, time_quantum;
  int j = 0, time = 0, wait_time = 0, turnaround_time = 0;
  printf("Enter Total Process: ");
  scanf("%d", &n);
  remain = n;
  for (int i = 0; i < n; i++)
  {
    p[i].pid = i + 1;
    printf("Enter Burst Time for Process Process Number %d :", i + 1);
    scanf("%d", &p[i].btime);
    p[i].btimeleft = p[i].btime;
  }
  printf("Enter Time Quantum: ");
  scanf("%d", &time_quantum);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  while (remain != 0)
  {
    if (p[j].btimeleft <= time_quantum && p[j].btimeleft > 0)
    {
      time += p[j].btimeleft;
      p[j].btimeleft = 0;
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n", p[j].pid, time, time - p[j].btime);
      wait_time += time - p[j].btime;
      turnaround_time += time;
    }
    else if (p[j].btimeleft > 0)
    {
      p[j].btimeleft -= time_quantum;
      time += time_quantum;
    }
    /*
    * j = (j + 1) % n;
    * works same as the 4 lines below.
    */
    if (j == n - 1)
      j = 0;
    else
      j++;
  }
  printf("\nAverage Waiting Time= %f", (float)wait_time / n);
  printf("\nAvg Turnaround Time = %f", (float)turnaround_time / n);
  return 0;
}