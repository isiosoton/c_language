#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ransu(int a,int b);

int main(void)
{
    int c=2;
    for(c=0;c!=1;)
    {
        int a,b,d,f,g,h;
        srand(time(NULL));
        /**
        printf("引数Aを入力してください：");
        scanf("%d",&a);
        printf("\n引数Bを入力してください：");
        scanf("%d",&b);
        */
        a = 10;
        b = 1;
        d = a - b;
        /**
        if(d<0)
        {
            d *= -1;
        }
        */
        d += 1; 
        int e[d];
        for(g=0;g<d+b;g++)
        {
            e[g] = 0;
            printf("%2d:%d\n",g,e[g]);
        }
        f = 10000;
        for(g=0;g<f;g++)
        {
            h = ransu(a,b);
            e[h] += 1;
            printf("%5d:%2d\n",g,h);
        }
        //printf("てくてく\n");
        h = 0;
        for(g=b;g<d+b;g++)
        {
            printf("%2d:%4d\n",g,e[g]);
            h += e[g];
        }
        //printf("計:%5d\n",h);
        printf("終了する場合は1を、終了しない場合は1以外を入力：");
        scanf("%d",&c);
    }
    printf("終了しました");

    return 0;
}

int ransu(int a,int b)
{
    int c,d;
    /**
    printf("引数Aを入力してください：");
    scanf("%d",&a);
    printf("\n引数Bを入力してください：");
    scanf("%d",&b);
    */
    c = a - b + 1;
    /**
    if(c<0)
    {
        c *= -1;
    }
    */
    d = b + rand()%c;
    //printf("\n結果は%dです。",d);
    
    return d;
}