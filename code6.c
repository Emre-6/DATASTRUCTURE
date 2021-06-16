#include <stdio.h>

typedef struct
{
	int a;
	char *str;
	void *pntr;
	char t;
	
}MYSTRUCT_t[1],*MYSTRUCT;



int main()
{
	MYSTRUCT_t e;
	
	e->a=77;
	
	printf("%d\n",e->a);
	
	MYSTRUCT f;
	
	f=(MYSTRUCT)malloc(sizeof(MYSTRUCT_t));
	
	f->str="hello";
	f->a=89;
	
	printf("%s\n",f->str);
	
	free(f);
	
	f=e;
	
	printf("%d\n",f->a);
	
	return 0;
}
