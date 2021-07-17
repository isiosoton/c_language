#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SEL 5
#define MAX 100000

int main(void){
    srand(time(NULL));
    int m[SEL],c[SEL],c_sum[MAX]={0};
    int sum,c_max,c_min,p_sum=0,i,j;
    double dob;
    for(i=0;i<MAX;i++){
        sum = 0;
        for(j=0;j<SEL;j++){
            m[j] = rand()%1000;
            c[j] = m[j] * (SEL+1);
            sum += m[j];
        }
        for(j=0;j<SEL;j++){
            dob = round((double)c[j] / (double)sum);
            c_sum[i] += (int)dob;
        }
        //printf("c_sum:%d\n",c_sum[i]);
    }
    c_min = c_sum[0];
    c_max = c_sum[0];
    
    for(i=0;i<MAX;i++){
        if(c_min >= c_sum[i]){
            c_min = c_sum[i];
        }
        if(c_max <= c_sum[i]){
            c_max = c_sum[i];
        }
    }
    for(i=c_min;i<=c_max;i++){
        p_sum = 0;
        for(j=0;j<MAX;j++){
            if(c_sum[j]==i){
                p_sum += 1;
                //printf("%d\n",c_sum[j]);
            }
        }
        printf("%d:%2d%%\n",i,(p_sum*100)/MAX);
    }
}