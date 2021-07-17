#include<stdio.h>

void file(void);

void loop(void);


int main(void)
{
    file();

    loop();

}


void file(void)
{
    int i;
    FILE *fp1, *fp2, *fp3;
    if((fp1 = fopen("members.txt","r")) == NULL)
    {
        printf("menbers.txtがありません\n");
        exit(1);
    }
    for(i=0;fscanf(fp1,"%d%d", &data[i][0], &data[i][1])!=EOF && i<100; i++);
    if((fp2 = fopen("monsters.txt","r")) == NULL)
    {
        printf("monsters.txtがありません\n");
        exit(1);
    }
    for(i=0;fscanf(fp2,"%d%d", &data[i][0], &data[i][1])!=EOF && i<100; i++);
    if((fp3 = fopen("levelup.txt","r")) == NULL)
    {
        printf("levelup.txtがありません\n");
        exit(1);
    }
    for(i=0;fscanf(fp3,"%d%d", &data[i][0], &data[i][1])!=EOF && i<100; i++);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void loop(void)
{
    int menu,f=1;

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