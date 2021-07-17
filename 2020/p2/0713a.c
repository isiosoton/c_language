#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    char a[11],b[2],c ='y';
    
    printf("表示OK？");
    for(i=0;;i>0);
    {
        printf("10文字以下のパスワードを設定してください：");
        scanf("%s",&a);
        printf("\nパスワードは%sで良いですか？\n良い場合はy\n悪い場合はnを入力してください：",a);
        scanf("%s",&b);
        if (strcmp(b, a) == 0)
        {
            printf("\nパスワードを設定しました\n");
            i = 1;
        } else {
            printf("\n最初からもう一度やり直してください\n");
        }
    }
    printf("終了しました。");

    return 0;

}
