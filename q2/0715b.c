#include <stdio.h>
#include <stdlib.h>
#define H  183 //調査項目数
#define L  200 //ラベル上限文字数
#define N1 189 //調査人数
#define N2 168 //調査人数
#define SN 182 //識別項目番号
#define FC 3 //ファイルの個数
#define F1 "/home/hokut/q2/kou29_1_SA.txt"//一回目のデータ
#define F2 "/home/hokut/q2/kou29_2_SA.txt"//二回目のデータ
#define F3 "/home/hokut/q2/H29label.txt"//調査項目別ラベル

int intcmp(const void *a, const void *b);
int intcmpave(const void *a, const void *b);

struct DATA{
    char item[L];
    double ave;
};

int main(void){
    FILE *fps[FC];
    int d[2][N1][H];
    int c[H][2] = {{0,0}};
    int max[2] = {N1,N2};
    int i, j, k;
    int i1=0, i2=0;
    char filename[FC][L] = {F1,F2,F3};
    struct DATA item_ave[H];

    for(i=0;i<FC;i++){
        fps[i] = fopen(filename[i],"r");
        if(fps[i]==NULL){
            printf("FILE(%s) OPPEN ERROR\n",filename[i]);
            exit(1);
        }
        if(i==2){
            for(k=0;k<H-3;k++){
                fscanf(fps[i],"%s",item_ave[k].item);
            }
        } else {
            for(k=0;k<max[i];k++){
                for(j=0;j<H-2;j++){
                    fscanf(fps[i],"%1d",&d[i][k][j]);
                }
                fscanf(fps[i],"%3d",&d[i][k][SN-1]);
                fscanf(fps[i],"%1d",&d[i][k][SN]);
            }
            qsort(d[i],max[i],sizeof(d[i][0]),intcmp);
        }
    }

    while((i1<N1)&&(i2<N2)){
        if(d[0][i1][SN-1]==d[1][i2][SN-1]){
            for(j=0;j<SN-1;j++){
                if((d[0][i1][j]!=0)&&(d[1][i2][j]!=0)){
                    c[j][0]+= d[1][i2][j]-d[0][i1][j];
                    c[j][1]++;
                }
            }
            i1++;
            i2++;
        } else if (d[0][i1][SN-1]<d[1][i2][SN-1]) {
            i1++;
        } else {
            i2++;
        }
    }
    for(i=0;i<H-3;i++){
        item_ave[i].ave=(double)c[i][0]/c[i][1];
    }
    qsort(item_ave,H-3,sizeof(item_ave[0]),intcmpave);
    for(i=1;i<SN-1;i++){
        printf("rank_NO=%3d　%6.3f　%s\n",i,item_ave[i-1].ave,item_ave[i-1].item);
    }
    for(i=0;i<FC;i++){
        fclose(fps[i]);
    }
    return 0;
}

int intcmp(const void *a, const void *b){
    return(((int *)a)[SN-1]-((int *)b)[SN-1]);
}

int intcmpave(const void *a, const void *b){
    if      (((struct DATA *)a)->ave < ((struct DATA *)b)->ave) return  1;
    else if (((struct DATA *)a)->ave ==((struct DATA *)b)->ave) return  0;
    else                                                        return -1;
}