#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

//at rear or last end
void enqueue(struct node **front, struct node **rear, int *s, int data)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = data;
	if(*front == NULL)
	{
		link->next = NULL;
		*front = link;
		*rear = link;
		*s= *s+1;
		return;
	}
	(*rear)->next = link;
	link->next = NULL;
	*rear =	link;
	*s = *s+1;
}

void dequeue(struct node **front, struct node **rear, int *s)
{
	if(*s==0)
	{
		printf("\nNo elements to be dequeued\n");
		return ;
	}
	if(*s==1)
	{
		free(*front);
		*front = NULL;
		*rear = NULL;
		*s = *s-1;
		return;
	}
	struct node *t=*front;
	*front = (*front)->next;
	free(t);
	*s = *s-1;
}

int peek(struct node **front, struct node **rear, int *s)
{
	return (*front)->data;
}

int isEmpty(struct node **front, struct node **rear, int *s)
{
	if(*s == 0)
	printf("\nQueue is empty\n");
	else
	printf("\nQueue is not empty\n");
}

void dispQueue(struct node **front, struct node **rear, int *s)
{
if(*s == 0)
{
printf("\nQueue is empty\n");
return ;
}
printf("\n       <==  ");
struct node *t = *front;
while(t != NULL)
{
printf(" %d ", t->data);
t = t->next;
}
printf("  <==\n");
}

main()
{
	struct node *f1=NULL, *r1=NULL, *f2=NULL, *r2=NULL;
    int s1=0, s2=0; 
    enqueue(&f1, &r1, &s1, 14);
    enqueue(&f1, &r1, &s1,12);
    enqueue(&f1, &r1, &s1,56);
    enqueue(&f2, &r2, &s2, 14);
    enqueue(&f2, &r2, &s2,12);
    enqueue(&f2, &r2, &s2,56);
    dequeue(&f1, &r1, &s1);
    dispQueue(&f1, &r1, &s1);
    dispQueue(&f1, &r1, &s1);
    printf("\n");
    dispQueue(&f2, &r2, &s2);
    dispQueue(&f2, &r2, &s2);
    getch();
}
