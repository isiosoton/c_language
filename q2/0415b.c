/* k0737.c */
#include<stdio.h>
#define L 10
#define RF "/home/hokut/q2/0415b.txt"
#define OUTFORM "%-10s%3d\n"

struct DATA
{
    char name[L];
    int p;
};

int main(void)
{
    struct DATA r;
    FILE *fp;

    if((fp=fopen(RF,"a")) == NULL)
      printf("FILE("RF") OPEN ERROR\n");
    else{
      while(printf("\n氏名="),scanf("%s",r.name) != EOF){
        printf("得点=");
        scanf("%d",&r.p);
        fprintf(fp,OUTFORM,r.name,r.p);
      }
    }

    fclose(fp);
    return 0;
}
