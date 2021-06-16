#include <stdio.h>


void swap(int *xp,int *yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}


void bubbleSort(int arr[],int n)
{
	int i,j;
	for(i=0;i<=n;i++)
	for(j=0;j<n-i-1;j++)
	if(arr[j]>arr[j+1])
	swap(&arr[j],&arr[j+1]);
}

void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	
}


int main()
{
	int arr[]={66,34,12,90,85};
	int n=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,n);
	printf("\n");
	printArray(arr,n);
	return 0;
}
