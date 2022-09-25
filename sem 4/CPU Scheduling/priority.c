#include <stdio.h>

struct process
{
    int pid;
	int priority;
    int wtime;
    int turnatime;
    int btime;
} p[10], temp;

int main()
{
    int n, i, j, totalwtime = 0, totalturnatime = 0;
    printf("Enter the number of eprocess: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {	
		 printf("Enter the priority of process(P%d): ", i);
        scanf("%d", &p[i].priority);
        printf("Enter the burst of process(P%d): ", i);
        scanf("%d", &p[i].btime);
        p[i].pid = i;
    }
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (p[j].priority > p[j+1].priority)
			{
				temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
			}
			
		}
		
	}
	
    for (i = 0; i < n; i++)
    {
        p[i].wtime = p[i - 1].btime + p[i - 1].wtime;
        p[i].turnatime = p[i].btime + p[i].wtime;
        totalwtime += p[i].wtime;
        totalturnatime += p[i].turnatime;
    }
    printf("Process_no\tPriority\tBurst_time\tWait_time\tTurn_time");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].priority, p[i].btime, p[i].wtime, p[i].turnatime);
    }
    printf("\n");
    printf("The average waiting time: %f", (float)totalwtime / n);
    printf("\n");
    printf("The average trun around time: %f", (float)totalturnatime / n);
    printf("\n");
}