#include <stdio.h>

int main(void)
{
    float a,b;
    printf("円の半径を入力してください：");
    scanf("%f", &a);
    b = a * a * 3.14;
    printf("円の面積は%.2fです。\n" , b);
    return 0;
}
