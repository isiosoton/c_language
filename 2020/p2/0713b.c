#include <stdio.h>

int main(void)
{
    char a[100],b[100];

    printf("文字を入力してください：");
    scanf("%s",&a);
    printf("\n入力した文字は「%s」です\n",a);

    return 0;
}