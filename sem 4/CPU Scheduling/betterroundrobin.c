#include <stdio.h>

struct process
{
    int pid;
    int wtime;
    int turnatime;
    int btime;
    int btimeleft;
} p[10];

int main()
{
	int n, i, j, q, left, time, totalwtime = 0, totalturnatime = 0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
     printf("Enter the time quantum: ");
    scanf("%d", &q);
    left = n;
    for (i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("Enter the burst of process(P%d): ", i);
        scanf("%d", &p[i].btime);
        p[i].btimeleft = p[i].btime;
    }
    i = 0, time = 0;
	while (left != 0)
    {
        j = i % n;
        if (p[j].btimeleft == 0)
            continue;
        else if (p[j].btimeleft > q)
        {
            p[j].btimeleft = p[j].btimeleft - q;
            time += q;
        }
        else if (p[j].btimeleft <= q)
        {
            time += p[j].btimeleft;
            p[j].btimeleft = p[j].btimeleft - q;
            p[j].wtime = time - p[j].btime;
            p[j].turnatime = p[j].btime + p[j].wtime;
            left--;
        }
        i++;
    }
    printf("Process_no\tBurst_time\tWait_time\tTurn_time");
	for(i=0; i < n; i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\n", p[i].pid,p[i].btime,p[i].wtime,p[i].turnatime);
    }
	return 0;
}
