#include <stdio.h>
int main(void)
{
    float b[4] = {180.5,190.0,163.2,140.1};
    float a;
    int c,d;
    for(a=0;a<4;a++)
    {
        for(c=3;a<c;c--)
        {
            if(b[c]>b[c-1])
            d = b[c-1];
            b[c+1] = b[c];
            b[c] = d;
            /*
            for(d=0;d<4;d++)
            {
                printf("%3.1f\n",b[d]);
            }
            **/
        }
    }
    for(d=0;d<4;d++)
    {
        printf("%3.1f\n",b[d]);
    }
}