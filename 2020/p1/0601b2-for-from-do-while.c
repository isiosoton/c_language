#include <stdio.h>

int main(void)
{
    int a;
    
    for(a=1; a>0;) // とりあえず繰り返し処理に入る
    {
        printf("正の整数を入力してください：");
        scanf("%d", &a);

        if(a%5 == 0 && a>0)
        {
            printf("  %dは5の倍数です。\n", a);
        }
        else
        {
            printf("  %dは5の倍数ではありません。\n", a);
        }
    }

    return 0;
}

