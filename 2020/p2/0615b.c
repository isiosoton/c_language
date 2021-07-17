#include <stdio.h>
#include <math.h>
int main(void)
{
    double a=0,b=0,c=0,d=0,e,f=0,g=0,h=0,i=0,j=0,k=0,l;
    for(l=0;l<=1;l++)
    {
        while(scanf("%lf",&a) != EOF) {
            if(l==1)
            {
                if(a > i)
                {
                    c++;
                    printf("番号：%dは%f点です。評価はAです。\n",c,a);
                } else if (i > a && a > d) {
                    c++;
                    printf("番号：%dは%f点です。評価はBです。\n",c,a);
                } else if (d > a && a > j) {
                    c++;
                    printf("番号：%dは%f点です。評価はCです。\n",c,a);
                } else if (j > a) {
                    c++;
                    printf("番号：%dは%f点です。評価はDです。\n",c,a);
                } else {
                    c++;
                    printf("番号：%dは%f点です。評価は不可です。\n",c,a);
                }
            } else {
                b += a;
                // printf("番号：%dは%f点です。\n",c,a);
                e += a * a;
                c++;
            }
        }
        if (l != 0)
        {
            c -= 1;
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
            c = 0;            
        }


    }

    return 0;
}