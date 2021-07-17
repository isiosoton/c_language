#include <stdio.h>
int main(void)
{
    int sum, i;

    for(sum=0, i=1; i<=12; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
