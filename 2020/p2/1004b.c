#include <stdio.h>

float A(void);
float B(void);
float baisu(float a/* ,float b**/);
float jousu(float a,float n);
float kaker(float a,float n);
float seisu(float m);

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
            case 1 :A();
                    break;
            case 2 :B();
                    break;
            default:printf("もう一度、入力してください");
                    break;
        }
        printf("\n終了する場合は1を、終了しない場合は1以外を入力：");
        scanf("%d",&b);
    }
    printf("終了しました");

    return 0;
}

float A(void)
{
    float a;
    float b;
    printf("二倍する値を入力してください：");
    scanf("%f",&a);
    /*
    printf("\n代入値b：");
    scanf("%f",&b);
    **/
    printf("答え：%.0f",baisu(a));

    return 0;
}

float baisu(float a/*,float b**/)
{
    float b;
    b = 2;
    a = a * b;
    return a;
}

float B(void)
{
    float a,n,m;
    printf("aのn乗におけるaの値を入力してください：");
    scanf("%f",&a);
    printf("aのn乗におけるnの値を入力してください：");
    scanf("%0f",&m);
    if (m == 0)
    {
        n = 0;
    }
    else if (m >= 0)
    {
        n = seisu(m);
    }
    else if (m <= 0)
    {
        m *= -1;
        n = seisu(m);
        n *= -1;
    }
    // n = floor(n);
    // printf("あ%f\n",n);
    printf("答え：%.4f",jousu(a,n));

    return 0;
}

float seisu(float m)
{
    float n;
    for(n=0;m>=0;m--)
    {
        n += 1;
        //printf("い%f\n",n);
    }
    n -= 1;
    return n;
}

float jousu(float a,float n)
{
    float p;
    if (n == 0)
    {
        p = 1;
    }
    else if (n >= 0)
    {
        p = kaker(a,n);
        //printf("う%f\n",p);
    }
    else if (n <= 0)
    {
        n *= -1;
        p = 1 / kaker(a,n);
        //printf("う%f\n",p);
    }

    return p;
}

float kaker(float a,float n)
{
   float count,k=1;
   for(count=1;count<=n;count++)
   {
       k *= a;
       //printf("い%f\n",k);
   }

   return k;
}