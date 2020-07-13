#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

bool isEmpty()
{
	return !head;
}

void dispLink()
{
	struct node *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		printf("\n%d\n", ptr->data);
		ptr = ptr->next;
	}
}

int peek()
{
	if(isEmpty())
	{
		printf("\nLink list is empty\n");
		return ;
	}
	return head->data;
}

void push(int l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = head;
	head = link;
}

int pop()
{
	int popped = head->data;
	struct node *ptr = head;
	if(isEmpty())
	{
		printf("\nLink list is empty; No elements can be popped\n");
		return ;
	}
	head = head->next ;
	free(ptr);
	return popped;
}

main()
{
	push(12);
	pop();
	printf("%d", peek());
	getch();
}
