#include <stdio.h>
#include <stdlib>

#define SIZE 5
int front, rear = -1;
int Q[25];

void enqueue(int item)
{
	/* Three cases to be handled
	 * queue is full condtion
	 * on first insertion  or front = rear = -1 then front and rear must set to zero
	 * Insert elemets to queue and update the pointers
	 */
	if (rear == SIZE - 1)
	{
		printf("The Queue is full!\n");
	}
	else
	{
		if (front == -1 && rear == -1)
		{
			front = 0;
		}
		Q[++rear] = item;
	}
}

int dequeue()
{
	/* Three conditons to be checked
	* Check if the queue is empty
	* if front = rear the set bot to -1
	* delete an element from the front of the queue and update front
	*/
	int item;
	if (front == -1)
	{
		printf("The Queue is empty!\n");
		item = -1;
	}
	else
	{	
		item = Q[front];
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
	}
}

void display_queue()
{
	int i = front;
	while (i <= rear)
	{
		printf("%5d", Q[i]);
		i++;
	}
	printf("\n");
}

void main()
{
	int choice, item;
	while (1)
	{
		printf("Choose the operation you want to perfrom:-");
		printf("\n");
		printf("Choice 1: ENQUEUE\n");
		printf("Choice 2: DEQUEUE\n");
		printf("Choice 3: EXIT\n");
		printf("\n");
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice)
		{
		case 1:
			printf("Enter the element to be enqueued: ");
			scanf("%d", &item);
			enqueue(item);
			break;
		case 2:
			item = dequeue();
			printf("The dequeued element is: %d", item);
			break;
		case 3:
			exit(1);
		default:
			continue;
		}
		printf("\nThe updated queue is: ");
		display_queue();
		printf("\n");
	}
}
