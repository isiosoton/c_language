/*第3回　ソフトウエア演習A*/

#include <stdio.h>
# define MAX 50
# define RF ""
# define OUTFORM "%-10s%3d\n" //氏名10文字と数値3行
# define RECSIZE 14 //一人当たりの文字数 +1(改行コード分)

struct DATA
{
    char name[L];
    int p;
};

int main(void)
{
    struct DATA r;
    int no, select;
    FILE *fp;

    if((fp=fopen(RF,"a+")) == NULL) //追加書き込みと参照モード　教p229
    {
        printf("FILE("RF")OPEN ERROR\n");
    } else {
        printf("参照=1 / 追加=2");
        scanf("%d",&select);
        if(select == 1)
        {
            while(printf("\nNo.="),scanf("%d",&no)!=EOF)
            {
                fseek(fp,(no-1)*RECSIZE,SEEK_SET);　//ファイル位置　ファイルの先頭から何人目(RECSIZEの倍数)
                fscanf(fp,"%s%d",r.name,&r.p);
                printf("  NO  氏名　　　得点\n");
                printf("%4d %-10s%3d\n",no, r.name, r.p);
            }
        } else {
            while(printf("\n 氏名="),scanf("%s",r.name) != EOF)
            {
                printf("得点=");
                scanf("%d",&r.p);
                fseek(fp,0,SEEK_END); //追加処理の場合の位置決め

                fprintf(fp,OUTFORM,r.name,r.p); //そのまま追加
            }
        }

        fclose(fp);

        return 0;
    }
}