#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void janken(void);

int main(void)
{
char b;
for(b=0;b!=1;)
    {
        printf("じゃんけんプログラム！\n最初はグー\nじゃんけん\n");
        janken();
        printf("ぽん！\n");
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
        case 0: printf("パー\n");
                break;
        case 1: printf("チョキ\n");
                break;
        case 2: printf("グー\n");
                break; 
    }
}

