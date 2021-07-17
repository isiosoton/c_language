#include <stdio.h>

int main(void)
{
	int	a, n=0;
    while ( scanf("%d", &a ) != EOF )
    {
        printf("%d\n", a);
        n++;
    }
    printf("データ数：%d\n", n);

	return 0;
}
