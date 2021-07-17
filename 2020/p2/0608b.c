#include <stdio.h>
int main(void)
{
    int a=5;
    while(a < 1001)
    {
        
        if(0==a%100)
        {
            
        } else {
            printf("%d\n",a);
        }
        a += 5;
    }

    return 0;
}