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
#include<ctype.h>

#define X_SIZE   256 // $B:GBgF~NO2hA|%5%$%:(J
#define Y_SIZE   256 //画像サイズ
#define F_NUM       2 // $BF~=PNO%U%!%$%k?t(J

int             x_size, y_size, kaityou;
double          d, sum;
unsigned char   image_in[X_SIZE][Y_SIZE];        // Input$B2hA|G[Ns(J
unsigned char   image_out[X_SIZE][Y_SIZE];       // output$B2hA|G[Ns(J

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
    *s = (int)NULL; //intに変更？
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

/*******************************$B%a%$%s4X?t(J**********************************/

main(int argc, char *argv[])
{
  FILE    *fp[F_NUM];
  int     j, k ,l;

  if(argc!=2){                                      // $B%(%i!<%A%'%C%/(J
    printf("Parameter error!\n");
    exit(1);
  }

  read_file_open (argv[1], fp, ".pgm",          0);   // input$B2hA|%U%!%$%k(J 拡張子を打たなくて良いようになってる。
  write_file_open(argv[1], fp, "_output.pgm",    1);   // output$B2hA|%U%!%$%k(J 出力の拡張子を自動で打ち込む、上書きしなくてよいように。

  load_pnm_header( &x_size, &y_size, &kaityou, fp[0]); //y_size 画像の横サイズ　縦サイズ

  for(k=0;k<y_size;k++){             // $BG[Ns$KF~NO2hA|%G!<%?$rBeF~(J
    for(j=0;j<x_size;j++){
      image_in[j][k]  = fgetc(fp[0]); //読み込んだ画像ファイルから1文字ずつ輝度値を下げるようにする
    }
  }
  
  write_pgm_file(fp, 1);

  int x,y,u,v;
  int m = 30; //輝度値の上下幅
  double Cu,Cv;
  int N = 8;
  double c[X_SIZE][Y_SIZE];

  for(x=0;x<x_size;x+=8)
  {
    for(y=0;y<y_size;y+=8)
    {
      for(u=0;u<N;u++)
      {
        for(v=0;v<N;v++)
        {
          //Cu,Cvの場合分け
          if(u==0)
          {
            Cu = 1/sqrt(2);
          } else {
            Cu = 1;
          }
          if(v==0)
          {
            Cv = 1/sqrt(2);
          } else {
            Cv = 1;
          }
          //式のΣ計算
          sum = 0;
          for(j=0;j<N;j++)
          {
            for(k=0;k<N;k++)
            {
              sum += image_in[x+j][y+k] * cos((2*j+1)*u*M_PI/16.0) * cos((2*k+1)*v*M_PI/16.0);
            }
          }
          //式全体を計算し、c[x+u][y+v]に格納
          c[x+u][y+v] = 0.25 * Cu * Cv * sum;
        }
      }
    }
  }

  int BL = 1;

  for(x=0;x<x_size;x+=8)
  {
    for(y=0;y<y_size;y+=8)
    {
      for(j=0;j<N;j++)
      {
        for(k=0;k<N;k++)
        {
          //式のΣ計算
          sum = 0;
          for(u=0;u<BL;u++)
          {
            for(v=0;v<BL;v++)
            {
              //Σ式の計算の中でCu,Cvの場合分け
              if(u==0)
              {
                Cu = 1/sqrt(2);
              } else {
                Cu = 1;
              }
              if(v==0)
              {
                Cv = 1/sqrt(2);
              } else {
                Cv = 1;
              }

              sum += Cu*Cv*c[x+u][y+v] * cos((2*j+1)*u*M_PI/16.0) * cos((2*k+1)*v*M_PI/16.0);
            }
          }

          //式全体を計算し、image_out[x+j][y+k]に格納
          image_out[x+j][y+k] = 0.25*sum;
        }
      }
    }
  }
  /*
  for(k=0;k<y_size;k++){                      // Main Process
    for(j=0;j<x_size;j++){
      l = image_in[j][k] + m;
      if(l>255)
      {
        image_out[j][k] = 255;
      } else if(l<0) {
        image_out[j][k] = 0;
      } else {
        image_out[j][k] = image_in[j][k] + m; //輝度値の値を上下させる
      }
    }
  }*/

  for(k=0;k<y_size;k++){                      
   for(j=0;j<x_size;j++){
     fputc(image_out[j][k]  ,fp[1]); //配列の中身を吐き出すという指示
   }
  }

  for(j=0; j<F_NUM; j++){
      fclose(fp[j]);
  }
  return 0;
}