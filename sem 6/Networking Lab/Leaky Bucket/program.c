#include <stdio.h>
#include <stdlib.h>
struct packet
{
    int time;
    int size;
} P[50];
void main()
{
    int i, n, m, k = 0;
    int bsize, bfilled, outrate;
    printf("Number of packets:");
    scanf("%d", &n);
    printf("Enter the packets in the order of their arrival time:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the time and size:");
        scanf("%d%d", &P[i].time, &P[i].size);
    }
    printf("Enter the bucket size: ");
    scanf("%d", &bsize);
    printf("Enter the output rate: ");
    scanf("%d", &outrate);
    m = P[n - 1].time;
    i = 1;
    k = 0;
    bfilled = 0;
    while (i <= m || bfilled != 0)
    {
        printf("\n\nAt time %d", i);
        if (P[k].time == i)
        {
            if (bsize >= bfilled + P[k].size)
            {
                bfilled = bfilled + P[k].size;
                printf("\n%d byte packet is inserted", P[k].size);
                k = k + 1;
            }
            else
            {
                printf("\n%d byte packet is discarded", P[k].size);
                k = k + 1;
            }
        }
        if (bfilled == 0)
        {
            printf("\n no packets to transmit");
        }
        else if (bfilled >= outrate)
        {
            bfilled = bfilled - outrate;
            printf("\n %d byte tranformed", outrate);
        }
        else
        {
            printf("\n%d bytes transfered", bfilled);
            bfilled = 0;
        }
        printf("\npackets in the bucket %d byte\n", bfilled);
        i++;
    }
}