#include <stdio.h>

int main()
{
	int a;
	int b;
	
	printf("Please give a number as 1st variable:");
	scanf("%d",&a);
	printf("Please give a number as 2nd variable:");
	scanf("%d",&b);
	
	a=a+b;
	b=a-b;
	a=a-b;
	
	printf("The value of the 1st variable:%d\n",a);
	printf("The value of the 2nd variable:%d\n",b);
	
	return 0;
}
