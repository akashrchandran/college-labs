#include <string.h>
#include <ctype.h>
#include <stdio.h>
struct states
{
    int ss;
    int sd;
    char a[3];
} st[25];
void main()
{
    int n, na, ns, i, j, z[15][15], r[30][30], t = 0, t1 = 0, t2 = 0, k;
    printf("Enter the number of states\n");
    scanf("%d", &ns);
    printf("Enter the number of alphabets including epsilon\n");
    scanf("%d", &na);
    printf("Enter the number of transitions\n");
    scanf("%d", &n);
    printf("\nHERE THE STATES STARTS FROM 1\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the source of %dth transitions ", i + 1);
        scanf("%d", &st[i].ss);
        printf("Enter the symbol of %dth transitions ", i + 1);
        scanf("%s", st[i].a);
        printf("Enter the destination of %dth transitions ", i + 1);
        scanf("%d", &st[i].sd);
    }
    for (j = 0; j < ns; j++)
    {
        z[j][t] = j + 1;
        t = 1;
        for (i = 0; i < n; i++)
        {
            if ((st[i].ss == (j + 1)) && (strcmp("e", st[i].a) == 0))
            {
                z[j][t] = st[i].sd;
                t = t + 1;
            }
        }
        z[j][t] = 0;
        t = 0;
    }
    for (j = 0; j < ns; j++)
    {
        t = 0;
        t2 = 0;
        while (z[j][t] > 0)
        {
            if (z[j][t] == j + 1)
            {
                r[j][t2] = z[j][t];
                t2 = t2 + 1;
            }
            else
            {
                t1 = 0;
                k = z[j][t];
                while (z[k - 1][t1] > 0)
                {
                    r[j][t2] = z[k - 1][t1];
                    t1 = t1 + 1;
                    t2 = t2 + 1;
                }
            }
            t = t + 1;
        }
        r[j][t2] = 0;
    }
    for (j = 0; j < ns; j++)
    {
        t = 0;
        t2 = 0;
        while (r[j][t] > 0)
        {
            if (r[j][t] == j + 1)
            {
                z[j][t2] = r[j][t];
                t2 = t2 + 1;
            }
            else
            {
                t1 = 0;
                k = r[j][t];
                while (r[k - 1][t1] > 0)
                {
                    z[j][t2] = r[k - 1][t1];
                    t1 = t1 + 1;
                    t2 = t2 + 1;
                }
            }
            t = t + 1;
        }
        z[j][t2] = 0;
    }
    for (j = 0; j < ns; j++)
    {
        t = 0;
        while (z[j][t] > 0)
        {
            t1 = t + 1;
            while (z[j][t1] > 0)
            {
                if (z[j][t] == z[j][t1])
                {
                    t2 = t1;
                    while (z[j][t2] > 0)
                    {
                        z[j][t2] = z[j][t2 + 1];
                        t2 = t2 + 1;
                    }
                }
                t1 = t1 + 1;
            }
            t = t + 1;
        }
    }
    for (j = 0; j < ns; j++)
    {
        t = 0;
        printf("e closure of q%d is {", j + 1);
        while (z[j][t] > 0)
        {
            printf("q%d ", z[j][t]);
            t = t + 1;
        }
        printf("}\n");
    }
}