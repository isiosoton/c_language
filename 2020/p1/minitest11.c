#include<stdio.h>
#include<math.h>

void func(float data[6], float *ave, float *s);

int main(void)
{
    float data[6]={12.1,13.5,11.9,12.5,14.2,5.4};
    float ave, s;
    int i;

	func(data, &ave, &s);
	printf("平均値±標準偏差:%.1f±%.1f\n", ave, s);

	return 0;
}

void func(float data[6], float *ave, float *s)
{
	int i;
	for(*ave=i=0; i<6; i++)
    {
        *ave += data[i];
    }
    *ave /= 6.0;

	for(*s=i=0; i<6; i++)
    {
        *s += (data[i] - *ave) * (data[i] - *ave);
    }
    *s = sqrt(*s/6.0);
}