#include <stdio.h>

int main(void)
{
    int ia, a;
    
    printf("正の整数を入力して下さい：");
    scanf("%d", &ia);
    a = ia;
    for(;a>0;)
    {
        if(a%5 == 0)
        {
            printf("正の数%d以上の最も小さい5の倍数：%d\n", ia, a);
            break;
        }
        a++;
    }

    return 0;
}

