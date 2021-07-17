/*
 * Image I/O Program
 *
 * Prodeuced by H. Imamura
 *
 */ 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define X_SIZE   1300 // 最大入力画像サイズ
#define Y_SIZE   1600
#define F_NUM       2 // 入出力ファイル数

int             x_size, y_size, kaityou;
double          d, sum;
unsigned char   image_in1[X_SIZE][Y_SIZE];       // Input1画像配列
unsigned char   image_in2[X_SIZE][Y_SIZE];       // input2画像配列

char *read_token(fp)
FILE	*fp;
{
    char	*s;
    static char	str[BUFSIZ];

    while(1){
	while(isspace(*str = getc(fp)));
	if('#' != *str) break;
	while('\n' != getc(fp));
    }
    for(s=str+1; !isspace(*s = getc(fp)); s++);
    *s = (char)NULL;
    return str;
}

int load_pnm_header(width, height, depth, fp)
int	*width, *height, *depth;
FILE	*fp;
{
    char	*str;

    str = read_token(fp);
    if(!strcmp("P4", str)){
	*depth = 1;
    } else if(!strcmp("P2", str)){
	*depth = 8;
    } else if(!strcmp("P5", str)){
	*depth = 8;
    } else if(!strcmp("P6", str)){
	*depth = 24;
    } else{
	fprintf(stderr, "%s is wrong magic number!\n", str);
	return 0;
    }
    *width = atoi(read_token(fp)); *height = atoi(read_token(fp));
    if(1 != *depth) (void)read_token(fp);
    return 1;
}

void read_file_open(char *file_name, FILE *fp[], char kaku[8], int count)
{ 
  char file_tmp[100];
  strcpy(file_tmp,file_name);
  strcat(file_tmp,kaku);
  if( (fp[count]=fopen(file_tmp,"rb"))==NULL )
  {
    printf("Can't open file\n");
    exit(1);
  }
}
void write_file_open(char *file_name, FILE *fp[], char kaku[8], int count)
{
  char file_tmp[100];
  strcpy(file_tmp,file_name);
  strcat(file_tmp,kaku);
  if( (fp[count]=fopen(file_tmp,"wb"))==NULL )
  {
    printf("Can't open file\n");
    exit(1);
  }
}

void write_pgm_file( FILE *fp[], int count){
  fprintf(fp[count], "P5\n");
  fprintf(fp[count], "%d %d\n", x_size, y_size);
  fprintf(fp[count], "255\n");
}

/*******************************メイン関数**********************************/

main(int argc, char *argv[])
{
  FILE    *fp[F_NUM];
  int     j, k;
  float mse, sum, psnr;

  if(argc!=3){                                      // エラーチェック
    printf("Parameter error!\n");
    exit(1);
  }

  read_file_open (argv[1], fp, ".pgm",          0);   // input1画像ファイル
  read_file_open (argv[2], fp, ".pgm",          1);   // input2画像ファイル

  load_pnm_header( &x_size, &y_size, &kaityou, fp[0]);

  for(k=0;k<y_size;k++){             // 配列に入力画像データを代入
    for(j=0;j<x_size;j++){
      image_in1[j][k] = fgetc(fp[0]);
    }
  }

 load_pnm_header( &x_size, &y_size, &kaityou, fp[1]);

  for(k=0;k<y_size;k++){             // 配列に入力画像データを代入
    for(j=0;j<x_size;j++){
      image_in2[j][k] = fgetc(fp[1]);
    }
  }


  for(k=0;k<y_size;k++){                      // Main Process
    for(j=0;j<x_size;j++){
      //sum += abs(image_in1[j][k]-image_in2[j][k]);
      sum += pow(abs(image_in1[j][k]-image_in2[j][k]),2);
	    //printf("%d \n",abs(image_in1[j][k]-image_in2[j][k]));
    }
  }
  //printf("%f\n",sum);
  //mse = (1 / ((float)x_size * (float)y_size)) * pow(sum,2);
  mse = (1 / ((float)x_size * (float)y_size)) * sum;
  //printf("%f\n",mse);
  psnr = 10 * log10((pow(255,2) / mse));
  printf("%f\n",psnr);

  for(j=0; j<F_NUM; j++){
      fclose(fp[j]);
  }
}

//mandrill
//girl
//peppers
