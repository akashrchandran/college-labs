#include <stdio.h>

int main()
{
	int i, j, k, m, n, y, p, z;
	printf("Enter the number of process: ");
	scanf("%d", &m);
	printf("Enter the number of resources: ");
	scanf("%d", &n);
	int allocation[n][m], max[n][m], need[n][m], available[m], sequence[m];
	printf("Enter the allocation matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &allocation[i][j]);
		}
	}
	printf("Enter the max matrix: \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &max[i][j]);
		}
	}
	printf("Enter the available matrix: \n");

	for (i = 0; i < m; i++)
	{
		scanf("%d", &available[i]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	p = 1;
	y = 0;
	while (p != 0)
	{
		for (i = 0; i < n; i++)
		{
			z = 0;
			for (j = 0; j < m; j++)
			{
				if (need[i][j] <= available[j] && (need[i][0] != -1))
				{
					z++;
				}
			}
			if (z == n)
			{
				for (k = 0; k < m; k++)
				{
					available[k] += allocation[i][k];
				}
				printf("SS process %d", i);
				need[i][0] = -1;
				y++;
			}
		}
		if (y == n)
		{
			p = 0;
		}
	}

	return 0;
}
