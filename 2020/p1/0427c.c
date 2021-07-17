#include<stdio.h>
int main(void)
{
    float w;
    float h;
    printf("底辺の長さを入力してください：");
    scanf("%f", &w); //底辺の長さ
    printf("高さを入力してください：");
    scanf("%f", &h); //高さ
    
    float S;
    S = w * h / 2; /* 面積 **/
    printf( "三角形の面積は%.2fです。\n ", S );
} 