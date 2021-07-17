#ifndef BMPH
#define BMPH

#include <stdio.h>

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef unsigned char BYTE;

typedef struct BitmapFileHeader
{
  WORD	bfType;
  DWORD	bfSize;
  WORD	bfReserved1;
  WORD	bfReserved2;
  DWORD	bfOffBits;
  
} BITMAPFILEHEADER;

typedef struct BitmapInfoHeader
{
  DWORD	biSize;
  LONG	biWidth;
  LONG	biHeight;
  WORD	biPlanes;
  WORD	biBitCount;
  DWORD	biCompression;
  DWORD	biSizeImage;
  LONG	biXPelsPerMeter;
  LONG	biYPelsPerMeter;
  DWORD	biClrUsed;
  DWORD	biClrImportant;
} BITMAPINFOHEADER;

typedef struct RGBQuad
{
  BYTE	rgbBlue;
  BYTE	rgbGreen;
  BYTE	rgbRed;
  BYTE	rgbReserved;
} RGBQUAD;

typedef struct BitmapInfo
{
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD	   bmiColors[1];
} BITMAPINFO;


//ビットマップファイルからの画像データ取得をおこなう関数
//正しく取得できた場合，取得画像サイズを返す
int LoadBMP(char *filename,unsigned char *image,int x, int y)
{
  FILE *fp;		   //画像ファイルポインタ
  int read_size = 0;	   //画像読み込み成功サイズ
  BITMAPFILEHEADER bmfhead;//ビットマップファイルヘッダ
  BITMAPINFOHEADER bmihead;//ビットマップインフォヘッダ
  int i;		   //繰り返し制御に使用
  
  //ファイルのオープン
  fp = fopen(filename,"rb");
  
  //ファイル読み込み失敗：異常終了
  if(fp == NULL)
    {
      return -1;
    }
  
  //ビットマップファイルヘッダの読み込み
  fread(&bmfhead.bfType,sizeof(WORD),1,fp);
  fread(&bmfhead.bfSize,sizeof(DWORD),1,fp);
  fread(&bmfhead.bfReserved1,sizeof(WORD),1,fp);
  fread(&bmfhead.bfReserved2,sizeof(WORD),1,fp);
  fread(&bmfhead.bfOffBits,sizeof(DWORD),1,fp);
  
  //ビットマップインフォヘッダの読み込み
  fread(&bmihead.biSize,sizeof(DWORD),1,fp);
  fread(&bmihead.biWidth,sizeof(LONG),1,fp);
  fread(&bmihead.biHeight,sizeof(LONG),1,fp);
  fread(&bmihead.biPlanes,sizeof(WORD),1,fp);
  fread(&bmihead.biBitCount,sizeof(WORD),1,fp);
  fread(&bmihead.biCompression,sizeof(DWORD),1,fp);
  fread(&bmihead.biSizeImage,sizeof(DWORD),1,fp);
  fread(&bmihead.biXPelsPerMeter,sizeof(LONG),1,fp);
  fread(&bmihead.biYPelsPerMeter,sizeof(LONG),1,fp);
  fread(&bmihead.biClrUsed,sizeof(DWORD),1,fp);
  fread(&bmihead.biClrImportant,sizeof(DWORD),1,fp);
  
  //ファイルポインタの移動
  fseek(fp,bmfhead.bfOffBits,SEEK_SET);
  
  //画像データの取得
  if(bmihead.biHeight > 0)
    for(i = 0;i < y;i++)
      read_size += fread((image + (y-1-i)*x),x,1,fp);
  else
    read_size = fread(image,x,y,fp);
  
  //ファイルのクローズ
  fclose(fp);
  
  //取得画像サイズのチェック
  if(read_size == y)//正しかった場合：正常終了
    return read_size;
  else		    //異なる場合:異常終了
    return -1;
}

int SaveBMP(char *filename,unsigned char *image,int x,int y)
{
  FILE *fp;			//画像ファイルポインタ
  int read_size;		//画像読み込みサイズ
  BITMAPFILEHEADER bmfhead;	//ビットマップファイルヘッダ
  BITMAPINFOHEADER bmihead;	//ビットマップインフォヘッダ
  RGBQUAD palet[256];		//カラーパレット
  int i;			//繰り返し制御に使用
  int write_size = 0;		//書き込み成功画像サイズ
  
  //ビットマップファイルヘッダの設定
  bmfhead.bfType      = 0x4D42;
  bmfhead.bfSize      = 14 + 40 + 4*256 + x*y;
  bmfhead.bfReserved1 = 0;
  bmfhead.bfReserved2 = 0;
  bmfhead.bfOffBits   = 14 +40 + 4*256;
  
  //ビットマップインフォヘッダの設定	
  bmihead.biSize          = 40;
  bmihead.biWidth         = x;
  bmihead.biHeight        = y;
  bmihead.biPlanes        = 1;
  bmihead.biBitCount      = 8;
  bmihead.biCompression   = 0;
  bmihead.biSizeImage     = 0;
  bmihead.biXPelsPerMeter = 0;
  bmihead.biYPelsPerMeter = 0;
  bmihead.biClrUsed       = 0;
  bmihead.biClrImportant  = 0;
  
  //カラーパレットの設定
  for(i = 0;i < 256;i++)
    {
      palet[i].rgbBlue     = i;
      palet[i].rgbGreen    = i;
      palet[i].rgbRed      = i;
      palet[i].rgbReserved = 0;
    }
  
  
  //ビットマップの設定終了
  
  
  //ファイルのオープン
  fp = fopen(filename,"wb");
  
  //ファイル作成失敗：異常終了
  if(fp == NULL)
    {
      return -1;
    }
  
  //fwrite(&bmfhead,14,1,fp);
  
  //ビットマップファイルヘッダの書き込み
  fwrite(&bmfhead.bfType,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfSize,sizeof(DWORD),1,fp);
  fwrite(&bmfhead.bfReserved1,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfReserved2,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfOffBits,sizeof(DWORD),1,fp);
  
  //ビットマップインフォヘッダの書き込み
  fwrite(&bmihead.biSize,sizeof(DWORD),1,fp);
  fwrite(&bmihead.biWidth,sizeof(LONG),1,fp);
  fwrite(&bmihead.biHeight,sizeof(LONG),1,fp);
  fwrite(&bmihead.biPlanes,sizeof(WORD),1,fp);
  fwrite(&bmihead.biBitCount,sizeof(WORD),1,fp);
  fwrite(&bmihead.biCompression,sizeof(DWORD),1,fp);
  fwrite(&bmihead.biSizeImage,sizeof(DWORD),1,fp);
  fwrite(&bmihead.biXPelsPerMeter,sizeof(LONG),1,fp);
  fwrite(&bmihead.biYPelsPerMeter,sizeof(LONG),1,fp);
  fwrite(&bmihead.biClrUsed,sizeof(DWORD),1,fp);
  fwrite(&bmihead.biClrImportant,sizeof(DWORD),1,fp);
  
  fwrite(&palet,4,256,fp);
  
  
  //ファイルポインタの移動
  fseek(fp,bmfhead.bfOffBits,SEEK_SET);
  
  //画像の書き込み
  for(i = 0;i < y;i++)
      write_size += fwrite((image + (y-1-i)*x),x,1,fp);

  if((i = bmfhead.bfSize%4) != 0)
    {
      bmfhead.bfSize += i;
      for(;i;i--)
	fputc(0,fp);
    }
  
  //ファイルポインタのクローズ
  fclose(fp);
  
  //書き込み画像サイズのチェック
  if(write_size == y)	//正しかった場合：正常終了
    return write_size;
  else			//異なる場合:異常終了
    return -1;
  
}

#endif
