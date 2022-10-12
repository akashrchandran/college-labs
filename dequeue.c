#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int DQ[25];
int front = -1;
int rear = -1;

void insertFront(int item)
{
	if ((front == 0 && rear == SIZE - 1) || (front  == rear + 1))
	{
		printf("Queue is Full");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (front == 0)
		{
			front = SIZE - 1;
		}
		else
		{
			front--;
		}
	DQ[front] = item;
	}
}


void insertRear(int item)
{
	if ((front == 0 && rear == SIZE - 1) || (front  == rear + 1))
	{
		printf("Queue is Full");
	}
	else
	{
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else if (rear == SIZE - 1)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}
	DQ[rear] = item;
	}
}

int deleteFront()
{
	int item;
	if(front == -1)
	{
		printf("Queue is Empty!");
		item = -1;
	}
	else
	{	
		item = DQ[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (front = SIZE - 1)
		{
			front = 0;
		}
		else
		{
			front++;
		}
	}
	return item;
}

int deleteRear()
{
	int item;
	if(front == -1)
	{
		printf("Queue is Empty!");
		item = -1;
	}
	else
	{	
		item = DQ[rear];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else if (rear = 0)
		{
			rear = SIZE - 1;
		}
		else
		{
			rear--;
		}
	}
	return item;
}

void display_queue()
{
	int i = front;
	while (i != rear)
	{
		printf("%5d", DQ[i]);
		if (i == SIZE -1)
		{
			i = 0;
		}
		else
		{
			i = i % SIZE + 1;
		}
	}
	printf("%5d", DQ[i]);
	printf("\n");
}



int main()
{
	insertFront(10);
	display_queue();
	insertFront(20);
	display_queue();
	insertRear(30);
	display_queue();
	insertRear(40);
	display_queue();
	deleteFront();
	display_queue();
	deleteFront();
	display_queue();
	deleteRear();
	display_queue();
	deleteRear();
	display_queue();
}
