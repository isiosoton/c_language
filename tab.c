#include <stdio.h>
#define MAX 500000
int main(void){
    int i;
    float a[MAX] = {0};
    printf("%d個のタブ区切りまで入力可能:",MAX);
    for(i=0; scanf("%d",a[i])!=EOF;i++);
    for(i=0;printf("%d",a[i])!=EOF;i++);
}