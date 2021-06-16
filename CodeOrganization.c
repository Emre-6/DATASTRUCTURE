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
	int a[SIZE]={2,6,4,12,56,98,102,45,67,77};
	
	printf("Enter 1 to sort ascending order,\nEnter 2 to sort descending order\n");
	scanf("%d",&order);
	
	printf("\n Data items for original order:\n");
	for(counter=0;counter<SIZE;counter++)
	{
		printf("%d ",a[counter]);
	}
	
	if(order==1)
	{
		bubbleSort(a,SIZE,ascending);
		printf("\n Data items for ascending \n");
	}
	else
	{
		bubbleSort(a,SIZE,descending);
		printf("\n Data items for descending \n");
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
	int hold=*element1;
	*element1=*element2;
	*element2=hold;
}

