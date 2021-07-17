//情報工学実験　第2回内容
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
    srand((unsigned)time(NULL));
    int i;
    double rn;
    for(i=0;i<10;i++)
    {
        rn = rand()/(1.0+RAND_MAX);
        printf("%f ",rn);
        if(rn<0.5)
        {
            printf("head\n");
        } else {
            printf("tail\n");
        }
    }
}