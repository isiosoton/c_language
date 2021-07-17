#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"0610b.c"
#define MAX 50000
#define L 31
#define RF "/home/hokut/q2/datarandom.txt" //ファイル名

void bubble(char name2[][L]); //バブルソート
void bubble_p(char *namep[]); //バブルソートポインタ配列用
void coms11(char name[][L]);  //コムソート11
void coms11_p(char *namep[]); //コムソート11ポインタ配列用
int qstcmp(const void *a,const void *b);  //クイックソート
int qstcmp_p(const void *a,const void *b);//クイックソートポイント配列用

int main(void) {
    clock_t start_time;
    double m, mp;
    int i,j,p=0;
    char *namep[MAX];
    char name[MAX][L];
    FILE *fp;

    if((fp=fopen(RF,"r"))==NULL) {
        printf("FILE("RF")OPPEN ERROR");
        exit(1);
    }

    for(j=0;j<6;j++) {
        if(j!=0) {
            fseek(fp,0,SEEK_SET); //ファイルポインタを先頭に移動させてから下記の行でファイルを再読み込み
        }
        for(i=0;i<MAX;i++) {
            fscanf(fp,"%s",name[i]);
        }
        if(p==1) {
            for(i=0;i<MAX;i++) {
                namep[i] = name[i]; //文字列の先頭アドレスが代入される
            }
        }
        switch (j) {
            case  0:printf("\nバブルソート:");
                    break;
            case  1:printf("\nバブルソートポインタ:");
                    break;
            case  2:printf("\nコムソート11:");
                    break;
            case  3:printf("\nコムソート11ポインタ:");
                    break;
            case  4:printf("\nクイックソート:");
                    break;
            case  5:printf("\nクイックソートポインタ:");
                    break;
        }
        start_time = clock();
        switch (j) {
            case  0:bubble(name);
                    break;
            case  1:bubble_p(namep);
                    break;
            case  2:coms11(name);
                    break;
            case  3:coms11_p(namep);
                    break;
            case  4:qsort(name,MAX,sizeof(name[0]),qstcmp);
                    break;
            case  5:qsort(namep,MAX,sizeof(namep[0]),qstcmp_p);
                    break;
        }
        mp = ((double)(clock()-start_time)/CLOCKS_PER_SEC);
        printf("%5f\n",mp);
        if(j%2==0) {
            for(i=0;i<10;i++) {
                printf("%s\n",name[i]);
            }
            m = mp;
            p = 1;
        } else {
            for(i=0;i<10;i++) {
                printf("%s\n",namep[i]);
            }
            if(mp>0){
                printf("\n 通常バブル速度 / ポインタ配列使用速度 = %.2f\n",m/mp);
            } else {
                printf("計算不可\n");
            }
            p = 0;
        }
    }
    fclose(fp);
    return 0;
}

void bubble(char name[][L]) {
    int i, bound,newbound;
    char tempc[L];
    bound = MAX - 1;
    while(bound>0) {
        newbound = 0;
        for(i=0;i<bound;i++) {
            if(strcmp(name[i],name[i+1]) > 0) {
                strcpy(tempc,name[i]);
                strcpy(name[i],name[i+1]);
                strcpy(name[i+1],tempc);

                newbound = i;
            }
        }
        bound = newbound;
    }
}

void bubble_p(char *namep[]) {
    int i, bound, newbound;
    char *temp;
    bound = MAX - 1;
    while(bound>0) {
        newbound = 0;
        for(i=0;i<bound;i++) {
            if(strcmp(namep[i],namep[i+1]) > 0) {
                temp = namep[i]; //文字列のコピーはポインタをコピーした方が楽
                namep[i] = namep[i+1];
                namep[i+1] = temp;

                newbound = i;
            }
        }
        bound = newbound;
    }
}

void coms11(char name[][L]) {
    int bound = MAX;
    int i,j=0;
    char tempc[L];

    while(1<bound || j==1) {
        if(1 < bound) {
            bound = (bound * 10) / 13;
        }
        j = 0;
        for(i=0;i < MAX-bound; i++) {
            if(strcmp(name[i],name[i+bound]) > 0) {
                strcpy(tempc,name[i]);
                strcpy(name[i],name[i+bound]);
                strcpy(name[i+bound],tempc);
                j = 1;
            }
        }
    }
    //自分で考える
}

void coms11_p(char *namep[]) {
    int bound = MAX;
    int i, j= 0;
    char *temp;

    while (1<bound || j==1) {
        if (1 < bound) {
            bound = (bound * 10) / 13;
        }
        j = 0;
        for (i=0;i < MAX-bound; i++) {
            if(strcmp(namep[i],namep[i+bound])>0) {
                temp = namep[i];
                namep[i] = namep[i+bound];
                namep[i+bound] = temp;
                j = 1;
            }
        }
    }
    //自分で考える
}

int qstcmp(const void *a,const void *b) {
    return(strcmp((char *)a,(char *)b));
}

int qstcmp_p(const void *a,const void *b) {
    return(strcmp(*(char **)a,*(char **)b));
}