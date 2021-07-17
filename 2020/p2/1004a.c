#include <stdio.h>
// #include <math.h>

float jousu(float a,float n);
float kaker(float a,float n);
float seisu(float m);

int main(void)
{
    float a,n,m;
    printf("代入値a：");
    scanf("%f",&a);
    printf("代入値n：");
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