#include <stdio.h>


void read_array(int array[], int n)
{   
    int i;
    for (i =0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

void display_array(int array[], int n)
{   
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%5d", array[i]);
    }
    printf("\n");
}

void bubble_sort(int array[], int n)
{   
    int i,j, temp;
    for (i = 0; i < (n-1); i++)
    {
        for (j =0; j < (n-i-1); j++)
        {
            if (array[j] > array[j+1])
            {   
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        } 
    }
}
void main()
{   
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the array elements: \n");
    read_array(array, n);
    printf("\nThe array is: ");
    display_array(array, n);
    bubble_sort(array, n);
    printf("\nSorted Array is: ");
    display_array(array, n);

}