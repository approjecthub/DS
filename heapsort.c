#include<stdio.h>
#include<conio.h>

int H[10];
int n, heapSize;

void Heapify(int i)
{
	int l = (2*i)+1, r=(2*i)+2, max, t;
	if(l<=heapSize && H[l]>H[i])
		max = l;
	else
	max = i;
	if(r<= heapSize && H[r] > H[max])
	max = r;
	if(max != i)
	{
		t = H[i];
		H[i] = H[max];
		H[max] = t;
	}
	else
	return;
	Heapify( max);
}

void buildHeap()
{
	int i;
	heapSize = n-1;
	for(i=heapSize; i>=0; i--)
	{
		Heapify( i);
	}
}

void HeapSort()
{
	int t, i;
	buildHeap();
	for(i=heapSize; i>=0; i--)
	{
	t = H[0];
	H[0] = H[i];
	H[i] = t;	
	heapSize = heapSize-1;
	Heapify(0);
}
}

main()
{
	int i;
	printf("Enter the no. elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0; i<n; i++)
	scanf("%d", &H[i]);
	HeapSort();
	printf("\nSorted list\n");
	for(i=0; i<n; i++)
	printf(" %d ", H[i]);
	getch();
}
