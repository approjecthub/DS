#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int arr[2];
int front=0, rear=0, e=0, size=3;

int isFull()
{
	if(e >= size)
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

int peek()
{
	if(isEmpty() == 0){
		return arr[front];
	}
	else
	{
		return 0;
	}
}

void enque(int d1)
{
	if(isFull() == 0)
	{
		arr[rear] = d1;
		rear++;
		e++;
	}
	else
	{
		printf("%d can not be enqueued", d1);
	}
}

int deque()
{
	int d2, i;
	if(isEmpty() == 0)
	{
		d2 = arr[front];
		arr[front] = 0;
		for(i=0; i<e; i++)
		{
			arr[i] = arr[i+1];
		}
		e--;
		rear--;
	}
	return d2;
}

void dispQue()
{
	int i;
	printf("\nEntry... ");
	for(i=e-1; i>=0; i--){
		printf(" %d ", arr[i]);
	}
	printf(" ...Exit\n");
}

main()
{
	enque( 13);
	enque(10);
	enque(56);
	printf("Front element is %d\n", peek());
	dispQue();
	printf("\ndequed = %d",deque());
	dispQue();
	getch();
}


