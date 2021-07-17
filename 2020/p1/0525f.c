#include <stdio.h>

int main(void)
{
    int sum, i;

    for(sum=0, i=1; i<=10; i++)
    {
        if(i%2 != 0)
        {
            printf("if continue: i=%d, sum=%d\n", i, sum);
            continue;
        }
        sum += i;
        printf("i=%d, sum=%d\n", i, sum);
        
    }
    printf("10までの偶数の合計：%d\n", sum);

    return 0;
}