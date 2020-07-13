#include <stdio.h>
#include <conio.h>
#define size 10
int largest(int arr[], int n);
void radix_sort(int arr[], int n);
void main()
{
int arr[size], i, n;
printf("\n Enter the number of elements in the array: ");
scanf("%d", &n);
printf("\n Enter the elements of the array: ");
for(i=0;i<n;i++)
{
scanf("%d", &arr[i]);
}
radix_sort(arr, n);
printf("\n The sorted array is: \n");
for(i=0;i<n;i++)
printf(" %d\t", arr[i]);
getch();
}
int largest(int arr[], int n)
{
int large=arr[0], i;
for(i=1;i<n;i++)
{
if(arr[i]>large)
large = arr[i];
}
return large;
}
void radix_sort(int arr[], int n)
{
int bucket[size][size], bucket_count[size];
int i, j, k, remainder, NOP=0, divisor=1, large, pass;
large = largest(arr, n);
while(large>0)
{
NOP++;
large/=size;
}
for(pass=0;pass<NOP;pass++) // Initialize the buckets
{
for(i=0;i<size;i++)
bucket_count[i]=0;
for(i=0;i<n;i++)
{
// sort the numbers according to the digit at passth place
remainder = (arr[i]/divisor)%size;
printf("\n");
printf(" remainder[%d] = %d", i, remainder);
printf("  bucket_count[%d] = %d", i, bucket_count[remainder]);
printf(" bucket[%d][%d] ", remainder, bucket_count[remainder]);
//printf(" arr[%d] = %d", i, arr[i]);
//printf(" divisor = %d", divisor);
printf("\n");
bucket[remainder][bucket_count[remainder]] = arr[i];
bucket_count[remainder] += 1;
}
// collect the numbers after PASS pass
printf("\n");
for(i=0;i<size;i++){
printf(" bucket_count[%d] = %d ", i, bucket_count[i] );
}
printf("\n");
i=0;
for(k=0;k<size;k++)
{
for(j=0;j<bucket_count[k];j++)
{
	printf(" bucket[%d][%d] = %d ", k, j, bucket[k][j]);
arr[i] = bucket[k][j];
i++;
}
}
divisor *= size;
printf("\n");
}
}

