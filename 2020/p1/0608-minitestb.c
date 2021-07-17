#include <stdio.h>
int main(void)
{
    int     i;
    char    moji;
    
    i=1;
    while(i<=1000)
    {
        if(i%100 == 0)
        {
            i++;
            continue;
        }
        if(i%5 == 0)
        {
            printf("%d\n", i);
        }
        i++;
    }
    
    return 0;
}
