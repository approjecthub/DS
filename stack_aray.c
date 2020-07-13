#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define size 3

int e=0;
int arr[size - 1];

int isFull()
{
	if(e == size)
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
	if(e == 0)
	{
		printf("\nList is empty\n");
		return 1;
	}
	else
	{
		return 0;
	}
}

int peek()
{
	if(isEmpty() == 0){
		return arr[e-1];
	}
}

void push(int d1)
{
	if(isFull() == 0)
	{
		arr[e] = d1;
		e++ ;
		return ;
	}
	else
	{
		printf("\n%d can not be pushed\n", d1);
		return ;
	}
}

void pop()
{
	if(isEmpty() == 0)
	{
		printf("\n%d is popped out", arr[e-1]);
		arr[e-1] = 0;
		e-- ;
		return;
	}
	else
	{
		printf("\nPopping is not possible\n");
		return ;
	}
}

void dispStack()
{
	int d;
	if(isEmpty() == 0){
	printf("Elements of stack is\n");
	for(d=e-1; d>=0; d--)
	{
		printf("%d\n", arr[d]);
	}
}
}

main()
{
	push(15);
printf("%d", peek());
getch();
}
