/* CIRCULAR DOUBLY LINKED LIST*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;
node *start=NULL,*tail=NULL;
void insert_front();
void insert_last();
void insert_pos();
void display();
void head_to_tail();
void tail_to_head();
void delet_begin();
void delet_end();
void delet_pos();
void linear_search();
int num_of_eles=0;
int main()
{
	int choice;
	time_t now =time(NULL);
	char *str=ctime(&now);
	printf("\nGMT +5.30hrs\n");
	printf("%s\n",str);
	while(1)
	{
		printf("\nDoubly Circular Linked List\n");
		printf("\n1.Insert front\n");
		printf("\n2.Insert last\n");
		printf("\n3.Insert in position\n");
		printf("\n4.Display\n");
		printf("\n5.Delete front\n");
		printf("\n6.Delete last\n");
		printf("\n7.Delete position\n");
		printf("\n8.Linear Search an element\n");
		printf("\n9.Exit the code\n");
		printf("\nEnter the option:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				insert_pos();
				break;
			case 4:
				display();
				break;
			case 5:
				delet_begin();
				break;
			case 6:
				delet_end();
				break;
			case 7:
				delet_pos();
				break;
			case 8:
				linear_search();
				break;
			case 9:
				sleep(1);
				printf("\nExiting the code\n");
				sleep(1);
				exit(0);
			default:
				sleep(1);
				printf("\nWrong option entered.\n");
				sleep(1);
				printf("\nPlease choose again from the the following options\n");
				break;
		}
	}
	return 0;
}
void insert_last()
{
	node *ptr,*temp;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nMemory allocation failure\nExiting code\n");
		sleep(1);
		exit(0);
	}
	printf("\nEnter the data:\n");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	if(tail==NULL)
	{
		ptr->next=ptr;
		ptr->prev=ptr;
		tail=ptr;
	}
	if(start==NULL)
	{
		ptr->prev=ptr;
		ptr->next=ptr;
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		start->prev=ptr;
		ptr->next=start;
		tail=ptr;
	}
	num_of_eles++;
}// ptr <--[ ] [temp]   <-->      [ ]-->start
void insert_front()
{
	node *ptr,*temp;
	ptr=(node *)malloc(sizeof(node));
	if(ptr==NULL)
	{
		printf("\nMemory allocation failure\nExiting code\n");
		sleep(1);
		exit(0);
	}
	printf("\nEnter the data:\n");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	ptr->prev=NULL;
	if(start==NULL)
	{
		ptr->prev=ptr;
		ptr->next=ptr;
		start=ptr;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->prev=temp;
		start->prev=ptr;
		ptr->next=start;
		start=ptr;
		
	}
	num_of_eles++;
}
void display()
{
	int ch;
	printf("\n1.Print from head to tail\n");
	printf("\n2.Print from tail to head\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			head_to_tail();
			break;
		case 2:
			tail_to_head();
			break;
		default:
			printf("\nWrong option taken!\n");
			break;
	}
	if(num_of_eles>1)
	{
		printf("\nThere are a total of %d elements in the list\n",num_of_eles);
	}
	else
	{
		printf("\nThere is only %d element in the list\n",num_of_eles);
	}
}
void head_to_tail()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else
	{
		node *ptr;
		ptr=start;
		printf("\n\nHEAD --> %d\n",ptr->data);
		printf("\nList of elements are:\n");
		while(ptr->next!=start)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
		printf("TAIL--> %d\n",ptr->data);
	}
}
void tail_to_head()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else
	{
		node *ptr;
		ptr=tail;
		printf("\n\nTAIL--> %d\n",ptr->data);
		printf("\nList of elements are:\n");
		while(ptr->prev!=tail)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->prev;
		}
		printf("HEAD--> %d\n",ptr->data);
	}
}
void linear_search()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else
	{
		node *ptr;
		int flag=0,location=0,data;
		printf("\nEnter the data you want to search:\n");
		scanf("%d",&data);
		if(tail->data==data)
		{
			printf("\nData was found in the list at last location \n");
		}
		else if(start->data==data)
		{
			printf("\nData was found in the list at frist location\n");
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
			{
				if(ptr->data==data)
				{
					printf("\nData found at loaction %d\n",location+1);
					flag=0;
					break;
				}
				else
				{
					flag=1;
				}
				location++;
				ptr=ptr->next;
			}
			if(flag!=0)
			{
				printf("\nData was not found\n");
			}
		}
	}
}
void insert_pos()
{
	node *ptr,*temp;
	ptr=(node *)malloc(sizeof(node));
	int pos;
	printf("Enter the place you want ot insert data in :\n");
	scanf("%d",&pos);
	if(pos==1||pos==0)
	{
		insert_front();
	}
	else if(pos==num_of_eles)
	{
		insert_last();
	}
	else
	{
		printf("Enter the data you want to insert:\n");
		scanf("%d",&ptr->data);
		ptr->next=NULL;
		ptr->prev=NULL;
		int i;
		temp=start;
		for(i=0;i<pos-2;i++)
		{
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
		ptr->prev=temp;
		temp->next=ptr;
	}
}
void delet_begin()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else if(start->next==start&&start->prev==start)
	{
		node *ptr;
		ptr=start;
		start=NULL;
		tail=NULL;
		free(start);
		free(tail);
		printf("\nData deleted is %d\n",ptr->data);
		free(ptr);
		--num_of_eles;
		if(num_of_eles>1)
	{
		printf("\nThere are a total of %d elements in the list\n",num_of_eles);
	}
	else
	{
		printf("\nThere is only %d element in the list\n",num_of_eles);
	}
	}
	else
	{
		node *ptr;
		ptr=start;
		tail->next=start->next;
		start->next->prev=tail;
		start=start->next;
		printf("Data deleted is %d",ptr->data);
		free(ptr);
		--num_of_eles;
		if(num_of_eles>1)
	{
		printf("\nThere are a total of %d elements in the list\n",num_of_eles);
	}
	else
	{
		printf("\nThere is only %d element in the list\n",num_of_eles);
	}
	}
}
void delet_end()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else if(start->next==start&&start->prev==start)
	{
		node *ptr;
		ptr=start;
		start=NULL;
		tail=NULL;
		printf("Data deleted is %d \n",ptr->data);
		free(start);
		free(tail);
		free(ptr);
		--num_of_eles;
		if(num_of_eles>1)
		{
			printf("\nThere are a total of %d elements in the list\n",num_of_eles);
		}
		else
		{
			printf("\nThere is only %d element in the list\n",num_of_eles);
		}
	}
	else
	{
		node *ptr;
		ptr=tail;
		start->prev=tail->prev;
		tail->prev->next=start;
		tail=tail->prev;
		printf("\nData deleted is %d\n",ptr->data);
		free(ptr);
		--num_of_eles;
		if(num_of_eles>1)
	{
		printf("\nThere are a total of %d elements in the list\n",num_of_eles);
	}
	else
	{
		printf("\nThere is only %d element in the list\n",num_of_eles);
	}
	}
}
void delet_pos()
{
	if(start==NULL)
	{
		int ch;
		printf("\nList is empty\n");
		printf("\nChoose any option\n");
		printf("\n1.Insert front\n");
		printf("\n2.insert end\n");
		printf("\nExit the code\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_last();
				break;
			case 3:
				printf("\nExiting the code\n");
				exit(0);
			default:
				printf("\nWrong option taken\n");
				break;
		}
	}
	else if(start->next==start&&start->prev==start)
	{
		node *ptr;
		ptr=tail;
		start->prev=tail->prev;
		tail->prev->next=start;
		tail=tail->prev;
		printf("\nData deleted is %d\n",ptr->data);
		free(ptr);
		--num_of_eles;
		if(num_of_eles>1)
		{
			printf("\nThere are a total of %d elements in the list\n",num_of_eles);
		}
		else
		{
			printf("\nThere is only %d element in the list\n",num_of_eles);
		}
	}
	else
	{	int pos;
		printf("\nEnter the place you want to delete:\n");
		scanf("%d",&pos);
		if(pos==0||pos==1)
		{
			delet_begin();
		}
		else if(pos==num_of_eles)
		{
			delet_end();
		}
		else if(pos>num_of_eles)
		{
			printf("\nOut of range\n");
		}
		else
		{	
			int i;
			node *ptr;
			ptr=start;
			for(i=1;i<pos-1;i++)
			{
				ptr=ptr->next;
			}
			node *hold=ptr->next;
			ptr->next->next->prev=ptr;
			ptr->next=ptr->next->next;
			printf("\nData deleted is %d\n",hold->data);
			free(hold);
		}
	}
}
