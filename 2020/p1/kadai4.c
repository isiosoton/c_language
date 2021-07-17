#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_range(int s, int e);

int main(void)
{
    int i, r, stat[11]={};
    int s=1, e=5;

    srand(time(NULL));

    for(i=0; i<100000; i++)
    {
		  r = random_range(s, e);
      printf("%d ", r);
      stat[r]++;
    }
    printf("\n");
    for(i=s; i<=e; i++)
    {
      printf("%d\t%d\n", i, stat[i]);
    }
	
	return 0;
}

/***************************************
 指定された二つの整数の間の乱数を返す関数
***************************************/
int random_range(int s, int e)
{
	return (rand() % (e-s+1) + s);
}
