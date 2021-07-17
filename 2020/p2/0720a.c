#include<stdio.h>
int main(void)
{
    int a,b,c=0;
    float tall[1000][2], hang, avarage;
    //printf("%d",c);
    for(a=0;scanf("%f %f",&tall[a][0],&tall[a][1]) != EOF /*|| a<=1000**/;a++)
    {
        hang += tall[a][0];
        //printf("%f",tall[a][0]);
    }
    hang /= a+1;
    a -= 1;
    for(b=0;a<=b;b++)
    {
        if(tall[b][0] >= hang)
        {
            c += 1;
            avarage += tall[b][1];
        }
    }
    avarage /= c;
    printf("\n人数:%4d人\n平均身長:%3.1fcm\n平均身長以上の人数:%d人\n平均身長以上の人の平均体重:%3.1fkg",a,hang,c,avarage);
    return 0;
}