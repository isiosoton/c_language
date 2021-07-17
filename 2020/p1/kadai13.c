#include <stdio.h>
int main(void)
{
	int	i, j, N;
	float	h[1000][2], temp;

    for(i=0; scanf("%f%f", &h[i][0], &h[i][1])!=EOF && i<1000; i++)
    {
        //printf("%f\n", h[i]);
    }
	N = i;
	
	//並べ替え
	for(j=N-1; j>0; j--)
	{
		for(i=0; i<j; i++)
		{
			//printf("%d %d\n", i, i+1);
			if(h[i][0]>h[i+1][0])
			{
				temp = h[i][0];
				h[i][0] = h[i+1][0];
				h[i+1][0] = temp;
				temp = h[i][1];
				h[i][1] = h[i+1][1];
				h[i+1][1] = temp;
			}
		}
	}

    //結果の出力
    for(i=0; i<N; i++)
    {
        printf("%6.1f %6.1f\n", h[i][0], h[i][1]);
    }

	return 0;
}
