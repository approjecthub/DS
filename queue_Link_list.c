#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *front=NULL, *rear=NULL;
int s=0;

//at rear or last end
void enqueue(int l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	if(front == NULL)
	{
		link->next = NULL;
		front = link;
		rear = link;
		s++;
		return;
	}
	rear->next = link;
	link->next = NULL;
	rear =	link;
	s++;
}

void dequeue()
{
	if(s==0)
	{
		printf("\nNo elements to be dequeued\n");
		return ;
	}
	if(s==1)
	{
		free(front);
		front = NULL;
		rear = NULL;
		s--;
		return;
	}
	struct node *t=front;
	front = front->next;
	free(t);
	s--;
}

int peek()
{
	return front->data;
}

int isEmpty()
{
	if(s == 0)
	{
		printf("\nQueue is empty\n");
		return s;
	}
	else
	{
		printf("\nQueue is not empty\n");
		return s;
	}
}

void dispQueue()
{
if(s == 0)
{
printf("\nQueue is empty\n");
return ;
}
struct node *d = front;
printf("\n       <==  ");
while(d != NULL)
{
printf(" %d ", d->data);
d = d->next;
}
printf("  <==\n");
}

main()
{	
    enqueue(14);
    enqueue(12);
    enqueue(56);
    dequeue();
    enqueue(16);
   dispQueue();
    getch();

}
