#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int a,b,c,d;
    srand(time(NULL));
    printf("引数Aを入力してください：");
    scanf("%d",&a);
    printf("\n引数Bを入力してください：");
    scanf("%d",&b);
    c = a - b;
    if(c<0)
    {
        c *= -1;
    }
    d = a + rand()%c;
    printf("\n結果は%dです。",d);
}