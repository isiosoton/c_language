#include <stdio.h>

float nibai(float x);
float njou(float a, int n);

int main(void)
{
		float	result;
		
		result = nibai(4);
		printf("%.3fの2倍=%.3f\n", a, result);
		
		result =njou(2, 3);
		printf("%.3fの%d乗=%.3f\n", a, n, result);
		
		return 0;
}

/***************************************
 aのn乗を返す関数
***************************************/
float njou(float a, int n)
{
	int i;
	float x;
	
	x = a;
	for(i=1; i<abs(n); i++)
	{
		x *= a;
	}
	if(n<0)
	{
		x = 1.0/x;
	}
	
	return x;
}

/***************************************
 引数の2倍を返す関数
***************************************/
float nibai(float x)
{
		return x*2.0;
}
