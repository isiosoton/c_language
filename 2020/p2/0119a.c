#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"time.h"
#include"unistd.h"
#include"0119a.h"

int main(void)
{
    struct STATUS party[3]={}, cocp[3]={}, amen[100]={}, mon[8][3][3];
    int menu, f = 1, levelup[101], py=0, bat=0, mn=3, com=3, e, maxfloar = 7, room[8][3],idm[100][3], orh[8][3][3];
    int fn, rn, mna, ia, ib;
    char *files[6] = {"members.txt", "monsters.txt", "levelup.txt", "save-party.txt", "save-monsters.txt", "save.txt"};

    srand(time(NULL));
    //printf("test1-0\n");
    file(amen, mon, levelup, files, &py, idm, party, orh);
    //printf("test2-0\n");
    //printf("test %d\n",py);
    if(party[1].id==0)
    {
        setup(amen,party,&py, &mn);
    } else {
        //i = 0;
        for(ia = 0;idm[ia][0]!=0; ia++)
        {
                fn  = idm[ia][0];
                rn  = idm[ia][1];
                mna = idm[ia][2];
                ib += mon[fn][rn][mna].hp;
                //printf("test1-%d\n", ib);
                if(idm[ia][0]!=idm[ia-1][0] || idm[ia][1]!=idm[ia-1][1])
                {
                        if(ib == 0)
                        {
                                room[fn][rn] = 1;
                                //printf("room %d-%d-%d test1-%d\n", idm[ia][0],idm[ia][1],idm[ia][2], ib);
                        } else {
                                ib = 0;
                                //printf("room %d-%d-%d test2-%d\n", idm[ia][0],idm[ia][1],idm[ia][2], ib);
                                room[fn][rn] = 0;
                        }
                } else {
                        //printf("room %d-%d-%d test3-%d\n", idm[ia][0],idm[ia][1],idm[ia][2], ib);
                }
        }
    }

    f = 1;
    for(;;)
    {
        bat = 0;
        scala(&f, &menu, &bat, maxfloar, room);
        if(bat == 1)
        {
                int ran,d=0,sw1,sw2=0,sw3,sum,lev,pan;
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
                                                        room[f][menu] = 1;
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
                                //printf("test-1\n");
                                for(sw1=0;sw1<mn;sw1++)
                                {
                                        if(party[sw1].hp!=0)
                                        {
                                                pan = (party[sw1].pw * party[sw1].hp) / cocp[sw1].hp;
                                                mon[f][menu][ran].hp -= pan;
                                                pw += pan;
                                        }
                                }
                                mon[f][menu][ran].hp = zero(mon[f][menu][ran].hp);
                                do{e = rans(com);}
                                while(party[e].hp==0);
                                //printf("test-%d\n",orh[f][menu][ran]);
                                pan = (mon[f][menu][ran].pw * mon[f][menu][ran].hp) / orh[f][menu][ran];
                                if(pan<=0)
                                {
                                        pan = 1;
                                }
                                party[e].hp -= pan;
                                printf("パーティ―は%sに%dの攻撃を与えた\n",mon[f][menu][ran].name,pw);
                                printf("%sは%sに%dの攻撃を受けた\n",party[e].name,mon[f][menu][ran].name,pan);
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
                                                int up = 1;
                                                printf("パーティのレベルが%dになった！\n",lev);
                                                //printf("キャラのHP,APがそれぞれ%d上がった！\n",mon[f][menu][ran].ex/3);
                                                printf("キャラのHPが%d上がった！\n",mon[f][menu][ran].ex/com);
                                                printf("キャラのAPが%d上がった！\n",up);
                                                for(sw1=0;sw1<com;sw1++)
                                                {
                                                        //cocp[sw1].hp += mon[f][menu][ran].ex;
                                                        //cocp[sw1].pw += mon[f][menu][ran].pw;
                                                        cocp[sw1].hp += mon[f][menu][ran].ex/3;
                                                        //cocp[sw1].pw += mon[f][menu][ran].pw;
                                                        cocp[sw1].pw += up;
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
                                                sleep(5);
                                                
                                                sleep(5);                                                
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
        } else if (bat == 2) {
                //printf("test-1\n");
                save(files, party, mon, idm, amen);
        } else if (bat == 3) {
                setup(amen, party, &py, &mn);                
        }
        printf("==============================\n");
        //sleep(2);
    }
    return 0;
}