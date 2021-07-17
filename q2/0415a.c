/*ソフトウエア演習A　2回目　課題1*/
#include<stdio.h>
#define L 10
#define RF "/home/hokut/q2/0415a.txt" //各自のパスとファイル名に置き換え
#define OUTFORM "%-10s%3d\n" //出力形式を変更しやすいようにここで定義

struct DATA
{
    char name[L]; //メンバー名1
    int p;        //メンバー名2
};

int main(void)
{
    struct DATA r; //構造体変数名
    FILE *fp;
    
    if ((fp=fopen(RF,"a")) == NULL){ //追加書き込みモード　教p229
        printf ("FILE("RF")OPEN ERROR\n");  //ファイルオープンエラーの時のエラー
    } else {
        while (printf("\n氏名="), scanf("%s",r.name)!=EOF)
        { //ctrl+dでEOF入力
            printf("得点=");
            scanf("%d",&r.p);
            fprintf(fp,OUTFORM,r.name,r.p); //書式指定子のマクロ定義名
        }
    }

    fclose(fp);
    return 0;

}

/*氏名は英文字入力
日本語と英字を混在させると、文字出力がずれるため
日本語はutf-8のコートの場合、一文字3バイト使用*/
