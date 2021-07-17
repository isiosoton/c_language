#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void janken(void);

int main(void)
{
    srand(time(NULL));
	janken();
		
	return 0;
}

void janken(void)
{
    int r;
    r = rand()%3;
    if(r==0)
    {
        printf("グー\n");
    }
    else if(r==1)
    {
        printf("チョキ\n");
    }
    else if(r==2)
    {
        printf("パー\n");
    }
}
