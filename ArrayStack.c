#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int max;
	int size;
	void **array;
}ARRAY_STACK_t[1],*ARRAY_STACK;

ARRAY_STACK array_stack_init(int max);
void array_stack_free(ARRAY_STACK stack);
void array_stack_push(ARRAY_STACK stack,void *data);
void *array_stack_pop(ARRAY_STACK stack);


int main()
{
	printf("sizeof(ARRAY_STACK)=%ld\n",sizeof(ARRAY_STACK));
	printf("sizeof(ARRAY_STACK_t)=%ld\n",sizeof(ARRAY_STACK_t));
	printf("sizeof(void*)=%ld\n",sizeof(void*));
	printf("sizeof(void**)=%ld\n",sizeof(void**));
	printf("int=%ld\n",sizeof(int));
	return 1;
	
}


