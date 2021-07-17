#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    printf("じゃんけんプログラム！\n");
    while(a<3)
    {
        printf("キーボードでグーなら1,チョキなら2,パーなら3を入力してください：")
        scanf("%d",&b);
        c = rand(time(NULL))%4;
        switch(c);
        {
            case1:  printf("コンピューターはグーを出した！\n");
                    break;
            case2:  printf("コンピューターはチョキを出した！\n");
                    break;
            case3:  printf("コンピューターはパーを出した！\n");
                    break;
            default:printf("コンピューターはいんちきをした！\n");
                    break;
        }
        if (b==c)
        {
            printf("じゃんけんの結果はあいこだった。\nもう一度入力してね\n");
            continue;
        } else if (b=c+1 && b=c-2) {
            printf("じゃんけんの結果は勝ち！\n");
            a += 1;
            if (a<3)
            {
                printf("もう一度入力してね\n");
            }
            continue;
        } else if (c=b+1 && c=b-2) {
            printf("じゃんけんの結果は負け！\nもう一度入力してね");
        }
    }

    return 0;
}