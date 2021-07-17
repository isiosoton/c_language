#include <stdio.h>

int main(void)
{
    int a, i;
    
    for(;;)// とりあえず繰り返し処理に入る 
    {
        printf("正の整数を入力してください：");
        scanf("%d", &a);
        if (a<0)
        {
            break;
        }
        else if(a%5 == 0)
        {
            printf("  %dは5の倍数です。\n", a);
            continue;
        }
        printf("  %dは5の倍数ではありませんが、次の数の倍数です。\n  ", a);
        for(i=2; i<=a; i++)
        {
            if(a%i == 0)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
    } while(a>0);


    return 0;
}

