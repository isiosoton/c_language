#include <stdio.h>
#include <string.h> //strlen,strncmp(文字列の比較)
#include <time.h> //time,difftime
#include <unistd.h> //sleep

int main(void)
{
    time_t  start_time;
	char	data[1000]="The movie is based on a smash-hit manga set in a Japan of about 100 years ago.";
	char    in[1000];
    int     n=0, i, j, len, inlen;

    printf("Text :%s\n\n", &data[n]);
    len = strlen(data); //文字列の長さを求める

    start_time = time(NULL);
    while(n<len)
    {
        printf("Input:");
        fgets(in,1000,stdin);
        inlen = strlen(in) - 1; //改行を一文字とする
        if(strncmp(&data[n], in, inlen) == 0){
            n += inlen;
            for(;inlen>n;n++){}
        }
        printf("Text :%s\n",&data[n]); 
    }
    printf("Time：%.0f秒\n", difftime(time(NULL), start_time));

	return 0;
}

/*
#include<stdio.h>

int main(void)
{
    char type[17][10] = {}
    printf("text:")

    
}
*/