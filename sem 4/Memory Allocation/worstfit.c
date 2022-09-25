#include <stdio.h>

struct process
{
	int pid;
	int size;
};

struct block
{
	int bid;
	int size;
};

int main()
{
	int n, x, i, j, flag, greatest;
	printf("Enter the number of process: ");
	scanf("%d", &n);
	struct process p[n];
	for (i = 0; i < n; i++)
	{
		printf("Enter the size of the process(P%d): ", i);
		scanf("%d", &p[i].size);
		p[i].pid = i;
	}
	printf("Enter the number of blocks: ");
	scanf("%d", &x);
	struct block b[x];
	for (i = 0; i < x; i++)
	{
		printf("Enter the size of block(B%d): ", i);
		scanf("%d", &b[i].size);
		b[i].bid = i;
	}
	printf("Process_no\tP_Size\tBlock_no\tB_left\n");
	for (i = 0; i < n; i++)
	{
		flag = 0, greatest = 0;
		for (j = 0; j < x; j++)
		{
			if (b[j].size >= p[i].size)
			{
				flag = 1;
				if (b[greatest].size < b[j].size)
					greatest = j;
			}
		}
		if (flag == 1)
		{
			b[greatest].size -= p[i].size;
			printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].size, b[greatest].bid, b[greatest].size);
		}
		else if (flag == 0)
		{
			printf("%d\t\t%d\t\t\t%s\t\n", p[i].pid, p[i].size, "Not Allocated");
		}
	}

	return 0;
}
