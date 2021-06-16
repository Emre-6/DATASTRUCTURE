#include <stdio.h>

int main()
{
	int b[]={10,20,30,40};
	int *bptr=b;
	int i,offset;
	
	for(i=0;i<4;i++)
	{
		printf("%d\n",b[i]);
	}
	
	for(offset=0;offset<4;offset++)
	{
		printf("*(b+%d)=%d\n",offset,*(b+offset));
	}
	
	for(i=0;i<4;i++)
	{
		printf("bPtr[%d]=%d\n",i, bPtr[i]);
	}
	
	for(offset=0;offset<4;offset++)
	{
		printf("*(bPtr+%d)=%d\n",offset,*(bPtr+offset));
	}
	
	return 0;
}
