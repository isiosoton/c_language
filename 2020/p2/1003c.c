#include <stdio.h>

float baisu(float a);
float jousu(float a, float n);
float kaker(float a, float n);

int main(void)
{
    float a;
    int b,n,i;
    for(b=0;b!=1;)
    {
        printf("倍数計算は1,乗数計算は2を入力してください：");
        scanf("%d",&i);
        switch(i)
        {
            case 1 :printf("二倍する値を入力してください：");
                    scanf("%f",&a);
                    printf("\n%f",baisu(a));
            case 2 :printf("aのn乗におけるaの値を入力してください：");
                    scanf("%f",&a);
                    printf("aのn乗におけるnの値を入力してください：");
                    scanf("%d",&n);
                    printf("\n%f",jousu(a,n));
            default:printf("もう一度、入力してください\n");
                    break;
        }
        printf("終了する場合は1を、終了しない場合は1以外を入力：");
        scanf("%d",&b);
    }
    printf("終了しました");

    return 0;
}

float baisu(float a)
{
    int n;
    n = 2;
    return a*n;
}


float jousu(float a,float n)
{
    float d;
    if (n>0)
    {
        d = kaker(a,n);
    }
    else if (n=0)
    {
        d = 1 ;
    }
    else //if (n<0)
    {
        d = 1/kaker(a,n);
    }   
    return d;
}

float kaker(float a,float n)
{
    float e;
    int c;
    for(c=1;c>n;c++)
    {
        e = a * a;
    }
    return e;
}
