#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct poly
{
	int coef, exp;
	struct poly *next;
};

void sort(struct poly *h1, size)
{
	struct poly *current, *next;
	int i, j, k;
	struct poly *t;
	k = size;
	for(i=0; i<size-1; i++, k--)
	{
		current = h1;
		next = current->next;
		for(j=1; j<k; j++)
		{
			if(current->exp < next->exp)
			{
				t->exp = current->exp;
				t->coef = current->coef;
				current->exp = next->exp;
				current->coef = next->coef;
				next->exp = t->exp;
				next->coef = t->coef;
			}
				current = current->next;
				next = next->next;
		}
	}
}

int insertLinkLast(struct poly *p )
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

