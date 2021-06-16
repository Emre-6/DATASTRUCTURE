#include <stdio.h>

int main()
{
	int a;
	int *b;
	
	a=17;
	b=&a;
	printf("%d %d\n\n",a,*b);
	
	*b=10;
	printf("%d %d\n\n",a,*b);
	printf("%lu %lx %p\n\n",b,b,b);
	
	printf("%d\n\n",sizeof(int ));
	printf("%d\n\n",sizeof(int *));
	
	return 1;
}
