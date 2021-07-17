#include <stdio.h>

int main(void)
{
	float	temp, h[4]={185.4,172.7,163.1,154.2};
	int	i=0, j;
	
	//データの出力
	for(i=0; i<4; i++)
	{
		printf("%6.1f", h[i]);
	}
	printf("\n");
	
	//並べ替え
    for(i=0; i<4; i++)
    {
        printf("%d %d\n", i, i+1);
    }
		
	
	return 0;
}
