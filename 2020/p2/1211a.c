#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct STATUS {
        int id;
        char name[50];
        int pw, hp, ex;
};

void file(struct STATUS amen[],struct STATUS mon[8][3][3], int levelup[],char *files[]);
void setup(struct STATUS amen[100], int *a);

int main(void)
{
    int *a;
    int menu,f=1;
    struct STATUS amen[100];
    struct STATUS mon[8][3][3];
    int levelup[101];
    char *files[6] = {"members.txt", "monsters.txt", "levelup.txt", "save-party.txt", "save-monsters.txt", "save.txt"};

    //printf("test1");
    file(amen, mon, levelup, files);
    setup(amen,a);

    for(;;)
    {
        if(f==1)
        {
            printf("%d階\n  0.階段(上の階に行く)\n  1.保存して終了\n",f);
            scanf("%d", &menu);
            switch(menu)
            {
                case 0: f += 1;
                        break;
                case 1: printf("保存しました\n");
                        break;
                default:printf("もう一度、入力しよう！\n");
                        break;
            }
        } else if (f==2 || f==3)
        {
            printf("%d階\n  0.階段(上の階に行く)\n  1.階段(下の階に行く)\n  2.保存して終了\n",f);
            scanf("%d", &menu);
            switch(menu)
            {
                case 0: f += 1;
                        break;
                case 1: f -= 1;
                        break;
                case 2: printf("保存しました\n");
                        break;
                default:printf("もう一度、入力しよう！\n");
                        break;
            }
        } else if(f==7) {
            printf("%d階\n  0.部屋\n  1.階段(下の階に行く)\n  2.保存して終了\n",f);
            scanf("%d", &menu);
            switch(menu)
            {
                case 0: printf("戦闘\n");
                        break;
                case 1: f -= 1;
                        break;
                case 2: printf("保存しました\n");
                        break;
                default:printf("もう一度、入力しよう！\n");
                        break;
            }
        } else {
            printf("%d階\n  0.部屋0\n  1.部屋1\n  2.部屋2\n  3.階段(上の階に行く)\n  4.階段(下の階に行く)\n  5.保存して終了\n",f);
            scanf("%d", &menu);
            switch(menu)
            {
                case 0: printf("戦闘\n");
                        break;
                case 1: printf("戦闘\n");
                        break;
                case 2: printf("戦闘\n");
                        break;
                case 3: f += 1;
                        break;
                case 4: f -= 1;
                        break;
                case 5: printf("保存しました\n");
                        break;
                default:printf("もう一度、入力しよう！\n");
                        break;
            }
        }
        printf("==============================\n");
    }
}

void file(struct STATUS amen[],struct STATUS mon[8][3][3], int levelup[],char *files[])
{
    FILE *fp1, *fp2, *fp3;
    int i, id, fn, rn, mn, *a;
    if((fp1=fopen(files[0],"r")) == NULL)
    {
        printf("%sがありません\n",files[0]);
        exit(1);
    }
    for(*a=0;fscanf(fp1,"%d%s%d%d", &amen[*a].id, amen[*a].name[50], &amen[*a].pw, &amen[*a].hp)!=EOF; *a++);

    if((fp2=fopen(files[1],"r")) == NULL)
    {
        printf("%sがありません\n",files[1]);
        exit(1);
    }
    for(i=0;fscanf(fp2,"%d", &id)!=EOF; i++)
    {
        fscanf(fp2,"%d%d%d", &fn, &rn, &mn);
        fscanf(fp2,"%s%d%d%d", mon[fn][rn][mn].name[50], &mon[fn][rn][mn].pw, &mon[fn][rn][mn].hp, &mon[fn][rn][mn].ex);
        mon[fn][rn][mn].id = id;
    };

    if((fp3=fopen(files[2],"r")) == NULL)
    {
        printf("%sがありません\n",files[2]);
        exit(1);
    }
    for(i=0;fscanf(fp3,"%d", &levelup[i])!=EOF; i++);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void setup(struct STATUS amen[100],int *a)
{
    struct STATUS party[3];
    int members[100],i;
    printf("勇者の名前を入力してください：");
    scanf("%s\n",&party[1].name);
    printf("勇者のステータス\nパワー：%d 体力：%d",amen[0].pw,amen[0].hp);
    party[0] = amen[0];
    for(i=1;i<*a;i++)
    {
        printf("パーティ―選択\n番号：%d 名前：%s パワー：%d 体力：%d\n",amen[i].id,amen[i].name,amen[i].pw,amen[i].hp);
    }
    i = 0;
    for(int b=1;b<3;b++){
        printf("選択するキャラクター1の番号を入力してください：");
        scanf("%d",&i);
        printf("あなたは%sを選択しました\n",amen[i].name);
        strncpy(party[b+1].name,amen[i].name,1000);
        party[b+1] = amen[i];
        i = 0;        
    }
}