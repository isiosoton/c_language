#include <stdio.h>
int main(void)
{
    int a;
    float r, S;
    for (a=0;; a++)
    {
        printf("\n1.円\n2.正方形\n3.正三角形\n4.終了\n何番の図形の面積を求めますか？：");
        scanf("%d", &a);
        switch(a)
        {
            case 1:  printf("円の半径を入力してください：");
                     scanf("%f", &r);
                     S = r * r * 3.14;
                     if(S == 0.00)
                     {
                         printf("計算できませんでした。\n");
                     } else {
                         printf("円の面積は%.2fです。\n", S);
                 }
                     continue;//switch文はbreakを原則として行う
            case 2:  printf("底辺の長さを入力してください：");
                     scanf("%f", &r);
                     S = r * r;
                     if(S != 0.00)
                     {
                         printf("正方形の面積は%.2fです。\n", S);
                     } else {
                         printf("計算できませんでした。\n");
                     }
                     continue;
            case 3:  printf("一辺の長さを入力してください：");
                     scanf("%f", &r);
                     S = r * r * 0.43;
                     if(S == 0.00)
                     {
                         printf("計算できませんでした。\n");
                     } else {
                         printf("正三角形の面積は%.2fです。\n", S);
                     }
                     continue;
            case 4:  printf("終了しました。\n");
                     break;
            default: printf("再度入力してください。\n");
                     continue;
        }
        break;
    }
    return 0;
}