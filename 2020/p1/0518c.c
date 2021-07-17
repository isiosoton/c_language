#include <stdio.h>
int main(void)
{
    int a;
    float r, S;
    printf("1.円\n2.正方形\n3.正三角形\n何番の図形の面積を求めますか？：");
    scanf("%d", &a);
    switch(a)
    {
        case 1:  printf("円の半径を入力してください：");
                 scanf("%f", &r);
                 S = r * r * 3.14;
                 if(S == 0.00)
                 {
                     printf("計算できませんでした。");
                 } else {
                     printf("円の面積は%.2fです。\n", S);
                 }
                 break;
        case 2:  printf("底辺の長さを入力してください：");
                 scanf("%f", &r);
                 S = r * r;
                 if(S != 0.00)
                 {
                     printf("正方形の面積は%.2fです。\n", S);
                 } else {
                     printf("計算できませんでした。");
                 }
                 break;
        case 3:  printf("一辺の長さを入力してください：");
                 scanf("%f", &r);
                 S = r * r * 0.43;
                 if(S == 0.00)
                 {
                     printf("計算できませんでした。");
                 } else {
                     printf("正三角形の面積は%.2fです。\n", S);
                 }
                 break;
        default: printf("入力が不適切でした。");
    }
    return 0;
}