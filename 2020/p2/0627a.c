#include <stdio.h>
#include <math.h>

int main(void)

{
    int x[100002],y,number;
    for(y=0;scanf("%d",&x[y]) != EOF;y++) {}
    float avarage,avarage2,sum,sum2,sum2avarage,deviation,square;
    for(number=0;y > number;number++) {
        //printf("%6d:%d\n",number,x[number]);
        sum += x[number];
        square = x[number] * x[number];
        sum2 += square;
    }
    avarage = sum / number;
    printf("平均値は%.0fです\n",avarage);
    avarage2 = avarage * avarage;
    sum2avarage = sum2 / number;
    deviation = sum2avarage - avarage2;
    deviation = sqrt(deviation);
    printf("標準偏差は%.0fです\n",deviation);
    int point,A=0,B=0,C=0,D=0,E=0,n,m,os;
    n = avarage + deviation;
    m = avarage - deviation;
    for(y=0;number > y;y++) {
        if(x[y] >= n) {
            A += 1;
        } else if(n > x[y] && x[y] >= avarage) {
            B += 1;
        } else if(avarage > x[y] && x[y] >= m) {
            C += 1;
        } else if(m > x[y]) {
            D += 1;
        } else {
            E += 1;
        }
    }
    printf("評価Aは%d人\n評価Bは%d人\n評価Cは%d人\n評価Dは%d人\n評価不能は%d人です。\n",A,B,C,D,E);
    
    for(;os==0;) {
        int pm;
        printf("番号を入力してください：\n");
        scanf("%d\n",&pm);
        if(x[pm] >= n) {
            printf("番号%dは%d点です。\n評価はAです。\n",pm,x[pm]);
        } else if(n > x[pm] && x[pm] >= avarage) {
            printf("番号%dは%d点です。\n評価はBです。\n",pm,x[pm]);
        } else if(avarage > x[pm] && x[pm] >= m) {
            printf("番号%dは%d点です。\n評価はCです。\n",pm,x[pm]);
        } else if(m > x[pm]) {
            printf("番号%dは%d点です。\n評価はDです。\n",pm,x[pm]);
        } else {
            printf("番号%dは%d点です。\n評価不能です。\n",pm,x[pm]);
        }
        printf("再確認する場合は1を、再確認しない場合は1以外の数字を入力してください：");
        scanf("%d\n",&os);
        /*if(o!=1) {
            break; 
        }
        **/
    }

    printf("\n終了しました。");
    return 0;
}