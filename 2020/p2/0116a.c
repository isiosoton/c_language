#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"time.h"
#include"unistd.h"
#include"0116a.h"

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
                                printf("キャラクター%d\t%-11s\t%d\n",sw1,party[sw1].name,party[sw1].hp);
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