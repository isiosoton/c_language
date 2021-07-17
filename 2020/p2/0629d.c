#include <stdio.h>

int main(void)
{
	int	i=0,j,k=9999,l,m=1;
	float temp, h[k],sort[k];
		
	//データの出力
	for(l=0;scanf("%f",&h[l]) != EOF && l < k; l++) //%dと%fに注意
	{
		sort[l] = h[l];　//メモのしすぎに注意
		// printf("%5d %3.1f\n",l,h[l]);
		m += 1;
	}
		
	//並べ替え
    for(j=k-1; 0<j; j--)
    {
		/*
		for(l=0;l<m;l++)
		{
			printf("%5d %3.1f \n",l,sort[l]);
		}
		**/
        for(i=0; i<j; i++)
		{
			if(sort[i]>sort[i+1])
			{
				temp = sort[i];
				sort[i] = sort[i+1];
				sort[i+1] = temp;
			}
			// printf("%d %d　★\n", i, i+1);
		}
    }

	int number=1;
	for(l=0;l<m;l++)
	{
		printf("%5d %3.1f \n",number,sort[l]);
		number += 1;
	}

		
	
	return 0;
}
