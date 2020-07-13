#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//creation of link list
struct node
{
	int data;
	struct node *next;
};

struct node *head = NULL;

void insertLinkFirst(int l1)
{
	struct node *link = (struct node*) malloc(sizeof(struct node));
	link->data = l1;
	link->next = head;
	head = link;
}

void insertLinkLast(int l2)
{
	struct node *link = (struct node*) malloc(sizeof(struct node)), *current;
	link->data = l2;
	link->next = NULL;
	current = head;
	while(current->next != NULL )
	{
		current = current->next;
	}
	current->next = link;
}

void insertLinkSpecific(int l3, int p)
{
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
int i=1;
struct node *link = (struct node*) malloc(sizeof(struct node)), *current, *lost;
link->data = l3;
current = head;
		while(current != NULL && i<p-1)
	{
		current = current->next;
		i++;
	}
	lost = current->next;
	current->next = link;
	link->next = lost;
}

//size of the link list
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

//display the link list
void dispLink()
{
	struct node *ptr;
	ptr = head;
	printf("\nhead => ");
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("=> Null\n");
}

//reverse the link list
void reverse()
{
	struct node *current, *prev, *lost;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		lost = current->next;
		current->next = prev;
		prev = current;
		current = lost;
	}
	head = prev;
}

//delete the first node
void deleteFirstLink()
{
	struct node *current;
	current = head;
	head = current->next;
	free(current);
}

void deleteLastLink()
{
	struct node *current, *lost;
	current= head;
	int i;
	for(i=0; i<size()-2; i++)
	{
		current = current->next;
	}
	lost = current->next;
	current->next = NULL;
	free(lost);
}

void deleteParticularLink(int l4)
{
	if(search(l4) == 0)
	return;	
	struct node *current, *prev;
	current = head;
	prev = NULL;
	if(l4 == current->data)
	{
	deleteFirstLink();
	return;	
	}
	while(current != NULL)
	{
		if(current->data == l4)
		{
		prev->next = current->next;
		free(current);
		return;
	}
	else
	{
		prev = current;
		current = current->next;
	}
	}		
}

//sorting(bubble sort) the elements in acsending order
void sort()
{
	struct node *current, *next;
	int i, j, k, t;
	k = size();
	for(i=0; i<size()-1; i++, k--)
	{
		current = head;
		next = current->next;
		for(j=1; j<k; j++)
		{
			if(current->data > next->data)
			{
				t = current->data;
				current->data = next->data;
				next->data = t;
			}
				current = current->next;
				next = next->next;
		}
	}
}

//Insert a link in a Sorted link list
void insertLink_in_SortedList(int l5)
{
	struct node *link = (struct node*) malloc(sizeof(struct node)), *current, *prev;
	int i=0;
	link->data = l5;
	current = head;
	prev = NULL;
	if(l5 <= head->data)
	{
		insertLinkFirst(l5);
		free(link);
		return;
	}
	while(current != NULL)
	{
		if(l5 <= current->data)
		{
			i++;
			break;
		}
		prev = current;
		current = current->next;
	}
	if(i == 0)
	{
		prev->next = link;
		link->next = NULL;
	}
	else if(i == 1)
	{
		prev->next = link;
		link->next = current;
	} 
}

//Update an existing element
void update(int l6, int p2)
{
	if( p2>0 && p2<= size())
	{
		struct node *d;
		int h;
		d = head;
		for(h=1; h<p2; h++)
		{
			d = d->next;
		}
		d->data = l6;
	}
	else
	printf("%d is an invalid location", p2);
}

//Search an element within the list
int search(int l7)
{
	struct node *c;
	c = head;
	while(c != NULL)
	{
		if(l7 == c->data)
		{
			printf("%d is found", l7);
			return 1;
		}
		c = c->next;
	}
	printf("%d is not found", l7);
	return 0;
}
//main function
main()
{int option, d, p, m;
do
{
printf("\n 1: Display the list");
printf("\n 2: Add a node at a particular position");
printf("\n 3: Add a node in a sorted list");
printf("\n 4: Delete a particular node");
printf("\n 5: EXIT");
printf("\n\n Enter your option : ");
scanf("%d", &option);
switch(option)
{
case 1: dispLink();
break;
case 2: printf("\nEnter the data and position");
scanf("%d %d", &d, &p);
insertLinkSpecific(d, p);
break;
case 3: sort();
printf("\nEnter the data");
scanf("%d", &d);
insertLink_in_SortedList(d);
break;
case 4: printf("\nEnter the element you want to delete");
scanf("%d", &d);
deleteParticularLink(d);
break;
}
}while(option !=5);
getch();
}
