#include <stdio.h>
#define SIZE 10

int main()
{
	int a[SIZE]={10,2,9,8,4,6,5,3,1,7};
	int pass;
	int i;
	int hold;
	
	printf("Data items in original order\n:");
	for(i=0;i<SIZE;i++)
	{
		printf("%4d",a[i]);
	}
	
	for(pass=1;pass<SIZE;pass++)
	{
		for(i=0;i<SIZE;i++)
		{
			if(a[i]>a[i+1])
			{
				hold=a[i];
				a[i]=a[i+1];
				a[i+1]=hold;
			}
		}
	}
	printf("\nData items ascending order\n");
	
	for(i=0;i<SIZE;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
	return 0;
	
}
