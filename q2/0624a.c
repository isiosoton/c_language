//構造体でのポインタ配列qsort関数使用例
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50000
#define L 11
#define RF ""

struct DATA{
    char name[L];
    int p;
    char add[L];
};

int comp_p(const void *a,const void *b);
int comp_name(const void *a,const void *b);

int main(void){
    char name[MAX][L];
    char *namep[MAX];
    void print(struct DATA **rp);
    if((fp=fopen(RF,"r"))==NULL){
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    }

    for(i=0;i<MAX;i++){

    }

    for(i=0;i<MAX;i++){
        fscanf(fp,"%s%d%s",)
    }
    start_time = clock();
    qsort(rp,MAX,sizeof(rp[0]),comp_p);
    print(rp);
    printf("\n%f\n\n",((double)(clock()-time)))
}

int comp_p(const void *a,const void *b){
    return (*(struct DATA **)b) -> p -(*)
}

void print(struct DATA **rp){
    int i;

    printf("  NO  氏名      得点 住所\n\n");
    
}