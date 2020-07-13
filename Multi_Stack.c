#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

bool isEmpty(struct node *s)
{
	return !s;
}

void dispLink(struct node *s)
{
	struct node *ptr;
	ptr = s;
	if(ptr == NULL)
	{
		printf("Nothing to display");
	}
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

int peek(struct node *s)
{
	if(isEmpty(s))
	{
		printf("\nLink list is empty\n");
		return ;
	}
	return s->data;
}

struct node* push(struct node *s, int l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = s;
	s = link;
	return s;
}

struct node* pop(struct node *s)
{
	if(isEmpty(s))
	{
		printf("\nLink list is empty; No elements can be popped\n");
		return ;
	}
	struct node *ptr = s;
	s = s->next ;
	free(ptr);
	return s;
}

main()
{
	struct node *s1=NULL;
	struct node *s2=NULL;
	s1 = push(s1, 19);
	s1 = push(s1, 13);
	s1 = push(s1, 103);
	s2 = push(s2, 29);
	s2 = push(s2, 39);
	s2 = push(s2, 10);
	printf("stack 1\n");
	dispLink(s1);
	printf("stack 2\n");
	dispLink(s2);
	s1 = pop(s1);
	s1 = pop(s1);
	s2 = pop(s2);
	printf("After popping\n");
	printf("stack 1\n");
	dispLink(s1);
	printf("stack 2\n");
	dispLink(s2);
	getch();
}
