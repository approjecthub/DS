#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
	int coef, exp;
};

void insertionSort(struct node a[], int n)
{
	int i, j;
	struct node t;
	for(i=1; i<n; i++)
	{
		t = a[i];
		for(j=i-1; j>=0; j--)
		{
			if(a[j].exp < t.exp)
			{
			a[j+1] = a[j];
			}
			else
			break;
		}
		a[j+1] = t;
	}
}

int represent(struct node p[])
{
	int i=0, t;
	printf("\nPut -1 at the end of the equation\nEnter coefficient\n");
	scanf("%d", &t);
	while(t != -1)
	{
		p[i].coef = t;
		printf("\nEnter exponent\n");
		scanf("%d", &t);
		p[i].exp = t;
		i++;
		printf("\nEnter coefficient\n");
		scanf("%d", &t);
	}
	insertionSort(p, i);
	return i;
}

void printpoly(struct node p[], int m)
{
	int i;
	for(i=0; i<m; i++)
	{
		printf("% dX%d ", p[i].coef, p[i].exp);
	}
}

int addpoly(struct node p1[],struct node p2[],struct node p3[], int max1, int max2)
{
	int i,j, k;
	i=j=k=0;
	while(i<max1 || j<max2)
	{
		if( p1[i].exp > p2[j].exp)
		{
			p3[k] = p1[i];
			k++;
			i++;
		}
		else
		if( p1[i].exp < p2[j].exp)
		{
			p3[k] = p2[j];
			k++;
			j++;
		}
		else
		{
			p3[k].exp = p1[i].exp;
			p3[k].coef = p1[i].coef + p2[j].coef;
			i++;
			j++;
			k++;
		}
	} //while
	while( i < max1 )
	{
		p3[k] = p1[i];
		k++;
		i++;
	} //while
	while( j < max2 )
	{
		p3[k] = p2[j];
		k++;
		j++;
	} //while
	return(k);
}

main()
{
	struct node p1[10],p2[10],p3[10];
	int max1,max2,max3;
	printf("\nEnter first poly : ");
	max1 = represent(p1);
	printf("\nEnter second poly : ");
	max2 = represent(p2);	
	max3 = addpoly(p1,p2,p3,max1,max2);	
	printf("\nFirst poly is ");
	printpoly(p1,max1);
	printf("\nSecond poly is ");
	printpoly(p2,max2);
	printf("\n The resultant poly after addition is");
	printpoly(p3,max3);	
	getch();
}
