//pre proccessor derivative
#include <stdio.h>

// read array elements from the user
void read_array(int array[], int n)
{   
    int i;
    for (i =0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
}

// display array elements
void display_array(int array[], int n)
{   
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%5d", array[i]);
    }
    printf("\n");
}


// Linear search algorithm code
int linear_Seach(int array[], int n, int key) {
    int i;
    int temp = 0;
    for (i = 0; i < n; i++) {
        if (key == array[i]) {
            temp = 1;
            break;
        }
    }
    return temp;
}

void main() {
    int n, key, result;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("\nEnter the array elements: \n");
    read_array(array, n);
    printf("\nThe array is: ");
    display_array(array, n);
    printf("\nEnter key to search: ");
    scanf("%d", &key);
    result = linear_Seach(array, n, key);
    if (result == 1) {
        printf("\nSearch Successfull\n");
    }
    else {
        printf("\nSearch Unsuccessfull\n");
    }
}