#include <stdio.h>

int main(void)
{
    int ia, a;
    
    printf("正の整数を入力して下さい：");
    scanf("%d", &ia);

    for(a=ia;a>0;a++) // aが正の数のときだけ繰り返し処理に入る
    {
        if(a%5 == 0)
        {
            printf("正の数%d以上の最も小さい5の倍数：%d\n", ia, a);
            break;
        }
    }

    return 0;
}

