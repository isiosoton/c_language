#include <stdio.h>
int main(void)
{
    int count, i;

    for(count=1, i=1; i<=3000; i++)
    {
        if(i%4 == 0)
        {
            printf("%4d %4d", count, i);
            if(i%400 == 0)
            {
                printf("☆☆☆ ");
            }
            else
            {
                printf("    ");
            }
            
            if(count%5 == 0)
            {
                printf("\n");
            }
            count++;
        }
    }
}
