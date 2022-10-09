#include <stdio.h>

int main()
{
	int pages, frames, frequency[10], i, j, flag, index = 0, hits = 0, faults = 0;
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
				frequency[pages_array[i]]++;
				break;
			}
		}
		if (flag == 0) {
			int pos = i, freq = frequency[pages_array[i]];
			for (int k = i - 1; k > 0; k--)
			{
				if (frequency[pages_array[k]] <= freq) {
					pos = k;
				}
			}
			printf("%d", frames_array[pos]);
			frequency[frames_array[pos]]--;
			frames_array[pos] = pages_array[i];
			faults++;
		}
	}
	printf("Total Page Faults: %d", faults);
	printf("\nTotal Page Hit: %d\n", hits);
}