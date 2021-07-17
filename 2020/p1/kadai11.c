#include <stdio.h>
int main(void)
{
	int	i, j, N;
	float	h[10000], temp;

    for(i=0; scanf("%f", &h[i])!=EOF && i<10000; i++)
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
			if(h[i]>h[i+1])
			{
				temp = h[i];
				h[i] = h[i+1];
				h[i+1] = temp;
			}
		}
	}

    //結果の出力
    for(i=0; i<N; i++)
    {
        printf("%6.1f", h[i]);
    }
    printf("\n");

	return 0;
}
