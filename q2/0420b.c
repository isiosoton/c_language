//情報工学実験　第2回内容
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define T 1000 //時刻
int main(void)
{
    srand((unsigned)time(NULL));
    int i,j;
    int a = 0;
    int y[T];
    int copy1[T];
    int copy2;
    double rn;
    for(i=0;i<T;i++)
    {
        rn = rand()/(1.0+RAND_MAX);
        y[i] = a;
        copy1[i] = y[i];
        if(rn<0.5)
        {
            a -= 1;
        } else {
            a += 1;
        }
    }
    for(j=T-1;0<j;j--)
    {
        for(i=0;i<j;i++){
            if(copy1[i]>copy1[i+1])
            {
                copy2 = copy1[i];
                copy1[i] = copy1[i+1];
                copy1[i+1] = copy2;
            }
        }
    }
    for(i=copy1[T-1];copy1[0]<i;i--)
    {
        printf("%3d",i);
        for(j=0;j<T;j++)
        {
            if(y[j]==i)
            {
                printf("■");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}