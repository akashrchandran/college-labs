#include <stdio.h>

int main()
{
	int pages, frames, i, j, flag, pos, hits = 0, faults = 0;
	printf("Enter the number of frames: ");
	scanf("%d", &frames);
	printf("Enter the number of pages: ");
	scanf("%d", &pages);
	int pages_array[pages], frames_array[frames], distance[pages];
	printf("Enter the reference string: ");
	for (i = 0; i < pages; i++)
		scanf("%d", &pages_array[i]);
	for (i = 0; i < pages; i++)	{
		flag = 0;
		for (j = 0; j < frames; j++)	{
			if (pages_array[i] == frames_array[j])	{
				hits++;
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			int max = -1;
            int index;
            for (int j = 0; j < frames; j++)
            {
                distance[j] = 0;
                for(int k = i - 1; k >= 0; k--)
                {
                    distance[j]++;
                    if(frames_array[j] == pages_array[k])
                        break;
                }
                if(distance[j] > max){
                    max = distance[j];
                    index = j;
                }
            }
            frames_array[index] = pages_array[i];
            faults++;
		}
	}
	printf("Total Page Faults: %d", faults);
	printf("\nTotal Page Hit: %d\n", hits);
}