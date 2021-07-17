#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

struct STATUS {
	int	id;
	char	name[50];
	int	pw, hp, ex;
};

void file(struct STATUS amen[],struct STATUS mon[][3][3], int levelup[],char *files[], int *py);
void setup(struct STATUS amen[], struct STATUS party[3], int *py);

int main(void)
{
    struct STATUS party[3]={}, amen[100]={}, mon[8][3][3];
    int menu, f = 1, levelup[101], py = 0, sw=0;
    char *files[6] = {"members.txt", "monsters.txt", "levelup.txt", "save-party.txt", "save-monsters.txt", "save.txt"};

    srand(time(NULL));
    //printf("test1-0\n");
    file(amen, mon, levelup, files, &py);
    //printf("test2-0\n");
    //printf("test %d\n",py);
    setup(amen,party,&py);

    f = 1;
    for(;;)
    {
        sw = 0;
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
                        sw = 1;
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
                        sw = 1;
                        break;
                case 1: printf("戦闘\n");
                        sw = 1;
                        break;
                case 2: printf("戦闘\n");
                        sw = 1;
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
        if(sw == 1)
        {
                int b=3,c,d=0;
                for(int a=0;a<b;a++)
                {
                        //srand(time(NULL));
                        c = rand() % b;
                        //printf("test %d\n",c);
                        printf("==============================\n");
                        printf("%sが現れた。行動を選択してください。\n1.攻撃する。\n2.部屋を出る。\n",mon[f][menu][c].name);
                        for(;;)
                        {
                                scanf("%d",&d);
                                if(d == 1 || d == 2)
                                {
                                        break;
                                } else {
                                        printf("対象外の番号です。再度選択してください。\n");
                                        continue;
                                }
                        }
                        if(d==1)
                        {
                                
                        } else {
                                
                        }
                }
        }
        printf("==============================\n");
        //sleep(2);
    }
    return 0;
}

void file(struct STATUS amen[],struct STATUS mon[][3][3], int levelup[], char *files[], int *py)
{
    FILE *fp1;
    int i, id, fn, rn, mn;
    for(int fpn=0;fpn<3;fpn++){
        if((fp1=fopen(files[fpn],"r")) == NULL)
        {
            printf("%sがありません\n",files[fpn]);
            exit(1);
        }
        switch(fpn)
        {
            case 0: for(i=0;fscanf(fp1,"%d%s%d%d", &amen[i].id, amen[i].name, &amen[i].pw, &amen[i].hp)!=EOF; i++);
                    //printf("test1-1\n");
                    *py = i;
                    //for(*py=0;*py<i;*py++);
                    //printf("test1-2\n");
                    break;
            case 1: while(fscanf(fp1,"%d%d%d%d", &id, &fn, &rn, &mn)!=EOF)
                    {
                        mon[fn][rn][mn].id = id;
                        fscanf(fp1,"%s%d%d%d", mon[fn][rn][mn].name, &mon[fn][rn][mn].pw, &mon[fn][rn][mn].hp, &mon[fn][rn][mn].ex);
                    }
                    break;
            case 2: for(i=0;fscanf(fp1,"%d", &levelup[i])!=EOF; i++);
                    break;
            default:printf("範囲外のファイルです");
                    break;
        }
        fclose(fp1);
    }
}

void setup(struct STATUS amen[100],struct STATUS party[3],int *py)
{
    //printf("test2-1\n");
    int pt=100;
    int members[100],i,d[pt],sw=0,mn=3;
    party[0] = amen[0];
    printf("勇者の名前を入力してください：");
    scanf("%s",&party[0].name);
    printf("勇者のステータス\nパワー：%d 体力：%d\n",amen[0].pw,amen[0].hp);
    printf("==============================\n");
    //party[0] = amen[0];
    //*py = 6;
    printf("パーティ選択\n");
    for(i=1;i<*py;i++)
    {
        printf("番号：%2d 名前：%s\t パワー：%2d\t 体力：%2d\n",amen[i].id,amen[i].name,amen[i].pw,amen[i].hp);
    }
    for(i=0;i<pt;i++)
    {
            d[i] = 0;
    }
    i = 0;
    printf("==============================\n");
    for(int b=1;b<mn;){
        printf("選択するキャラクター%dの番号を入力してください：",b);
        scanf("%d",&i);
        d[b] = i;
        for(int c=0;c<b;c++)
        {
                if(i>*py-1 || 0>=i)
                {
                        printf("対象外のキャラクターです\n再度選びなおしてください\n");
                        sw = 1;
                        break;
                } else if(d[c]==i){
                        printf("一度選択したキャラクターです\n再度選びなおしてください\n");
                        sw = 1;
                        break;
                } else {
                        sw = 0;
                }
        }
        //printf("test %d\n",sw);
        if(sw==1)
        {
                //printf("test2-2\n");
                continue;
        }
        sw = 0;
        printf("あなたは%sを選択しました\n",amen[i].name);
        //strncpy(party[b].name,amen[i].name,100);
        party[b] = amen[i];
        i = 0;
        b++;        
    }
    printf("==============================\n");
    printf("パーティ編成\n");
    for(sw=0;sw<mn;sw++)
    {
        printf("キャラクター%d\t%s\n",sw,party[sw].name);
    }
    printf("==============================\n");
    sleep(2);
}