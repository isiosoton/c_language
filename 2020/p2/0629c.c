#include <stdio.h>

int main(void)
{
	float	temp, h[4]={185.4,172.7,163.1,154.2};
	int	i=0, j=4;
	
	//データの出力
	for(i=0; i<4; i++)
	{
		printf("%6.1f", h[i]);
	}
	printf("\n");
	
	//並べ替え
    for(j=3;j>0;j--)
	{
		for(i=0;j>i;i++)
		{
			if (h[i]>h[i+1])
			{
				temp = h[i];
				h[i] = h[i+1];
				h[i+1] = temp;
			}
			printf("%d %d\n", i, i+1);
			// printf("%d　★\n",j);
		}
	}
	for(i=0; i<4; i++)
	{
		printf("%6.1f", h[i]);
	}
	printf("\n");
	
	return 0;
}
