#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void stat(float data[6], float *max, float *min, float *sum );

int main(void)
{
    srand(time(NULL));
    float data[6];
    float max, min, sum;
    for(int math = 0; math < 6 ;math++)
    {
        data[math] = rand() % 1000;
        //printf("%4.0f\n",data[math]);
    }
    stat(data,&max,&min,&sum);
    printf("最大値：%4.0f\n最小値：%4.0f\n合計値：%4.0f", max, min, sum);

    return 0;
}

void stat(float data[6],float *max,float *min,float *sum)
{
    //printf("初期値：%4.0f\n",data[0]);
    *max = data[0];
    *min = data[0];
    int math;
    for(math = 0;math < 5;math++)
    {
        *sum += data[math];
        
        if(*max < data[math+1])
        {
            *max = data[math + 1];
            //printf("最大値：%4.0f\n",*max);
        }
        
        if(*min > data[math+1])
        {
            *min = data[math + 1];
            //printf("最小値：%4.0f\n",*min);
        }
    }
    *sum += data[math + 1];
}
