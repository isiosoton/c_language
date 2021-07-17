/*ソフトウエア演習A　第3回　課題*/
#include<stdio.h>
#include<stdlib.h>
# define MAX 50
# define L 10
# define RF "/home/hokut/q2/0519a.txt"
# define RECSIZE 14
# define OUTFORM "%-10s%3d\n"

struct DATA
{
    char name[L];
    int p;
};

void shu(void);
void san(void);
void tui(void);

int main(void)
{
    struct DATA r;
    int no;
    long int no_up;
    FILE *fp;

    if((fp=fopen(RF,"rb")) == NULL) //バイナリモードで読込可
    {
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    } else {
        fseek(fp,0,SEEK_END); //ファイルの最後に異動　最後から異動しない
        no_up = ftell(fp) / RECSIZE; //上記fseekでのデータの位置(半角分で何文字目かを示す) / 一人当たりの文字数で割り上限人数を算出 
        fclose(fp); //いったん閉じる
    }
    fp = fopen(RF,"r+"); //テキストモードでファイルのopen処理をする
    while(printf("\nNo(1~%ld)=",no_up),scanf("%d",&no)!=EOF)
    {
        for(;1;)
        {
            if(no <= no_up) //上限人数範囲内のみ処理
            {
                fseek(fp,(no - 1) * RECSIZE,SEEK_SET);
                fscanf(fp,"%s%d",r.name,&r.p);
                break;
            } else {
                printf("\nNo(1~%ld)=",no_up);
                scanf("%d",&no);
            }
        }
        printf("  NO  氏名      得点\n");
        printf("%4d %-10s%3d\n",no,r.name,r.p);
        printf("\n訂正得点=");
        scanf("%d",&r.p);
        fseek(fp,(no - 1) * RECSIZE,SEEK_SET);
        fprintf(fp,OUTFORM,r.name,r.p);
    }
    fclose(fp);
    return(0);
}