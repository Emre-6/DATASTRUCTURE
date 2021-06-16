#include <stdio.h>

typedef struct
{
	char u;
	int size;
	void **array;
}ARRAY_STACK_t[1],*ARRAY_STACK;

int main()
{
	printf("sizeof(ARRAY_STACK)=%ld\n",sizeof(ARRAY_STACK));
	printf("sizeof(ARRAY_STACK_t)=%ld\n",sizeof(ARRAY_STACK_t));
	printf("sizeof(void*)=%ld\n",sizeof(void*));
	printf("sizeof(void**)=%ld\n",sizeof(void**));
	printf("sizeof(int)=%ld\n",sizeof(int));
	return 1;
}

