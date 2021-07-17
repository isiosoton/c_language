#include <stdio.h>
int main(void)
{
	int	i, N;
	float	h[100000];
	
	printf("ファイルからデータを読み込もう。ただしデータ数は不明です。最大10000個。\n");
    printf("もしデータ数が10000になったらwhile文を強制終了するように修正\n");
    i=0;
	while(scanf("%f", &h[i]) != EOF)
	{
		i++;
	}
	N = i;
	
	printf("\n読み込み終了後、全データを出力する。\n");
	for(i=0; i<N; i++)
	{
		printf("%8.2f\n", h[i]);
	}
	
	return 0;
}
