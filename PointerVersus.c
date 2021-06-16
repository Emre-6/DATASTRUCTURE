#include <stdio.h>

size_t getSize(float *ptr);

int main()
{
	float array[20];
	
	printf("Sizeof(array)=%ld\n",sizeof(array));
	printf("getSize(array)=%ld\n",getSize(array));
	
	return 0;	
}

size_t getSize(float *ptr)
{
	return sizeof(ptr);
} 
