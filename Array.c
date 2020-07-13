#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int arr[9] = {10, 5, 3, 52, 34, 39};
int si = 10, e=6;

int isFull()
{
	if(e >= si)
	{
		printf("\nList is Full\n");
		return 1;
	}
	else 
	{
		return 0;
	}
}

int isEmpty()
{
	if(e <= 0)
	{
		printf("\nList is empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

//insertion at a given position
void insert(int d1, int p)
{
	int j;
	if(p == 0 || p > size() )
	{
		printf("\nInvalid position\n");
		return ; 
	}
	else if(isFull() == 1)
	{
		printf("\nInsertion is not possible\n");
		return;
	}
for(j=size(); j>=p-1; j--)
{
	arr[j+1] = arr[j];
}
arr[p-1] = d1;
e++;
}

//Delete a particular element 
void delet(int d2)
{
	int l=0;
if(search(d2) == 1 && isEmpty() == 0)
{
	while(arr[l] != d2)
	{
		l++;
	}
	arr[l] = 0;
	printf("\n%d is deleted\n", d2);
	e--;
	}
	else
	{
		printf("\nDeletion can not be performed\n");
		return ;
		}	
}

//Size of the array
int size()
{
	int s = sizeof(arr)/sizeof(arr[0]);
	return s;
}

//Search an element
int search(int d3)
{
	int i;
	for(i=0; i<size(); i++)
	{
		if(d3 == arr[i])
		{
			printf("\n%d is found\n", d3);
			return 1;
		}
	}
	printf("\n%d is not found\n", d3);
	return 0;
}

//Display the list
void disp()
{
	int i;
	printf("\nElements of the array are :");
	for(i=0; i<size(); i++)
	{
	printf("%d ", arr[i]);	
	}
	printf("\n");
}

main()
{
	disp();
	insert(12, 9);
	disp();
	delet(5);
	disp();
	getch();
}
