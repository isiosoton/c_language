#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int	stat[201][201]={};
		int	i, j, x, y, r;

		//10000人ループ
		for(i=0; i<1000000; i++)
		{
				x = y = 0;
				
				//100歩ループ
				//xとyの範囲：-100〜100
				//printf("歩   x   y\n");
				for(j=0; j<100; j++)
				{
						r = rand()%4;
						//方向分岐
						switch(r)
						{
								case 0: x++; break;
								case 1: x--; break;
								case 2: y++; break;
								case 3: y--; break;
						}
						//printf("%3d %3d %3d\n", j, x, y);
				}
				//201×201の表（行列）に座標値の数として集計
				stat[x+100][y+100]++;
		}

		//集計結果の出力
		for(i=0; i<201; i++)
		{
				for(j=0; j<201; j++)
				{
						printf("%d\t", stat[i][j]);
				}
				printf("\n");
		}
		
		return 0;
}
