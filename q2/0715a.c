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
    FILE *fps[FC],*fp, *fp1, *fp2, *fp3;
    int d1[N1][H], d2[N2][H];
    int c[H][2] = {{0,0}};
    int i, j, i1=0, i2=0;
    char filename[FC][L] = {F1,F2,F3};
    struct DATA item_ave[H];
    /*
    for(i=0;i<FC;i++){
        fps[i] = fopen(filename[i],"r");
        if(fp[i]==NULL){
            printf("FILE("%s") OPPEN ERROR\n",filename[i]);
            exit(1);
        }
    }
    */
    
    fp1=fopen(F1,"r");
    fp2=fopen(F2,"r");
    fp3=fopen(F3,"r");


    if(fp1==NULL){
        printf("FILE("F1") OPPEN ERROR");
        exit(1);
    }

    if(fp2==NULL){
        printf("FILE("F2") OPPEN ERROR");
        exit(1);
    }

    if(fp2==NULL){
        printf("FILE("F3") OPPEN ERROR");
        exit(1);
    }
    //printf("data1\n");
    for(i=0;i<N1;i++){
        for(j=0;j<H-2;j++){
            fscanf(fp1,"%1d",&d1[i][j]);
            //printf("%1d",d1[i][j]);
        }
        fscanf(fp1,"%3d",&d1[i][SN-1]);
        //printf("%3d",d1[i][SN-1]);
        fscanf(fp1,"%1d",&d1[i][SN]);
        //printf("%2d\n\n",d1[i][SN]);
    }
    //printf("data2\n");
    for(i=0;i<N2;i++){
        for(j=0;j<H-2;j++){
            fscanf(fp2,"%1d",&d2[i][j]);
            //printf("%1d",d2[i][j]);
            //printf("test1\n");
        }
        fscanf(fp2,"%3d",&d2[i][SN-1]);
        //printf("%3d",d2[i][SN-1]);
        fscanf(fp2,"%1d",&d2[i][SN]);
        //printf("%2d\n\n",d2[i][SN]);
    }

    for(i=0;i<H-3;i++){
        fscanf(fp3,"%s",item_ave[i].item);
    }

    qsort(d1,N1,sizeof(d1[0]),intcmp);
    qsort(d2,N2,sizeof(d2[0]),intcmp);

    while((i1<N1)&&(i2<N2)){
        //printf("%3d:%3d ",d1[i1][SN-1],d2[i2][SN-1]);
        if(d1[i1][SN-1]==d2[i2][SN-1]){
            //printf("1\n");
            for(j=0;j<SN-1;j++){
                if((d1[i1][j]!=0)&&(d2[i2][j]!=0)){
                    c[j][0] += d2[i2][j]-d1[i1][j];
                    c[j][1]++;
                    //printf("j:%3d　c1:%2d　c2:%3d\n",j,c[j][0],c[j][1]);
                    //printf("j:%3d　d1:%2d　d2:%3d\n",j,d1[i1][j],d2[i2][j]);
                }
            }
            i1++;
            i2++;
        } else if (d1[i1][SN-1]<d2[i2][SN-1]) {
            i1++;
            //printf("2\n");
        } else {
            i2++;
            //printf("3\n");
        }
    }

    for(i=0;i<H-3;i++){
        item_ave[i].ave=(double)c[i][0]/c[i][1];
    }
    qsort(item_ave,H-3,sizeof(item_ave[0]),intcmpave);
    for(i=1;i<SN-1;i++){
        printf("rank_NO=%3d　%6.3f　%s\n",i,item_ave[i-1].ave,item_ave[i-1].item);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
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

