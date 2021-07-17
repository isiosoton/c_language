#include<stdio.h>

float baisu(float a/* ,float b**/);

int main(void)
{
    float a;
    float b;
    printf("代入値：");
    scanf("%f",&a);
    /*
    printf("\n代入値b：");
    scanf("%d",&b);
    **/
    printf("\n答え：%.0f",baisu(a));

    return 0;
}

float baisu(float a/*,float b**/)
{
    float b;
    b = 2;
    a = a * b;
    return a;
}