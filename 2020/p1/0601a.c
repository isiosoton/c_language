#include <stdio.h>

int main(void)
{
    int sum, i, max;

    printf("整数値を入力してください：");
    scanf("%d", &max);

    for(sum=0, i=1; ; i++)
    {
        if(i>max)
        {
            break;
        }
        sum += i;
        printf("i=%d, sum=%d\n", i, sum);
        
    }
    printf("%dまでの合計：%d\n", max, sum);

    return 0;
}