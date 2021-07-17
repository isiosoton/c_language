#include <stdio.h>
int main(void)
{
    int     i, a, c=0;

    for(a=2; a<1100; a++)
    {
        for(i=2; i<(a/i); i++)
        {
            if((a%i) == 0)
            {
                break;
            }
        }
        if((a%i) != 0)
        {
            printf("%4d ", a);
            c++;
            if(c%10 == 0)
            {
                printf("\n");
            }
        } //if((a%i) != 0)
    } //for(a=2; a<1000; a++)
    printf("\n");
    
    return 0;
}
