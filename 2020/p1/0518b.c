#include <stdio.h>

int main(void)
{
    double a,b;
    printf("円の半径を入力してください：");
    scanf("%lf", &a);
    b = a * 2 * 3.14;
    printf("円の円周は%fです。\n", b);

    return 0;
}