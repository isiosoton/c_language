#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
		int  i;

        /* 乱数系列の変更 */
		//srand(3);             //プログラムの先頭で1回だけ使用
		srand( time(NULL) );  //実行ごとに違う乱数系列にする

		/* 1～100の擬似乱数を10個発生 */
		for (i=1; i<=10; i++) 
        {
			printf("%d ", rand()%100+1);
        }
		printf("\n");
}
