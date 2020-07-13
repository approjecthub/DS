#include<stdio.h>
#include<conio.h>

int p[10], n, b[10];

void merge(int low, int mid, int high)
{
	int h=low, k=low, j=mid+1, i;
	while(h<=mid && j<=high)
	{
		if(p[h] <= p[j]){
		b[k] = p[h];
		h = h+1;
		}
		else{
			b[k] = p[j];
			j = j+1;
		}
		k = k+1;
	}
	if(j > high)
	{
		for(i=h; i<=mid; i++)
		{
			b[k] = p[i];
			k = k+1;
		}
		}
		else {
			for(i=j; i<=high; i++)
			{
				b[k]= p[i];
				k = k+1;
			}
		}
		for(i=low; i<= high; i++)
		{
			p[i] = b[i];
			}	
}

void mergeSort(int low, int high)
{
	int mid;
	if(low<high)
	{
	mid = (low+high)/2;
	mergeSort(low, mid);
	mergeSort(mid+1, high);
	merge(low, mid, high);	
	}
}

main()
{
	int i;
	printf("Enter the no. elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0; i<n; i++)
	scanf("%d", &p[i]);
	mergeSort(0, n-1);
	printf("\nSorted list\n");
	for(i=0; i<n; i++)
	printf(" %d ", p[i]);
	getch();
}
