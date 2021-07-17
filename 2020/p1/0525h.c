#include <stdio.h>
int main(void)
{
    int y , i;
    for(y=0,i=1;y<3000;i++)
    {
        y = y + 4;
        if(0==y%400) 
        {
            printf("i=%d,y=%d★\n", i, y);
        } else {
            printf("i=%d,y=%d\n", i, y);
        }
    }
}