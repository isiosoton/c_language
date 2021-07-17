#include <stdio.h>
int main(void)
{
    float data[4],a=0,b;
    while(scanf("%f",&data[a]) != EOF)
    {
        a += 1;
    }
    for(b=0;b>=a;b++)
    {
        printf("%2.1fcm\n",data[b]);
    }
    return 0;
}