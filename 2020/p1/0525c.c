#include <stdio.h>
int main(void)
{
    int sum, i, max=10;

    for(sum=0, i=1; i<=max; i++)
    {
        sum += i;
        printf("i=%d, sum=%d\n", i, sum);
    }
    printf("for終了後\n i=%d, sum=%d\n", i, sum);
    printf(" %dまでの合計：%d\n", max, sum);
}
