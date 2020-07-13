#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int coe, exp;
	struct node *next;
};

struct node *create(struct node *l, int c, int e)
{
	struct node *link = (struct node*) malloc(sizeof(struct node)), *l1 = l;
	link->coe = c;
	link->exp = e;
	link->next = NULL;
	if(l1 == NULL)
	{
		l1 = link;
		return l1;
	}
	while(l1->next != NULL)
	{
		l1 = l1->next;
	}
	l1->next = link;
	return l;
}

void dispList(struct node *l)
{
	struct node *l1=l;
	while(l1 != NULL)
	{
		printf(" %dX%d ", l1->coe, l1->exp);
		l1 = l1->next;
	}
}

int size(struct node *l)
{
	int i=0;
	while(l != NULL)
	{
		i++;
		l = l->next;
	}
	return i;
}

struct node *add(struct node *ll1, struct node *ll2)
{
	struct node *l1 = ll1, *l2 = ll2, *a=NULL;
	while(l1!=NULL && l2!=NULL)
	{
		if(l1->exp == l2->exp)
		{
		a = create(a, (l1->coe + l2->coe), l1->exp);
		l1 = l1->next;
		l2 = l2->next;
		}
		else if(l1->exp > l2->exp)
		{
			printf("l1");
			a = create(a, l1->coe, l1->exp);
			l1 = l1->next;
		}
		else if( l2->exp > l1->exp)
		{
			printf("\nl2->exp = %d & l1->exp = %d\n", l2->exp, l1->exp);
			a = create(a, l2->coe, l2->exp);
			l2 = l2->next; 
		}
	}
	while(l1 != NULL)
	{
	a = create(a, l1->coe, l1->exp);
	l1 = l1->next;
	}
	while(l2 != NULL)
	{
	a = create(a, l2->coe, l2->exp);
	l2 = l2->next; 	
	}
	return a;
}

main()
{
	struct node *L1=NULL, *L2=NULL, *A=NULL;
	//3x2 + 4x1 + 4x0 is inserted in L1;
	L1 = create(L1, 3, 2);
	L1 = create(L1, 4, 1);
	L1 = create(L1, 4, 0);
	printf("1st polynomial\n");
	dispList(L1);
	
	//3x2 + 6x1  is inserted in L2;
	L2 = create(L2, 3, 2);
	L2 = create(L2, 2, 1);
	printf("\n2nd polynomial\n");
	dispList(L2);
	
	A = add(L1, L2);
	printf("\nSum of the polynomial\n");
	dispList(A);*/
	
	getch();
}


