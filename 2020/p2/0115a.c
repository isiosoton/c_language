#include <stdio.h>
#include <stdlib.h>

struct DATA
{
	  char	pref[50]; //都道府県名
	  int	area;   //面積
	  int	popu;   //人口
      float dens;   //人口密度
};

void fill(struct DATA data[]);
void sort(struct DATA date[]);

int main(void)
{
    int i,sw1;
    struct DATA data[50];
    fill(data);
    for(;;)
    {
        printf("メニュー\n1.全データを表示\n2.最大と最小を表示\n3.1と2以外　終了\n番号を選んでください:");
        scanf("%d",&sw1);
        switch(sw1)
        {
            case  1:for(i=0;i<47;i++)
                    {  
                        printf("%-10s\t%5dkm^2\t%8d人\t%4.1f人/km^2\n",data[i].pref,data[i].area,data[i].popu,data[i].dens);
                    }
                    break;
            case  2:sort(data);
                    break;
            case  3:exit(0);
                    break;
            default:printf("もう一度、入力してください\n");
                    break;
        }


    }
}

void fill(struct DATA data[])
{
    FILE *fp;
    int  i;
    //char filepref = "info2020-2.txt"

    if((fp = fopen("info2020-2.txt", "r")) == NULL)
    {
        printf("ファイルオープンエラー\n");
    }
    for(i=0; i<47; i++)
    {
        fscanf(fp, "%s%d%d", data[i].pref, &data[i].area, &data[i].popu);
        data[i].dens = data[i].popu / data[i].area;
        //printf("test%d\n",i);
    }
    fclose(fp);

}

void sort(struct DATA data[])
{
    int i;
    int s[4];
    for(i=0;i<46;i++)
    {
        if(data[s[0]].popu<data[i+1].popu)
        {
            printf("0-%s\n",data[i].pref);
            s[0] = i;
        }
        if(data[s[1]].popu>data[i+1].popu)
        {
            printf("1-%s\n",data[i].pref);
            s[1] = i;
        }
        if(data[s[2]].area<data[i+1].dens)
        {
            printf("2-%s\n",data[i].pref);
            s[2] = i;
        }
        if(data[s[3]].area>data[i+1].dens)
        {
            printf("3-%s\n",data[i].pref);
            s[3] = i;
        }
    }
    printf("人口\n最大%s\t%dkm^2\t%4.0f人/km^2\n最小%s\t%dkm^2\t%4.0f人/km^2\n",data[s[0]].pref,data[s[0]].popu,data[s[0]].dens,data[s[1]].pref,data[s[1]].popu,data[s[1]].dens);
    printf("人口密度\n最大%s\t%dkm^2\t%4.0f人/km^2\n最小%s\t%dkm^2\t%4.0f人/km^2\n",data[s[2]].pref,data[s[2]].popu,data[s[2]].dens,data[s[3]].pref,data[s[3]].popu,data[s[3]].dens);
}