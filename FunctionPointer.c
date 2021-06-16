#include <stdio.h>
#include <stdlib.h>

void abc(int a,float k)
{
    printf("abc() has been called with the parameter %d %f\n\n",a,k);
}

int main()
{
    void (*myfunc)(int,float);

    myfunc=abc;

    nyfunc(25,89.326);

    return 0;
}
