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
void setup(struct STATUS amen[], struct STATUS party[3], int *py, int *mn);
int zero(int z);
int rans(int com);
void scala(int *f, int *menu, int *bat, int maxfloar, int room[8][3]);

int main(void)
{
    struct STATUS party[3]={}, cocp[3]={}, amen[100]={}, mon[8][3][3];
    int menu, f = 1, levelup[101], py=0, bat=0, mn=3, com=3, e, maxfloar = 7, room[8][3];
    char *files[6] = {"members.txt", "monsters.txt", "levelup.txt", "save-party.txt", "save-monsters.txt", "save.txt"};

    srand(time(NULL));
    //printf("test1-0\n");
    file(amen, mon, levelup, files, &py);
    //printf("test2-0\n");
    //printf("test %d\n",py);
    setup(amen,party,&py, &mn);

    f = 1;
    for(;;)
    {
        bat = 0;
        scala(&f, &menu, &bat, maxfloar, room);
        if(bat == 1)
        {
                int ran,d=0,sw1,sw2=0,sw3,sum,lev;
                for(e=0;e<com;e++)
                {
                        cocp[e] = party[e];
                }
                sw3 = 0;
                for(int a=0;a<com;)
                {
                        printf("==============================\n");
                        printf("パーティーのHP\n");
                        for(sw1=0;sw1<mn;sw1++)
                        {
                                printf("キャラクター%d\t%s\t%d\n",sw1,party[sw1].name,party[sw1].hp);
                                //printf("合計HP\t%d\n",hp0);
                        }
                        printf("==============================\n");
                        switch(sw2)
                        {
                                case 0: //srand(time(NULL));
                                        for(sw1=0;;sw1++)
                                        {
                                                sum += mon[f][menu][sw1].hp;
                                                if(sw1>com && sum <= 0)
                                                {
                                                        printf("この部屋のモンスターは既に倒されている\n");
                                                        sw3=1;
                                                        break;
                                                } else {
                                                        ran = rand() % com;
                                                }
                                                if(mon[f][menu][ran].hp>0)
                                                {
                                                        //printf("test%d\n",mon[f][menu][ran].hp);
                                                        break;
                                                }
                                        }
                                        //printf("test %d\n",ran);
                                        if(sw3!=1)
                                        {
                                                printf("%sが現れた。行動を選択してください。\n1.攻撃する。\n2.部屋を出る。\n",mon[f][menu][ran].name);
                                        }
                                        break;
                                case 1: printf("%sにもう一度攻撃しますか。\n1.攻撃する。\n2.部屋を出る。\n",mon[f][menu][ran].name);
                                        break;
                        }
                        for(;sw3==0;)
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
                                int pw=0,hp0=0;
                                for(sw1=0;sw1<mn;sw1++)
                                {
                                        if(party[sw1].hp!=0)
                                        {
                                                mon[f][menu][ran].hp -= party[sw1].pw;
                                                pw += party[sw1].pw;
                                        }
                                }
                                mon[f][menu][ran].hp = zero(mon[f][menu][ran].hp);
                                for(;;)
                                {
                                        e = rans(com);
                                        //printf("test3-%d\n",e);
                                        if(party[e].hp!=0)
                                        {
                                                //printf("test%d\n",party[e].hp);
                                                break;
                                        }
                                }
                                party[e].hp -= mon[f][menu][ran].pw;
                                printf("パーティ―は%sに%dの攻撃を与えた\n",mon[f][menu][ran].name,pw);
                                printf("%sは%sに%dの攻撃を受けた\n",party[e].name,mon[f][menu][ran].name,mon[f][menu][ran].pw);
                                if(party[e].hp<=0)
                                {
                                        printf("%sはHPが0になり戦えなくなった。\n",party[e].name);
                                }
                                printf("==============================\n");
                                hp0 = 0;
                                for(sw1=0;sw1<mn;sw1++)
                                {
                                        party[sw1].hp = zero(party[sw1].hp);
                                        hp0 += party[sw1].hp;
                                        //printf("test%d\n",hp0);
                                }
                                if(hp0 <= 0) {
                                        printf("パーティは全滅しました\nゲームオーバー\n");
                                        exit(0);
                                } else if(mon[f][menu][ran].hp<=0) {
                                        printf("パーティ－は%sを倒した！\n",mon[f][menu][ran].name);
                                        for(sw1=0;sw1<com;sw1++)
                                        {
                                                cocp[sw1].ex += mon[f][menu][ran].ex;
                                                //printf("test%d\n",cocp[sw1].ex);
                                                //party[sw1] = cocp[sw1];
                                        }
                                        //printf("test%d-%d\n",0,cocp[0].ex);
                                        //printf("tese%d-%d\n",lev,levelup[lev]);
                                        if(cocp[0].ex >= levelup[lev++])
                                        {
                                                //lev++;
                                                printf("パーティのレベルが%dになった！\n",lev);
                                                //printf("キャラのHP,APがそれぞれ%d上がった！\n",mon[f][menu][ran].ex/3);
                                                printf("キャラのHPが%d上がった！\n",mon[f][menu][ran].ex/com);
                                                printf("キャラのAPが%d上がった！\n",lev);
                                                for(sw1=0;sw1<com;sw1++)
                                                {
                                                        //cocp[sw1].hp += mon[f][menu][ran].ex;
                                                        //cocp[sw1].pw += mon[f][menu][ran].pw;
                                                        cocp[sw1].hp += mon[f][menu][ran].ex/3;
                                                        //cocp[sw1].pw += mon[f][menu][ran].pw;
                                                        cocp[sw1].pw += lev;
                                                        party[sw1] = cocp[sw1];
                                                }
                                        } else {
                                                lev--;
                                        }
                                        sw2 = 0;
                                        a++;
                                } else {
                                printf("モンスターのHP\n%s\t%d\n",mon[f][menu][ran].name,mon[f][menu][ran].hp);
                                sw2 = 1;
                                }
                                sum = 0;
                                for(sw1=0;sw1<com;sw1++)
                                {
                                        sum += mon[f][menu][sw1].hp;
                                }
                                if(sum==0)
                                {
                                        printf("この部屋のモンスターはやっつけた！\n");
                                        room[f][menu]=1;
                                        if(f==maxfloar)
                                        {
                                                printf("理工学部棟を奪還した\n");
                                                sleep(10);
                                                printf("創価大学の戦いはまだ続く…\n");
                                                exit(0);
                                        }
                                        sw3 = 1;
                                        break;
                                }
                        } else {            
                                break;
                        }
                }
                for(e=0;e<com;e++)
                {
                        party[e] = cocp[e];
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
    int i, id, fn, rn, mna;
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
            case 1: while(fscanf(fp1,"%d%d%d%d", &id, &fn, &rn, &mna)!=EOF)
                    {
                        mon[fn][rn][mna].id = id;
                        fscanf(fp1,"%s%d%d%d", mon[fn][rn][mna].name, &mon[fn][rn][mna].pw, &mon[fn][rn][mna].hp, &mon[fn][rn][mna].ex);
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

void setup(struct STATUS amen[100],struct STATUS party[3],int *py, int *mn)
{
    //printf("test2-1\n");
    int pt=100;
    int members[100],i,d[pt],sw=0;
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
    for(int b=1;b<*mn;){
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
    for(sw=0;sw<*mn;sw++)
    {
        printf("キャラクター%d\t%s\n",sw,party[sw].name);
    }
    printf("==============================\n");
    sleep(2);
}

int zero(int z)
{
        if(z<=0)
        {
                z = 0;
        }
        return z;
}

int rans(int com)
{
        int comr=0,sum=0,fra[50];
        for(comr=0;comr<com;comr++)
        {
                fra[comr] = 100/(2+comr);
                //printf("testa-%d\n",fra[comr]);
                sum += fra[comr];
                //printf("testb-%d\n",sum);
        }
        //printf("test1-%d\n",sum);
        sum = rand()%sum;
        //printf("test2-%d\n",sum);
        for(comr=0;comr<com;comr++)
        {
                sum -= fra[comr];
                if(sum<=0)
                {
                        break;
                }
        }
        
        return comr;
}

void scala(int *f, int *menu, int *bat, int maxfloar, int room[8][3])
{
        int on[5] = {0,0,0,0,0};
        printf("%d階\n",*f);
        if((4<=*f && *f<=maxfloar) && room[*f][0]==0)
        {
                printf("0.%d00号室に入る\n",*f);
                on[0] = 1;
        }
        if((4<=*f && *f<=(maxfloar-1)) && room[*f][1]==0)
        {
                printf("1.%d01号室に入る\n",*f);
                on[1] = 1;
        }
        if((4<=*f && *f<=(maxfloar-1)) && room[*f][2]==0)
        {
                printf("2.%d02号室に入る\n",*f);
                on[2] = 1;
        }
        if(1<*f)
        {
                printf("3.階段(下の階に行く)\n");
                on[3] = 1;
        }
        if(*f<maxfloar)
        {
                printf("4.階段(上の階に行く)\n");
                on[4] = 1;
        }
        printf("5.保存して終了\n");
        scanf("%d",menu);
        if(*menu==0 && on[0]==1)
        {
                printf("戦闘\n");
                *bat = 1;
        } else if (*menu==1 && on[1]==1) {
                printf("戦闘\n");
                *bat = 1;
        } else if (*menu==2 && on[2]==1) {
                printf("戦闘\n",*f);
                *bat = 1;
        } else if (*menu==3 && on[3]==1) {
                *f -= 1;
        } else if (*menu==4 && on[4]==1) {
                *f += 1;
        } else if (*menu==5) {
                printf("保存しました\n");
        } else {
                printf("もう一度、入力してください\n");
        }
}