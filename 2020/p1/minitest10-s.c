#include<stdio.h>
#include<math.h>

void func(float data[6], float *ave, float *s);

int main(void)
{
    float data[6]={12.1,13.5,11.9,12.5,14.2,5.4};
    float ave,s;
    
    func(data,&ave,&s);

	printf("1. 配列変数の6つの値の平均値と標準偏差を算出する。\n");
    printf("　　標準偏差 = pow((Σxi - X)*(Σxi - X)/6.0, 0.5)\n");
    printf("　　※Xは平均値とする。\n");
    printf("　　※math.hをincludeする必要がある。\n");
    printf("2. 平均値および標準偏差の計算結果を関数の引数を用いて返す。\n");
    printf("3. main関数において、平均値および標準偏差を画面に出力する。\n\n");

    printf("平均値　：%3.1f\n標準偏差：%3.1f",ave,s);

	return 0;
}

void func(float data[6], float *ave, float *s)
{
    int a;

    for(*ave=a=0;a<6;a++)
    {
        *ave += data[a];
    }

    *ave /= 6;

    for(*s=a=0;a<6;a++)
    {
        *s += ((data[a] - *ave) * (data[a] - *ave));
        //printf("%f\n",s);
    }

    *s /= 6;
    printf("%f\n",s);

    *s = sqrt(*s);
}