#include <stdio.h>
#include <math.h>
int main(void)
{
    int c=0,l=0,m=0,n=0,o=0,p=0;
    double a=0,b=0,d=0,e,f=0,g=0,h=0,i=0,j=0,k=0;
    while(scanf("%lf",&a) != EOF) {
        c += 1;
        b += a;
        // printf("番号：%dは%f点です。\n",c,a);
        e += a * a;
        d = b / c;
        printf("平均は%.0f点です。\n",d);
        f = e / c;
        k = d * d;
        // printf("%f\n",f); // (デバッグ用)
        g = f - k;
        // printf("分散は%fです。\n",g); // (デバッグ用)
        h = sqrt(g);
        printf("標準偏差は%.0f点です。\n",h);
        i = d + h;
        j = d - h;

        if(a >= i)
        {
            printf("番号：%dは%.0f点です。評価はAです。\n",c,a);
            l += 1;
        } else if (i >= a && a > d) {
            printf("番号：%dは%.0f点です。評価はBです。\n",c,a);
            m += 1;
        } else if (d >= a && a > j) {
            printf("番号：%dは%.0f点です。評価はCです。\n",c,a);   
            n += 1;
        } else if (j > a) {    
            printf("番号：%dは%.0f点です。評価はDです。\n",c,a);
            o += 1;
        } else {
            printf("番号：%dは%.0f点です。評価は不可です。\n",c,a);
            p += 1;
        }
    }
    printf("評価Aは%d人\n評価Bは%d人\n評価Cは%d人\n評価Dは%d人\n評価不可は%d人です。\n始めの評価は変動しやすくなっています。\n",l,m,n,o,p);


    return 0;
}