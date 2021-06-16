#include <stdio.h>

typedef struct
{
	int a;
	char *str;
	void *pntr;
	char t;
}MYSTRUCT_t,*MYSTRUCT;

int main()
{
	MYSTRUCT_t e[1];
	
	e[0].a=34;
	
	MYSTRUCT f;
	
	f=(MYSTRUCT)malloc(sizeof(MYSTRUCT_t));
	
	f->str="hello";
	f->a=89;
	
	printf("%s.\n",f->str);
	
	free(f);
	
	return 0;
}
