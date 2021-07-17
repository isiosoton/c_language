#include<stdio.h>

int main(void)
{
    // A
    float data;
    printf("値を入力して下さい：");
    scanf("%f",&data);
    // B
    float *data_p;
    data_p = &data;
    printf("%f", *data_p);

    return 0;
}