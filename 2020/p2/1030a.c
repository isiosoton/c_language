#include<stdio.h>

void func(int a,int *result);

int main(void)
{
    int result;
    printf("値を入力してください：");
    scanf("%d",&result);
    func(result,&result);
    if (result == 0)
    {
        printf("答えを出力することができませんでした");
    } else {
        printf("答え：%d",result);
    }

    return 0;
}

void func(int a,int *result)
{
    int b;
    b = a - 1;
    for(;b>0;b--)
    {
        // printf("%d\n",a);
        a *= b;
    }
    if (a > 2147483647 || a < -2147483647 )
    {
        a = 0;
    }

    *result = a;
}