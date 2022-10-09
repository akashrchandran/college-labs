#include <stdio.h>

int main()
{
	int pages, frames, i, j, flag, index = 0, hits = 0, faults = 0;
	printf("Enter the number of frames: ");
	scanf("%d", &frames);
	printf("Enter the number of pages: ");
	scanf("%d", &pages);
	int pages_array[pages], frames_array[frames];
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
			frames_array[index] = pages_array[i];
			faults++;
			index = (index + 1) % frames;
		}
	}
	printf("Total Page Faults: %d", faults);
	printf("\nTotal Page Hit: %d\n", hits);
}