#include <stdio.h>
#include <stdlib.h>

typedef unsigned long MYTYPE;
 
typedef unsigned long *MYPNTR;

int main()
{
	MYTYPE t[100];
	MYPNTR u;
	
	u=(MYPNTR)malloc(sizeof(unsigned long)*30);
	u[22]=345816638165381523UL;
	*(u+22)=8123235273512763UL;
	
	free(u);
	
	MYTYPE w;
	
	w=18932;
	
	unsigned long a;//64 bits=8 byte
	long b;	//64 bits=8 bytes
	int c; //8 bits=1 bytes
	float e;	//32 bits
	double f;	//64 bits
	
	printf("%d",sizeof(unsigned long));
	
	return 0;
}
