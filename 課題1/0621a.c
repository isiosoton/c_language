#include <stdio.h>
#include "bmp.h"
#define  MAX 256

int main(void){
    unsigned char input_image[MAX][MAX] = {0};
    unsigned char output_image[MAX][MAX] = {0};
    char filename[50];
    int mask[3][3] = {{-1,-1,-1},{-1,8,-1},{-1,-1,-1}};
    int i,j;
    int x,y,test = 0;
    long temp = 0;

    printf("filename:");
    scanf("%s",filename);
    LoadBMP(filename,input_image[0],MAX,MAX);
    for(y=0;y<MAX-1;y++){
        for(x=0;x<MAX-1;x++){
            test += input_image[x][y];
            if(x==0||y==0||x==MAX-1||y==MAX-1){
                output_image[x][y] = 0;
            } else {
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                            temp += input_image[x+i-1][y+j-1] * mask[i][j];
                    }
                }
                if(temp <= 0) {
                    temp = 0;
                } else if(MAX-1 <= temp) {
                    temp = MAX - 1;
                }
                //printf("input:%3d,temp:%3ld\n",(int)input_image[x][y],temp);
                output_image[x][y] = temp;
                temp = 0;
            }
            //ここを考える
        }
    }
    if(test==0){
        printf("-1");
        return -1;
    } else {
        SaveBMP("result.bmp",output_image[0],MAX,MAX);
        return 0;
    }
}