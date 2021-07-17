#include <stdio.h>
int main(void)
{
    int	w = 1, h = 5; /* w:底辺の長さ, h:高さ */
    float	S;

    printf("三角形の面積を計算します。\n");
    printf("底辺の長さを入力してください：");
    scanf("%d", &w);
    printf("高さを入力してください：");
    scanf("%d", &h);
    
    S = w * h / 2.0;
    printf("三角形の面積は%.2fです。\n", S);
}
