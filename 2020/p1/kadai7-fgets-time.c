#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    time_t  start_time;
	char	data[1000]="The movie is based on a smash-hit manga set in a Japan of about 100 years ago.";
	char    in[1000];
    int     n=0, i, j, len, inlen;

    printf("Text :%s\n\n", &data[n]);
    len = strlen(data);

    start_time = time(NULL);
    while(n<len)
    {
        printf("Input:");
        fgets(in,100,stdin);
        inlen = strlen(in) - 1; //改行を一文字とする
    }
    printf("Time：%.0f秒\n", difftime(time(NULL), start_time));

	return 0;
}
