#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a, b, c=0;
    srand(time(NULL));
    while(c <= 100000)
    {
        a = rand()%101;
        printf("%d\n",a);
        c++;
    }
    return 0;
}