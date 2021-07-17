#include <stdio.h>

int main(void)
{
	int tate,yoko;
    tate = 3;
    yoko = 5;
    printf("縦列を指定してください：");
    scanf("%d",&tate);
    printf("\n横列を指定してください：");
    scanf("%d",&yoko);
    int	i, j, kuku[ tate ][ yoko ];

	/* 配列変数kuku[][]への値の代入 */
    for(i=0;i<tate;i++)
	{
		for(j=0;j<yoko;j++)
		{
			kuku[ i ][ j ] = (i + 1) * (j + 1);
		}
	}

    // printf("    0  1  2  3  4\n");
    printf("\n   ");
    for(j=0;j<yoko;j++)
    {
        printf("%5d",j);
    }

    printf("\n");

    for(i=0;i<tate;i++)
	{
		printf("%2d|",i);
        for(j=0;j<yoko;j++)
		{
			printf("%5d",kuku[i][j]);
		}
		printf("\n");
	}
	

    return 0;
}