#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a,b,c,d,e = 1;
    printf("じゃんけんプログラム！\n");
    while(e == 1)
    {
        srand(time(NULL));
        printf("勝ちの回数は%d回\n負けの回数は%d回\nどちらかが三回勝った時点で終了だよ！\n",a,d);
        printf("キーボードでグーなら1,チョキなら2,パーなら3を入力してください：");
        scanf("%d",&b);
        switch(b)
        {
            case 1: printf("あなたはグーを出した！\n");
                    break;
            case 2: printf("あなたはチョキを出した！\n");
                    break;
            case 3: printf("あなたはパーを出した！\n");
                    break;
            default:printf("あなたはいんちきをした！\n");
                    b = 8;
                    break;
        }
        c = rand() % 4;
        while (c == 0)
        {
            c = rand() % 4;
        }
        switch(c)
        {
            case 1: printf("コンピューターはグーを出した！\n");
                    break;
            case 2: printf("コンピューターはチョキを出した！\n");
                    break;
            case 3: printf("コンピューターはパーを出した！\n");
                    break;
            default:printf("コンピューターはいんちきをした！\n");
                    break;
        }
        if (b == c)
        {
            printf("じゃんけんの結果はあいこだった。\nもう一度入力してね\n\n");
            continue;
        } else if (c==b+1 || c==b-2) {
            printf("じゃんけんの結果は勝ち！\n");
            a += 1;
            if (a < 3)
            {
                printf("もう一度入力してね\n\n");
            } else {
                printf("あなたの勝ち！\nもう一度じゃんけんをする場合は1を、やめる場合は1以外の数字を入力してください\n");
                scanf("%d",&e);
                if (e == 1) 
                {
                    a = 0;
                    d = 0;
                    printf("\n");
                }
            }
            continue;
        } else if (b == c+1 || b == c-2) {
            printf("じゃんけんの結果は負け！\n");
            d += 1;
            if (d < 3)
            {
                printf("もう一度入力してね\n\n");
            } else {
                printf("あなたの負け！\nもう一度じゃんけんをする場合は1のどれかを、やめる場合は1以外の整数を入力してください\n");
                scanf("%d",&e);
                if (e == 1) 
                {
                    a = 0;
                    d = 0;
                    printf("\n");
                }
            }
            continue;
        } else {
            printf("じゃんけん出来なかったよ！\nもう一度入力してね\n\n");
            continue;
        }
    }
    printf("終了しました");

    return 0;
}