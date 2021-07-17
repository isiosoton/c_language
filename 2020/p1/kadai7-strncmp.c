#include <stdio.h>
#include <string.h>

int main(void)
{
	char	str1[20]="abcdefg";
	char	str2[20]="cdeg";

    if(strncmp(str1, str2, 3)==0)
    {
        printf("比較された３文字は等しい\n");
    }
    else
    {
        printf("比較された３文字は異なる\n");
    }

    if(strncmp(&str1[0], &str2[0], 3)==0)
    {
        printf("比較された３文字は等しい\n");
    }
    else
    {
        printf("比較された３文字は異なる\n");
    }

    if(strncmp(&str1[2], &str2[0], 3)==0)
    {
        printf("比較された３文字は等しい\n");
    }
    else
    {
        printf("比較された３文字は異なる\n");
    }

	return 0;
}
