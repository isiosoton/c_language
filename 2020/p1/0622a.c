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
	scanf("%f",&h[0]);
	scanf("%f",&h[1]);
	scanf("%f",&h[2]);
	scanf("%f",&h[3]);

	printf("\nfor文で全部出力してみよう。\n");
	int n=0;
	for(n=0;n<4;n++)
	{
		printf("%f\n",f[n]);
		n++;
	}

	printf("\nif文を使って100以上のものだけ出力してみよう。\n");
	for(n=0;n<4;n++)
	{
		if(h[i]>=100)
		{
			printf()
		}
	}
    
	return 0;
}
