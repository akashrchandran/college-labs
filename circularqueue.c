#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int CQ[25];
int front = -1;
int rear = -1;

void enqueue(int item)
{   
    /* Two cases are exist
    * if front is equal to -1, then set front and rear pointing to 1
    * and next is qual to Size mod length plus 1 and check if its equal to front if not equal to front insert element or the queue is full
    */
    int next;
    if (front == -1)
    {
        front = rear = 1;
        CQ[front] = item;
    }
    else
    {   
        next = (rear % SIZE) + 1;
        if(next != front)
        {
            rear = next;
            CQ[rear] = item;
        }
        else
        {
            printf("Queue is full!!\n");
        }
    }
}

int dequeue()
{   
    int item;
    if (front == -1)
    {
        printf("Queue is Empty!\n");
        item = -1;
    }
    else
    {
        item = CQ[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front % SIZE) + 1;
        }
    }
    return item;
}


void display_queue()
{
    int i = front;
    while (i != rear)
    {
        printf("%5d", CQ[i]);
        i = (i % SIZE) + 1;
    }
    printf("%5d", CQ[i]);
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
