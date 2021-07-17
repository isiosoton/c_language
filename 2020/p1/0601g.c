#include <stdio.h>
int main(void)
{
    int i,e;
    for(i=-3,e=0;e<=20000;e++)
    {
        i = i + 3;
        printf("%d,%d\n" , e, i);
    }
    return 0;
}