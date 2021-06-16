#include <stdio.h>

int main()
{
	//icore-7 64 bit=8 bytes
	
	long a; //64 bits = 8 byte
	int b;	//32 bits = 4 byte
	char c; //8 bits = 1 byte
	float d; //32 bits = 4 byte
	double e;//64 bits= 8 byte
	
	long *f; //64 bits=8 byte
	char *g; //64 bits=8 byte
	
	printf("%d\n",sizeof(double));
	
	return 0;
}
