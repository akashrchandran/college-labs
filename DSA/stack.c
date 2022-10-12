#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int a[25];
int top = -1;

void push(int item)
{
	/* Two cases to be handled
	 * If stack is full
	 * Insert element into stack
	 */
	if (top >= SIZE - 1)
	{
		printf("Error: Stack is Full!\n");
	}
	else
	{
		top++;
		a[top] = item;
	}
}

int pop(void)
{
	/* Two cases to be handled
	 * Stack is empty :element cannot be deleted anymore
	 * Delete an element from stack
	 */
	int item;
	if (top < 0)
	{
		printf("Error: Stack is Empty\n");
		item = -1;
	}
	else
	{
		item = a[top--];
	}

	return item;
}

void display_stack()
{	
	int i = 0;
	while (i <= top)
	{
		printf("%5d", a[i]);
		i++;
	}
	printf("\n");
}

void main()
{	int choice, item;
	while (1)
	{
		printf("Choose the operation you want to perfrom:-");
		printf("\n");
		printf("Choice 1: PUSH\n");
		printf("Choice 2: POP\n");
		printf("Choice 3: EXIT\n");
		printf("\n");
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("Enter the element to be pushed: ");
			scanf("%d", &item);
			push(item);
			break;
		case 2:
			item = pop();
			printf("The poped element is: %d", item);
			break;
		case 3:
			exit(1);
		default:
			continue;
		}
		printf("\nThe updated stack is: ");
		display_stack();
		printf("\n");
	}
}