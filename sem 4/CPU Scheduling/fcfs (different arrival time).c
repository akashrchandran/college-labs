#include <stdio.h> 

struct process
{
    int pid;
    int atime;
    int wtime;
    int turnatime;
    int btime;
}p[10], temp;


int main()
{
    int n, i, j, totalwtime = 0, totalturnatime = 0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process(P%d): ", i);
        scanf("%d", &p[i].atime);
        printf("Enter the burst time of process(P%d): ", i);
        scanf("%d", &p[i].btime);
        p[i].pid = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (p[j].atime > p[j + 1].atime)
            {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

            }
        }
        
    }
    
    for(i = 0; i<n; i++)
    {
        if (i == 0)
            p[i].wtime = p[i].atime;
        else
            p[i].wtime = p[i-1].btime - p[i].atime;
        p[i].turnatime = p[i].btime + p[i].wtime;
        totalwtime += p[i].wtime;
        totalturnatime += p[i].turnatime;

    }
    printf("Process_no\tBurst_time\tWait_time\tTurn_time");
	for(i=0; i < n; i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\n", p[i].pid,p[i].btime,p[i].wtime,p[i].turnatime);
    }
    printf("\n");
    printf("The average waiting time: %f", (float)totalwtime/n);
    printf("\n");
    printf("The average trun around time: %f", (float)totalturnatime/n);
    printf("\n");
}