#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void janken(void);

int main(void)
{
char b;
int c;
for(b=0;b!=1;)
    {
        printf("じゃんけんプログラム！\nキーボードでパーなら0,チョキなら1,グーなら2を入力してね：");
        scanf("%d",&c);
        printf("\n");
        switch(c)
        {
            case 0: printf("パー\n");
                    break;
            case 1: printf("チョキ\n");
                    break;
            case 2: printf("グー\n");
                    break;
            default:printf("いんちきをした。もう一度やり直してね\n");
                    continue;
        }
        printf("コンピューターは");
        janken();
        printf("を出した！\n");
        printf("じゃんけんは勝てたかな？\n終了するなら1を、続けるなら1以外を入力してね\n");
        scanf("%d",&b);
    }
printf("終了しました\n");

return 0;
}

void janken(void)
{
    int a;
    srand( time(NULL) );
    a = rand() % 2;
    switch(a)
    {
        case 0: printf("パー");
                break;
        case 1: printf("チョキ");
                break;
        case 2: printf("グー");
                break; 
    }
}
