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