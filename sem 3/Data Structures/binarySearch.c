#include <stdio.h>
// binarySearch.c

int binarySearch(int first, int last, int list[], int target, int loc)
{   
    int found = 0, mid;
    while (first <= last)
        {
            mid = (first + last) / 2;
            if (list[mid] > target)
                first = mid + 1;
            else if (list[mid] < target)
                last = mid - 1;
            else
                found = 1;
                loc = mid;
                break;
        }
    if (found == 1)
        return found;
    else
        found = -1;
        return found;
}


void main()
{
    int a[] = {1, 2, 3,4,5, 6,7};
    int last = 7;
    int first = 1;
    int target = 3;
    int loc;
    int result = binarySearch(first, last, a, target, loc);
    printf("%d", result);
}
