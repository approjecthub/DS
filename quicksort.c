#include<stdio.h>
#include<conio.h>

int Q[20];

int partition( int p, int r)
{
	int i = p, j=r, x=Q[p], t;
	while(i<j)
	{
		while(Q[i] < x)
		 i = i+1;
		while(Q[j] > x)
		j = j-1;
		if(i<j)
		{
			t = Q[i];
			Q[i] = Q[j];
			Q[j] = t;
		}
		else 
		return j;
	}
}

void quickSort( int p, int r)
{
	if(p<r)
	{
		int q = partition( p, r);
		quickSort( p, q-1);
		quickSort( q+1, r);
	}
}

main()
{
	int p=0, r, i;
	printf("Enter the no. of element\n");
	scanf("%d", &r);
	printf("Enter the elements\n");
	for(i=0; i<r; i++)
	scanf("%d", &Q[i]);
	quickSort( p, r-1);
	for(i=0; i<r; i++)
	printf(" %d ", Q[i]);
	getch();
}
