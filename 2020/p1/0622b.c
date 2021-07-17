#include <stdio.h>
int main(void)
{
	int	i;
	float	h[4] = {45.3, 231.3, 2.32, 54.1};
	
	printf("変数の値も画面に出力してみよう。\n");
	printf("%8.2fcm\n", h[0]);
	printf("%8.2fcm\n", h[1]);
	printf("%8.2fcm\n", h[2]);
	printf("%8.2fcm\n", h[3]);
	
	printf("\nキーボードからデータを入力できるように修正してみよう。\n");
	printf("実数を4つ入力してください\n");
	for(i=0; i<4; i++)
	{
		scanf("%f", &h[i]);
	}
	
	printf("\nなんならfor文で全部出力してみよう。\n");
	for(i=0; i<4; i++)
	{
		printf("%8.2fcm\n", h[i]);
	}
	
	printf("\nif文を使って100以上のものだけ出力してみよう。\n");
	for(i=0; i<4; i++)
	{
		if(h[i]>=100)
		{
			printf("%8.2fcm\n", h[i]);
		}
	}
	
	return 0;
}
