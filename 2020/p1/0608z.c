#include <stdio.h>
int main(void)
{
    int     i;
    char    moji;

    printf("\n文字型\n");
    moji = 'A';
    printf("moji:%%c->%c\n", moji);
    printf("moji:%%d->%d\n", moji);

    moji = 'B';
    printf("moji:%%c->%c\n", moji);
    printf("moji:%%d->%d\n", moji);

    printf("\nfor文\n");
    for(i=10; i>=0; i--)
    {
        printf("%02d\n", i);
    }
    printf("%02d\n", i);
    
    return 0;
}
