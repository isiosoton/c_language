#include <stdio.h>

int main(void)
{
    int sum, i;

    for(sum=i=0; i<=10; i++)
    {
        if(i%2 == 0)
        {
            sum += i;
            printf("if   i=%d, sum=%d\n", i, sum);
        }
        else
        {
            printf("else i=%d, sum=%d\n", i, sum);
        }
        
    }
    printf("10までの偶数の合計：%d\n", sum);

    return 0;
}