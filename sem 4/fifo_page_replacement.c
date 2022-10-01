// C program for FIFO page replacement algorithm
#include <stdio.h>
int main()
{
    int pageFaults = 0;
    int m, i, n, s, pages, no_of_pages, frames;
	printf("Enter number of frames: ");
	scanf("%d", &frames);
	printf("Enter number of pages: ");
	scanf("%d", &no_of_pages);
    int incomingStream[no_of_pages];
	printf("Enter reference string: ");
    for(i = 0; i < no_of_pages; ++i){
     scanf("%d", &incomingStream[i]);
    }
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);

    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3");
    int temp[frames];
    for(m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for(m = 0; m < pages; m++)
    {
        s = 0;

        for(n = 0; n < frames; n++)
        {
            if(incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        
        if((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if(s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }
      
        printf("\n");
        printf("%d\t\t\t",incomingStream[m]);
        for(n = 0; n < frames; n++)
        {
            if(temp[n] != -1)
                printf(" %d\t\t\t", temp[n]);
            else
                printf(" - \t\t\t");
        }
    }

    printf("\nTotal Page Faults:\t%d", pageFaults);+
	printf("\nTotal Page Hit = %d\n", no_of_pages - pageFaults);
    return 0;
}
