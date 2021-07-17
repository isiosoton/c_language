#include <stdio.h>
int main(void)
{
    int a = 1;
    printf("%d\n",a);
    while(a < 198)
    {
        a += 1;
        printf("%d\n",a);
    }
    a /= 2;
    printf("%d\n",a);

    double b;
    printf("数値：");
    scanf("%lf",&b);
    while(b < 130000)
    {
        b = b * b;
        printf("%.0f\n",b);
    }
    b -= 5;
    printf("%.0f\n",b);

    return 0;
}
