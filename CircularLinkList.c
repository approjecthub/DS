#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *last = NULL;

bool isEmpty()
{
	return !last;
}

void display()
{
	if(isEmpty()){
		printf("\nList is empty\n");
	}
	else
	{
		struct node *ptr = last->next ;
		printf("\n");
		do
		{
			printf(" %d ", ptr->data);
			ptr = ptr->next ;
			}
			while(ptr != last->next);	
			printf("\n");
	}
}

void insert_in_EmptyList(int l3)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l3;
	link->next = link;
	last = link;
}

void insertLinkFirst(int l1)
{
	if(isEmpty())
	{
		insert_in_EmptyList(l1);
		return;
	}
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = last->next;
	last->next = link;
}


void insertLinkLast(int l2)
{
	if(isEmpty())
	{
		insert_in_EmptyList(l2);
		return;
	}
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l2;
	link->next = last->next;
	last->next = link;
	last = link;
}

void insertBeforeLink(int l5, int l6)
{
	if(isEmpty())
	{
		insert_in_EmptyList(l6);
		return;
	}
	struct node *p, *t=NULL;
	p = last->next;
	if(p->data == l5)
	{
		insertLinkFirst(l6);
		return;
	}
	t = p;
	p = p->next;
	do
	{
		if(p->data == l5)
		{
		struct node *link = (struct node*) malloc(sizeof(struct node));
		link->data = l6;
		t->next = link;
		link->next = p;
		break;	
		}
		else
		{
	t = p;
	p = p->next;
			
		}
	}
	while(p != last->next);
}

void deletParticularLink(int l4)
{
	struct node *ptr= last->next, *d=last, *c ;
	//if the list is empty
	if(isEmpty())
	{
		printf("\nList is empty; Nothing can be deleted\n");
		return;
	}
	//if the link list contains only one noode
	else if(ptr == d && d->data == l4)
	{
		free(d);
		last = NULL;
		return;
	}
	//if the required link is first node
	else if(ptr->data == l4)
	{
		d->next = ptr->next;
		free(ptr);
		return;
	}
	c = ptr;
	ptr = ptr->next;
	printf("\nbl %d\n", ptr->data);
	while(ptr != last)
	{
		if(ptr->data == l4)
		{
			c->next = ptr->next;
			("\n%d is deleted\n", ptr->data);
			free(ptr);
			return;
		}
		else
		c = ptr;
		ptr = ptr->next;
	}
	printf("\nal p=%d, c=%d", ptr->data, c->data);
	if(last->data == l4)
	{
		c->next = ptr->next;
		free(ptr);
		last = c;
	}
}

void deletLinkAfter(int l7)
{
		if(isEmpty())
	{
		printf("\nList is empty; Nothing can be deleted\n");
		return;
	}
	if(last->data == l7)
	{
		printf("\nNo element to be deleted\n");
		return;
	}
	struct node *t, *d;
	t = last->next;
	d = t->next;
	do
	{
		if(t->data == l7)
		{
			t->next = d->next;
			if(d->data == last->data)
			{
				last = t;
			}
			free(d) ;
			break;
		}
		else
		{
			t = t->next;
			d = d->next;
		}
	}
	while(t != last->next);
}

void deletLinkBefore(int l8)
{
	if(isEmpty())
	{
		printf("\nList is empty; Nothing can be deleted\n");
		return;
	}
	if(last->next->data == l8)
	{
		printf("\nNo existing nodes before head to be deleted\n");
		return ; 
	}
	struct node *t, *d;
	d = last;
	t = d->next->next;
	do 
	{
		if(t->data == l8)
		{
			free(d->next);
		d->next = t;
		break;
		}
		else
		{
			d = d->next ;
			t = t->next ;
		}
	}
	while(t != last->next);
}

void reverse()
{
	if(isEmpty())
	{
		printf("\nList is empty!\n");
		return;
	}	
	struct node *current, *prev, *lost, *head= last->next;
	current = head;
	prev = last;
	do
	{
		lost = current->next;
		current->next = prev;
		prev = current;
		current = lost;
	}
	while(current != head);
	
	//head = prev;
	last = current;
}

main()
{
	insertLinkLast(25);
	insertLinkLast(16);
	insertLinkLast(18);
	insertLinkFirst(15);
	insertLinkFirst(17);
	insertBeforeLink(17,19);
	display();
	deletLinkAfter(16);
	display();
	deletLinkBefore(17);
	display();
	reverse();
	display();
	getch();
}
