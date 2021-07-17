#include <stdio.h>
#include <math.h>
int main(void)
{
    int c=0,l=0,m=0,n=0,o=0,p=0,g;
    double a=0,b=0,d=0,e,h=0,i=0,j=0,f[100000]; //k=0
    while(scanf("%lf",&f[c]) != EOF) {
        // f[c](読込値),b(合計),c(振分番号)は固定
        b += f[c];
        // printf("番号：%dは%f点です。\n",c,a);
        e += f[c] * f[c];
        d = b / c;
        // printf("平均は%.0f点です。\n",d);
        e /= c;
        d *= d;
        e -= d;
        // printf("分散は%fです。\n",e); // (デバッグ用)
        h = sqrt(e);
        printf("標準偏差は%.0f点です。\n",h);
        i = d + h;
        j = d - h;
        c++;
    }
    /*
    printf("平均は%.0f点です。\n",d);    
    printf("標準偏差は%.0f点です。\n",h);
    for(g=0;g>=c;g++)
    { 
        if(f[g] >= i)
        {
            // printf("番号：%dは%.0f点です。評価はAです。\n",c,a);
            l += 1;
        } else if (i >= f[g] && f[g] > d) {
            // printf("番号：%dは%.0f点です。評価はBです。\n",c,a);
            m += 1;
        } else if (d >= f[g] && f[g] > j) {
            // printf("番号：%dは%.0f点です。評価はCです。\n",c,a);   
            n += 1;
        } else if (j > f[g]) {    
            // printf("番号：%dは%.0f点です。評価はDです。\n",c,a);
            o += 1;
        } else {
            // printf("番号：%dは%.0f点です。評価は不可です。\n",c,a);
            p += 1;
        }  
    }
    printf("評価Aは%d人\n評価Bは%d人\n評価Cは%d人\n評価Dは%d人\n評価不可は%d人です。\n始めの評価は変動しやすくなっています。\n",l,m,n,o,p);
    printf("成績照会します。番号を入力してください：");
    scanf("%d",&c);
    if(f[c] >= i)
    {
        printf("番号：%dは%.0f点です。評価はAです。\n",c,f[c]);
    } else if (i >= f[g] && f[g] > d) {
        printf("番号：%dは%.0f点です。評価はBです。\n",c,f[c]);
    } else if (d >= f[g] && f[g] > j) {
        printf("番号：%dは%.0f点です。評価はCです。\n",c,f[c]);   
    } else if (j > f[g]) {    
        printf("番号：%dは%.0f点です。評価はDです。\n",c,f[c]);
    } else {
        printf("番号：%dは%.0f点です。評価は不可です。\n",c,f[c]);
    }

        /*
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
        **/


    return 0;
}