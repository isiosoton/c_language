#include <stdio.h>

int main(void)
{
	float	data, *data_p;
	
	printf("実数を入力してください：");
	scanf("%f", &data);
	
	data_p = &data;
	
	printf("data=> %f\n", *data_p);
	
	return 0;
}
