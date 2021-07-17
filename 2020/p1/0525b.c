#include <stdio.h>

int main(void)
{
    int n;
    float r;

    printf("int型の数値を入力：");
    scanf("%d", &n);

    //r = (float)n/3;
    /* r = (float)n/3; 教科書の7p */
    r = n/3.0;

    printf("%d/3=%.3f\n", n, r);

    return 0;
}
