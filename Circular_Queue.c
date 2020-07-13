#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *rear=NULL;

bool isEmpty()
{
	return !rear;
}

int peek()
{
	if(isEmpty())
	{
		printf("\nTop element is NULL\n");
		return;
	}
	return rear->next->data;
}

void enqueue(int l1)
{
	if(isEmpty())
	{
		struct node *link = (struct node*) malloc(sizeof(struct node));
		link->data = l1;
		link->next = link;
		rear = link;
		return;
	}
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = rear->next;
	rear->next = link;
	rear = link;
}

void dequeue()
{
	if(isEmpty())
	{
		printf("\nQueue is empty\n");
		return;
	}
	if(rear->next == rear)
	{
		free(rear);
		rear = NULL;
		return;
	}
	struct node *t = rear->next;
	rear->next = t->next;
	free(t);
}

void dispQueue()
{
if(isEmpty())
{
printf("\nQueue is empty\n");
return ;
}
struct node *d = rear->next;
printf("\n       <==  ");
do
{
printf(" %d ", d->data);
d = d->next;
}
while(d != rear->next);
printf("  <==\n");
}

main()
{
	enqueue(23);
	enqueue(48);
	enqueue(13);
	dispQueue();
	dequeue();
	dequeue();
	dispQueue();
	printf(" %d ",peek());
	getch();
}
