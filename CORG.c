#include <stdio.h>

#define SIZE 10


void bubbleSort(int work[],const int size,int(*compare)(int a,int b));
int ascending(int a,int b);
int descending(int a,int b);
void swap(int *element1,int *element2);

int main()
{
	int order;
	int counter;
	int a[SIZE]={3,9,2,6,34,67,89,102,96,77};
	
	printf("Enter 1 for ascending order:\n Enter 2 for descending order:\n");
	scanf("%d",&order);
	
	
	printf("Data items for original order\n");
	
	for(counter=0;counter<SIZE;counter++)
	{
		printf("%d ",a[counter]);
	}
	
	if(order==1)
	{
		bubbleSort(a,SIZE,ascending);
		printf("\nData items ascending order\n");
	}
	else
	{
		bubbleSort(a,SIZE,descending);
		printf("\nData items descending order\n");
	}
	
	for(counter=0;counter<SIZE;counter++)
	{
		printf("%d ",a[counter]);
	}
	
	printf("\n");
	
	return 0;
	
	
	
}

void bubbleSort(int work[],const int size,int(*compare)(int a,int b))
{
	int pass,count;
	
	for(pass=1;pass<size;pass++)
	{
		for(count=0;count<size-1;count++)
		{
			if((*compare)(work[count],work[count+1]))
			{
				swap(&work[count],&work[count+1]);
			}
		}
	}
}
int ascending(int a,int b)
{
	return b<a;
}
int descending(int a,int b)
{
	return a<b;
}
void swap(int *element1,int *element2)
{
	int temp=*element1;
	*element1=*element2;
	*element2=temp;
}

