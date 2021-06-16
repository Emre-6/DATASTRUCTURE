#include <stdio.h>
#define SIZE 5

void modifyArray(int b[],SIZE);
void modifyElement(int e);


int main()
{
	int a[SIZE]={0,1,2,3,4};
	int i;
	printf("Effects passing entire array:");
	modifyArray(a,SIZE);
	
	printf("The values are modified array:");
	modifyArray(a,SIZE);
	printf("The values of the modify array are:");
	
	for(i=0;i<SIZE;i++)
	{
		printf("%3d",a[i]);
	}
	
	printf("Effects of passing array:\n\n",a[3]);
	
	modifyElement(a[3]);
	
	printf("%d",a[3]);
	
	return 0;
}

void modifyArray(int b[],SIZE)
{
	int j;
	
	for(j=0;j<SIZE;j++)
	{
		b[j]*=2;
	}
}
void modifyElement(int e)
{
	printf("Value in modify element is %d\n:",e*=2);
}



