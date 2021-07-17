#include<stdio.h>
#include<stdlib.h>

struct TIME
{
    int h;
    int m;
    int s;
};

void file(char name[20][50],struct TIME one[], struct TIME two[]);

int main(void)
{
    struct TIME one[20]={0}, two[20]={0};
    char name[20][50];
    int scan,i=0;
    file(name,one,two);
    printf("メニュー\n1.往路の記録を表示\n2.復路の記録を表示\n3.総合記録を表示\n4.終了\n番号を選んでください");
    scanf("%d",scan);

    switch(scan)
    {
        case  1:for(i=0;i<20;i++)
                {
                    printf("%s\t%1dh\t%3dm\t%3ds\n",name[i][20], one[i].h, one[i].m, one[i].s);
                }
                break;
        case  2:for(;i<20;i++)
                {
                    printf("%s\t%1dh\t%3dm\t%3ds\n",name[i][20], two[i].h, two[i].m, two[i].s);
                }
                break;
        case  3:break;
        case  4:break;
        default:break;
    }
}

void file(char name[20][50],struct TIME one[], struct TIME two[])
{
    FILE *fp;
    int i;
    if((fp=fopen("info2020.txt","r")) == NULL)
    {
        printf("info2020がありません\n");
        exit(1);
    }
    
    for(i=0;fscanf(fp,"%s%d%d%d%d%d%d", &name[i], &one[i].h, &one[i].m, &one[i].s, &two[i].h, &two[i].m, &two[i].s)!=EOF; i++){};
    fclose(fp);

    printf("test2.0\n");
    printf("test%1.0d\n",&name);
}
