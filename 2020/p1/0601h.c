#include <stdio.h>
int main(void)
{
    int a,b;
    for(a=0,b=1;b<=12;b++)
    {
        a = a + b;
        printf("%d,%d\n",b,a);
    }
    return 0;
}