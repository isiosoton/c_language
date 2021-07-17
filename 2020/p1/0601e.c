#include <stdio.h>

int main(void)
{
    int a;
    
    for(;;)
    {
        printf("正の整数を入力してください：");
        scanf("%d", &a);
        if(a<0)
        {
            break;
        }
        else if(a%5 == 0)
        {
            printf("  %dは5の倍数です。\n", a);
        }
        else
        {
            printf("  %dは5の倍数ではありません。\n", a);
        }
    };
    return 0;
}

