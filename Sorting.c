#include<stdio.h>
#include<conio.h>

void insertionSort(int a[], int n)
{
	int i, j, t;
	for(i=1; i<n; i++)
	{
		t = a[i];
		for(j=i-1; j>=0; j--)
		{
			if(a[j] > t)
			{
			a[j+1] = a[j];
			}
			else
			break;
		}
		a[j+1] = t;
	}
}

void shellSort(int a[], int s)
{
	int i, j, k,t;
	for(i=s/2; i>=1; i=i/2)
	{
		for (k = i; k < s; k++){
			t=a[k];
		for(j=k-i; j>=0; j = j-i)
		{
			if(a[j] > t)
			{
			a[j+i] = a[j];
			}
			else
			break;
		}
		a[j+i] = t;
	}
}
}

void selectionSort(int a[], int n)
{
	int i, j, j1,min, t;
	for(i=0; i<n-1; i++)
	{
		min = a[i];
		for(j=i+1;j<n;j++)
      {
	  if(a[j]<=min)
	  {
	  t = a[j];
	  a[j] = a[i];
	  a[i] = t;
	  min = a[i];
	  }
	  }
	}
}

void print(int a[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf(" %d ", a[i]);
	}
}

void merging(int A[], int P, int Q, int R1)
{
	int n1 = Q-P+1;
	int n2 = R1-Q ;
	int i, j, k;
	int L[n1], R[n2];
	for(i=0; i<n1; i++)
	{
		L[i] = A[P+i];
	}
	for(j=0; j<n2; j++)
	{
		R[j] = A[Q+j+1];
	}
	L[n1] = 9999;
	R[n2] = 9999;
	i=0, j=0;
	for(k=P; k<R1; k++)
	{
		if(L[i] <= R[j] ) //&& L[i]!=9999
		{
			A[k] = L[i];
			i++;
		}
		else if(L[i] > R[j] ) //&& R[j]!=9999
		{
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int a[], int p, int r)
{
    if (p < r)
    {
    	int i;
        int q = (p+r)/2;
		mergeSort(a, p, q);
        mergeSort(a, q+1, r-1);
        merging(a, p, q, r-1);
    }
}

int partition(int a[], int p, int r)
{
	int x = a[r-1], i = p-1, j, t;
	for(j=p; j<r ; j++)
	{
		if(a[j] <= x)
		{
			i++;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	return i+1;
}

void quicksort(int a1[], int p1, int r1)
{
	if(p1<r1)
	{
		int q1=partition(a1, p1, r1) ;
		quicksort(a1, p1, q1-1);
		quicksort(a1, q1+1, r1);
	}
}

void bubblesort(int a[], int n)
{
	int i, j, t;
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]>=a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

main()
{
	int arr[] = {10,9,9,8,7,6} ;
	int size = sizeof(arr)/sizeof(arr[0]);
	
	//quicksort(arr, 0, size);
	//mergeSort(arr, 0, size);
	
	//selectionSort(arr, size);
	//shellSort(arr, size);
	bubblesort(arr, size);
	//insertionSort(arr, size);
	print(arr, size);
	getch();
}
