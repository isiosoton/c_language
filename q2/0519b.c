/*ソフトウエア演習A　第3回　課題*/
#include<stdio.h>
#include<stdlib.h>
# define MAX 50
# define L 10
# define RF "/home/hokut/q2/0519a.txt"
# define RECSIZE 14 //一人当たりの文字数+1(改行コード分)
# define OUTFORM "%-10s%3d\n"

struct DATA
{
    char name[L];
    int p;
};

void shu(void); //戻り値、返り値なしの指定
void san(void);
void tui(void);

int main(void)
{
    int i;
    int j = 0;
    while(j != 1)
    {
        printf("\n\n修正(1),参照(2),追加(3),終了(4)=");
        scanf("%d",&i);
        switch(i)
        {
            case  1:shu();
                    break;
            case  2:san();
                    break;
            case  3:tui();
                    break;
            case  4:j=1;
                    break;
            default:printf("もう一度、入力してください");
                    break;
        }
    }
    return 0;
}

void shu() //修正用関数
{
    struct DATA r;
    int no,no_up;
    int s = 0;
    FILE *fp;

    if((fp=fopen(RF,"rb"))==NULL)
    {
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    } else {
        fseek(fp,0,SEEK_END); //ファイルの最後に移動
        no_up = ftell(fp) / RECSIZE; //fseekのデータ位置
        fclose(fp);
    }

    fp = fopen(RF,"r+"); //テキストモード
    while(s!=1 && s!=2 && s!=3)
    {
        printf("\n氏名のみ変更(1),得点のみ変更(2),氏名と得点の変更(3)=");
        scanf("%d",&s);
    }
    while(printf("\nNo(1-%d)=",no_up),scanf("%d",&no)!=EOF)
    {
        if(no>no_up)
        {
            printf("再入力してください。");            
            continue;
        }        
        fseek(fp,(no-1)*RECSIZE,SEEK_SET);
        fscanf(fp,"%s%d",r.name,&r.p);
        printf("  NO  氏名      得点\n");
        printf("%4d  %-10s%3d\n",no,r.name,r.p);
        switch(s)
        {
            case  1:printf("\n 訂正氏名=");
                    scanf("%s",r.name);
                    break;
            case  2:printf("\n 訂正得点=");
                    scanf("%d",&r.p);
                    break;
            case  3:printf("\n 訂正氏名=");
                    scanf("%s",r.name);
                    printf("\n 訂正得点=");
                    scanf("%d",&r.p);
                    break;
            default:printf("再入力してください。");
                    break;
        }
        fseek(fp,(no-1)*RECSIZE,SEEK_SET);
        fprintf(fp,OUTFORM,r.name,r.p);
    }
    fclose(fp);
}

void san() //参照用関数
{
    struct DATA r;
    int no, no_up;
    FILE *fp;

    if((fp=fopen(RF,"rb"))==NULL)
    {
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    } else {
        fseek(fp,0,SEEK_END); //ファイルの最後に移動
        no_up = ftell(fp) / RECSIZE; //fseekのデータ位置
        fclose(fp);
    }

    fp = fopen(RF,"a+"); //追加書き込みと参照モード
    while(printf("\nNo(1-%d)=",no_up),scanf("%d",&no)!=EOF)
    {
        if(no>no_up)
        {
            printf("再入力してください。");            
            continue;
        }
        fseek(fp,(no-1)*RECSIZE,SEEK_SET);
        fscanf(fp,"%s%d",r.name,&r.p);
        printf("  NO  氏名      得点\n");
        printf("%4d  %-10s%3d\n",no,r.name,r.p);
    }
    fclose(fp);

}

void tui() //追加用関数
{
    struct DATA r;
    FILE *fp;
    if((fp=fopen(RF,"a"))==NULL) //追加書き込みモード
    {
        printf("FILE("RF")OPEN ERROR\n");
        exit(1);
    } else {
        while(printf("\n氏名="),scanf("%s",r.name)!=EOF)
        {
            printf("得点=");
            scanf("%d",&r.p);
            fseek(fp,0,SEEK_END); //追加処理の位置決め
            fprintf(fp,OUTFORM,r.name,r.p);
        }
    }
    fclose(fp);
}

//fseek(ファイルポインタ,どれだけ移動させるか,どの位置から移動させるか)