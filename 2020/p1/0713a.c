#include <stdio.h>

int main(void)
{
	int	i, j, kuku[ 3 ][ 5 ];

	/* 配列変数kuku[][]への値の代入 */
    for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			kuku[ i ][ j ] = (i + 1) * (i + 1);
		}
	}

    for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%2d",kuku[i][j]);
		}
		printf("\n");
	}
	

    return 0;
}

