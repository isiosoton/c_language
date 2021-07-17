#include<stdio.h>
int main(void){
    int a=5,b=3,r=0;
    if(b==0){ //以下の文を機械語で作る。
        return 0;//エラーチェック　returnで終了する。 １
    }
    while(1){//for文を使わなければ、iを使う必要がない。
        r = r + a;//２
        b = b - 1;//３
        if(0>b){break;}
    }//繰り返し条件、三回繰り返しができるというもの。//４
    printf("%d",r);
}