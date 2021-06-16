#include <stdio.h>

void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}


void selection(int arr[],int n)
{
	int i,j,min_idx;
	
	for(i=0;i<n-1;i++)
	{
		min_idx=i;
		for(j=i+1;j<n;j++)
			if(arr[j]>arr[j+1])	
			min_idx=j;
		swap(&arr[min_idx],&arr[i]);
	}
}

void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d\n",arr[i]);
	printf("\n");
	
}

int main()
{
	int arr[]={64,25,12,22,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	printf("Sorted array: \n");
	printArray(arr,n);
	return 0;
	
}
