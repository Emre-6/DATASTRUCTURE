#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int a;
	int b;
	char c;
	unsigned long t;
}MYSTRUCT;

typedef struct{
	int a;
	int b;
	char c;
	unsigned long t;
}*MYSTRUCT_PNTR;

typedef struct{
	int a; //4 bytes
	int b; //4 bytes
	char c; //8 bytes
	unsigned long t; //8bytes
}MYSTRUCT_t,*MYSTRUCT_pntr;

int main()
{
	int a;
	
	MYSTRUCT_t d;
	MYSTRUCT_t e[10];
	MYSTRUCT_pntr f;
	
	f=(MYSTRUCT_pntr)malloc(sizeof(MYSTRUCT_t));
	f->b=90;
	
	free(f);
	a=19;
	d.a=17;
	d.t=19;
	e[2].c='r';
	printf("%d\n",sizeof(f)); //8 bytes
	
	return 0;
}
