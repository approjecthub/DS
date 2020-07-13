#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL;

void insertLinkFirst(int l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	if(head == NULL)
	{
		link->data = l1;
		link->prev = NULL;
		link->next = NULL;
	}
	else
	{
		link->data = l1;
		link->prev = NULL;
		link->next = head;
		head->prev = link;
	}
	head = link;
}

void insertLinkLast(int l2)
{
	struct node *link = (struct node*) malloc(sizeof(struct node)), *current;
	link->data = l2;
	link->prev = NULL;
	current = head;
	if(current == NULL)
	{
		head = link;
		return;
	}
	while(current->next != NULL )
	{
		current = current->next;
	}
	current->next = link;
	link->prev = current;
	link->next = NULL;
}

void insertLinkSpecific(int l3, int p)
{
int i=1;
if(head == NULL || p == 1)
{
	insertLinkFirst( l3);
	return;
}
else if(p > size()+1)
{
	printf("\ninvalid location\n");
	return ;
}
else if(p == size()+1)
{
	insertLinkLast(l3);
	return;
}
struct node *link = (struct node*) malloc(sizeof(struct node)), *current;
link->data = l3;
current = head;
		while(i<p-1)
	{
		current = current->next;
		i++;
	}
	link->next = current->next;
	link->prev = current;
	current->next->prev = link;
	current->next = link;
}

void insertBeforeParticularNode(int l4, int l5)
{
	int l, r;
	r = search(l4);
	printf("\ni = %d\n", r);
	struct node *current, *link;
	current = head;
	link = NULL;
	if(r == 0)
	{
	printf("%d dose not exist\n%d can not be inserted after %d\n", l4, l5, l4);
	return;	
	}
	else if(r == 1)
	{
		insertLinkFirst(l5);
		return;
	}
	else if(r>1)
	{
		link = (struct node*) malloc(sizeof(struct node));
		link->data = l5;
		for(l=1; l<r-1; l++)
		{
			current = current->next;
		}
		link->next = current->next;
		link->prev = current;
		current->next->prev = link;
		current->next = link;
	}
}

void insertAfterParticularNode(int l6, int l7)
{
	int l, r;
	r = search(l6);
	struct node *current, *link;
	current = head;
	link = NULL;
	if(r == 0)
	{
	printf("%d dose not exist\n%d can not be inserted after %d\n", l6, l7, l6);
	return;	
	}
	else if(r == 1)
	{
		link = (struct node*) malloc(sizeof(struct node));
		link->data = l7;
		link->next = current->next;
		link->prev = current;
		current->next->prev = link;
		current->next = link;
		return;
	}
	else if(r>1)
	{
		link = (struct node*) malloc(sizeof(struct node));
		link->data = l7;
		for(l=1; l<r; l++)
		{
			current = current->next;
		}
		if(current->next == NULL)
		{
			insertLinkLast(l7);
			return;
		}
		link->next = current->next;
		current->next->prev = link;
		link->prev = current;
		current->next = link;
		printf("%d", current->data);
	}	
}

int search(int l8)
{
	int i=0;
	struct node *current;
	current = head;
	while(current != NULL)
	{
		i++;
		if(current->data == l8)
		{
			return i;
		}
		current = current->next ; 
	}
	return 0;
}

int size()
{
	int i=0;
	struct node *current;
	current = head;
	while(current != NULL)
	{
		current = current->next;
		i++;
	}
	return i;
}

void dispLink()
{
	struct node *ptr;
	ptr = head;
	printf("\nhead => ");
	while(ptr != NULL)
	{
		printf(" %d ", ptr->data);
		ptr = ptr->next;
	}
	printf("=> Null\n");
}

void reverseDisp()
{
	struct node *current;
	current = head;
	if(current == NULL)
	{
		printf("\nList is empty\n");
		return;
	}
		while(current->next != NULL)
	{
		current = current->next;
	}
	printf("\nReversed list\n");
	while(current != NULL)
	{
		printf(" %d ", current->data);
		current = current->prev;
	}
}

void deleteFirstLink()
{
	struct node *current;
	current = head;
	if(current == NULL)
	{
		printf("\nUnderflow\n");
		return;
	}
		else
		{	
		if(current->next == NULL)
		{
			free(current);
			head = NULL;
			}	
			else{
	head = current->next;
	head->prev = NULL;
	free(current);
		}
}
}

void deleteLastLink()
{
    struct node *current;
	current = head;
	if(current == NULL)
	{
		printf("\nUnderflow\n");
		return;
	}
		else
		{
				while(current->next != NULL)
				{
					current = current->next;
				}
				if(current->prev == NULL)
				{
					free(current);
					head = NULL;
					return;
				}
				current->prev->next = NULL;
				free(current);		
}
}

main()
{
	insertLinkFirst(23);
	insertLinkLast(26);
	insertLinkSpecific(13, 3);
	insertBeforeParticularNode( 13, 17);
	insertAfterParticularNode(13, 100);
	dispLink();
	reverseDisp();
	deleteLastLink();
	dispLink();
	reverseDisp();
	getch();
}
