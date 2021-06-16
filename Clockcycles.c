#include <stdio.h>
#include <stdlib.h>

#define uint64_t unsigned long
#define uint32_t unsigned int

uint64_t cycles_now(void)
{
#if defined(__GNUC__)
 uint32_t lo, hi;
 __asm__ __volatile__("rdtsc" : "=a" (lo), "=d" (hi));
 return ((uint64_t)lo | ((uint64_t)hi << 32));
#else
 return 0;
#endif

}

int main(void) {
 int i, j, k, l = 0;
 uint64_t st, fn;

 st = cycles_now(); // start

 // This part is measured.
 for(i = 0; i < 1000; i++) {
 for(j = 0; j < 1000; j++) {
 for(k = 0; k < 1000; k++) {
 l = l + 1;
 }
 }
 }

 fn = cycles_now(); // finish

 printf("This code took %lu clock cycles to execute.\n", (fn - st));

 return 0;
 }
