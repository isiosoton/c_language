#include<stdio.h>

int main(void)
{
    FILE *fp1, *fp2, *fp3;
    int a, b, c;
    fp1 = fopen("members.txt","r");
    fp2 = fopen("monsters.txt","r");
    fp3 = fopen("levelup.txt","r");
    
    printf("読み込めました");
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}