#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50000 //作成する文字列の数
#define MSMAX 30  //作成する1文字列の文字数
#define RF "/home/hokut/q2/datarandom.txt" //ファイル名

int main(void) {
    char strings[MSMAX + 1]; //文字列を入れる配列
    int show_count; //文字列を表示する回数
    int i; //for文で用いる
    FILE *fp;

    printf("RAND_MAX=%d\n",RAND_MAX);

    if((fp=fopen(RF,"w"))==NULL) {
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    }
    srand(time(NULL)); //randを毎度別の値に返すための関数
    show_count = MAX;
    while(show_count!=0) {
        show_count--;
        for(i=0;i<MSMAX;i++) {
            strings[i] = 'a' + rand()%('z'-'a'+1);
        }
        strings[MSMAX] = 0; //文字列の終了コード
        fprintf(fp,"%s\n",strings); //ファイルへの書き込み
        printf("%s\n",strings);
    }
    fclose(fp);
    return 0;
}