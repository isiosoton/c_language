#include<stdio.h>
void file(void);

int main(void)
{
    file();
}

void file(void)
{
    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("members.txt","r");
    fp2 = fopen("monsters.txt","r");
    fp3 = fopen("levelup.txt","r");
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}