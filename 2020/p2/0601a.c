#include <stdio.h>
int main(void)
{
    double a,b,c,d,e,f;
    int x,y;
    printf("ax+by=c\ndx+ey=f\nより\naを入力してください：\n");
    scanf("%lf",&a);
    printf("bを入力してください：\n");
    scanf("%lf",&b);
    printf("cを入力してください：\n");
    scanf("%lf",&c);
    printf("dを入力してください：\n");
    scanf("%lf",&d);
    printf("eを入力してください：\n");
    scanf("%lf",&e);
    printf("fを入力してください：\n");
    scanf("%lf",&f);
    if((int)a%(int)d == 1)
    {
        (double)a,(double)b;
        for(;a=1;)
        {
            a -= d;
            b -= e;
            c -= f;
        }
    } else {
        a /= a;
        b /= a;
        c /= a;
    }

    for(;d=0;)
    {
        d -= a;
        e -= b;
        f -= c;
    }
    
    if(c == 0)
    {
        if(f == 0)
        {
            printf("\nx,yの答えは不定である。");
        } else {
            printf("\nx,yの答えは不能である。");
        }
    } else {
        e /= e;
        f /= e;
    }
    
    for(;b=0;)
    {
        b -= e;
        c -= f;
    }
    printf("x=%f,y=%f",c,f);

}