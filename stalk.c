#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i;
    srand(time(NULL));
    i = rand()%6;
    printf("さいころの目:%d\n",i+1);

    switch (i) {
        case 0:printf("最近のビックニュースは？\n");
                break;
        case 1:printf("好きなタレントは？\n");
                break; 
        case 2:printf("もしも自分を動物に例えるなら？\n");
                break;
        case 3:printf("無人島に1つ物を持っていけるなら、何を持っていきますか？\n");
                break;
        case 4:printf("今一番何が欲しいですか？\n");
                break;
        case 5:printf("明日地球が滅びるとしたら何がしたい？\n");
                break;
    }
    return 0;
}