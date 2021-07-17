/*ソフトウエア演習　課題2*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
#define L 11
#define RF "/home/hokut/q2/datanew50.txt"
#define PS %

struct DATA
{
    char name[L]; //名前
    int p; //得点
    double hen; //偏差値に用いる
    char h; //得点の段階評価に用いる
};

int comp_rank(const void *a, const void *b);
int comp_name(const void *a, const void *b);
void print(struct DATA r[],int k);

int main(void)
{
    //宣言
    FILE *fp;
    struct DATA r[MAX];
    int i,j,ave,sum,p,k;
    int ls = L - 1;
    int xi[L] = {};
    int rank[4] = {};
    double hens;

    //ファイル読込
    if((fp=fopen(RF,"r"))==NULL)
    {
        printf("FILE("RF") OPEN ERROR\n");
        exit(1);
    }
    for(i=0;i<MAX;i++)
    {
        fscanf(fp,"%s%d",r[i].name,&r[i].p);
    }

    //本文
    //平均値計算とグラフ入力
    for(i=0;i<MAX;i++)
    {
        sum += r[i].p; //点数合計値
        p = r[i].p / ls;
        //printf("test%2d:%2d\n",i,p);
        xi[p] += 1;
        if(r[i].p >= 80) {
            //strncpy(r[i].h, "A", 1);
            r[i].h = 'A';
            rank[0] += 1;
        } else if (80 > r[i].p && r[i].p >= 60) {
            r[i].h = 'B';
            rank[1] += 1;
        } else if (60 > r[i].p && r[i].p >= 50) {
            r[i].h = 'C';
            rank[2] += 1;
        } else {
            r[i].h = 'D';
            rank[3] += 1;
        }
        //printf("%d\n",i);
    }
    ave = sum / MAX;
    printf("平均値　=%2.0d\n",ave);

    //標準偏差計算
    for(i=0;i<MAX;i++)
    {
        hens += pow((double)r[i].p - (double)ave,2.0);
    }
    hens = sqrt(hens/MAX);
    printf("標準偏差=%2.0f\n",hens);

    //グラフ出力
    for(i=0;i<L;i++)
    {
        printf("%3d:%3d:",i*10,xi[i]);
        for(j=0;j<xi[i];j++)
        {
            printf("*");
        }
        printf("\n");
    }

    //評価表示
    printf("A=%2d%5.0f％ \n",rank[0],((float)rank[0]/MAX)*100);
    printf("B=%2d%5.0f％ \n",rank[1],((float)rank[1]/MAX)*100);
    printf("C=%2d%5.0f％ \n",rank[2],((float)rank[2]/MAX)*100);
    printf("D=%2d%5.0f％ \n",rank[3],((float)rank[3]/MAX)*100);
    //偏差値代入
    for(i=0;i<MAX;i++)
    {
        r[i].hen = ((double)r[i].p - (double)ave) * 10 / hens  + 50;
    }
    //得点順
    qsort(r,MAX,sizeof(r[0]),comp_rank);
    k = 0;
    print(r,k);
    //名前順
    qsort(r,MAX,sizeof(r[0]),comp_name);
    k = 1;
    print(r,k);

    fclose(fp);
    return(0);
}

int comp_rank(const void *a,const void *b)
{
    return(((struct DATA *)b)->p - ((struct DATA *)a)->p);
}

int comp_name(const void *a,const void *b)
{
    return(strcmp(((struct DATA *)a)->name,((struct DATA *)b)->name));
}

void print(struct DATA r[],int k)
{
    int i;
    int j[MAX] = {};
    printf("\n\n NO  氏名      得点  偏差値  評価 \n\n");
    for(i=0;i<MAX;i++){
        j[i] = i;
        if(r[i-1].p==r[i].p && k == 0)
        {
            j[i] = j[i-1];
        }
        printf("%3d %-10s%3d　　　%2.0f　　%c\n",j[i]+1,r[i].name,r[i].p,r[i].hen,r[i].h);
    }
}

//出力に評価を加える
//同点同順位を加える
//星配列を11にする