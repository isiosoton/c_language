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


//�r�b�g�}�b�v�t�@�C������̉摜�f�[�^�擾�������Ȃ��֐�
//�������擾�ł����ꍇ�C�擾�摜�T�C�Y��Ԃ�
int LoadBMP(char *filename,unsigned char *image,int x, int y)
{
  FILE *fp;		   //�摜�t�@�C���|�C���^
  int read_size = 0;	   //�摜�ǂݍ��ݐ����T�C�Y
  BITMAPFILEHEADER bmfhead;//�r�b�g�}�b�v�t�@�C���w�b�_
  BITMAPINFOHEADER bmihead;//�r�b�g�}�b�v�C���t�H�w�b�_
  int i;		   //�J��Ԃ�����Ɏg�p
  
  //�t�@�C���̃I�[�v��
  fp = fopen(filename,"rb");
  
  //�t�@�C���ǂݍ��ݎ��s�F�ُ�I��
  if(fp == NULL)
    {
      return -1;
    }
  
  //�r�b�g�}�b�v�t�@�C���w�b�_�̓ǂݍ���
  fread(&bmfhead.bfType,sizeof(WORD),1,fp);
  fread(&bmfhead.bfSize,sizeof(DWORD),1,fp);
  fread(&bmfhead.bfReserved1,sizeof(WORD),1,fp);
  fread(&bmfhead.bfReserved2,sizeof(WORD),1,fp);
  fread(&bmfhead.bfOffBits,sizeof(DWORD),1,fp);
  
  //�r�b�g�}�b�v�C���t�H�w�b�_�̓ǂݍ���
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
  
  //�t�@�C���|�C���^�̈ړ�
  fseek(fp,bmfhead.bfOffBits,SEEK_SET);
  
  //�摜�f�[�^�̎擾
  if(bmihead.biHeight > 0)
    for(i = 0;i < y;i++)
      read_size += fread((image + (y-1-i)*x),x,1,fp);
  else
    read_size = fread(image,x,y,fp);
  
  //�t�@�C���̃N���[�Y
  fclose(fp);
  
  //�擾�摜�T�C�Y�̃`�F�b�N
  if(read_size == y)//�����������ꍇ�F����I��
    return read_size;
  else		    //�قȂ�ꍇ:�ُ�I��
    return -1;
}

int SaveBMP(char *filename,unsigned char *image,int x,int y)
{
  FILE *fp;			//�摜�t�@�C���|�C���^
  int read_size;		//�摜�ǂݍ��݃T�C�Y
  BITMAPFILEHEADER bmfhead;	//�r�b�g�}�b�v�t�@�C���w�b�_
  BITMAPINFOHEADER bmihead;	//�r�b�g�}�b�v�C���t�H�w�b�_
  RGBQUAD palet[256];		//�J���[�p���b�g
  int i;			//�J��Ԃ�����Ɏg�p
  int write_size = 0;		//�������ݐ����摜�T�C�Y
  
  //�r�b�g�}�b�v�t�@�C���w�b�_�̐ݒ�
  bmfhead.bfType      = 0x4D42;
  bmfhead.bfSize      = 14 + 40 + 4*256 + x*y;
  bmfhead.bfReserved1 = 0;
  bmfhead.bfReserved2 = 0;
  bmfhead.bfOffBits   = 14 +40 + 4*256;
  
  //�r�b�g�}�b�v�C���t�H�w�b�_�̐ݒ�	
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
  
  //�J���[�p���b�g�̐ݒ�
  for(i = 0;i < 256;i++)
    {
      palet[i].rgbBlue     = i;
      palet[i].rgbGreen    = i;
      palet[i].rgbRed      = i;
      palet[i].rgbReserved = 0;
    }
  
  
  //�r�b�g�}�b�v�̐ݒ�I��
  
  
  //�t�@�C���̃I�[�v��
  fp = fopen(filename,"wb");
  
  //�t�@�C���쐬���s�F�ُ�I��
  if(fp == NULL)
    {
      return -1;
    }
  
  //fwrite(&bmfhead,14,1,fp);
  
  //�r�b�g�}�b�v�t�@�C���w�b�_�̏�������
  fwrite(&bmfhead.bfType,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfSize,sizeof(DWORD),1,fp);
  fwrite(&bmfhead.bfReserved1,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfReserved2,sizeof(WORD),1,fp);
  fwrite(&bmfhead.bfOffBits,sizeof(DWORD),1,fp);
  
  //�r�b�g�}�b�v�C���t�H�w�b�_�̏�������
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
  
  
  //�t�@�C���|�C���^�̈ړ�
  fseek(fp,bmfhead.bfOffBits,SEEK_SET);
  
  //�摜�̏�������
  for(i = 0;i < y;i++)
      write_size += fwrite((image + (y-1-i)*x),x,1,fp);

  if((i = bmfhead.bfSize%4) != 0)
    {
      bmfhead.bfSize += i;
      for(;i;i--)
	fputc(0,fp);
    }
  
  //�t�@�C���|�C���^�̃N���[�Y
  fclose(fp);
  
  //�������݉摜�T�C�Y�̃`�F�b�N
  if(write_size == y)	//�����������ꍇ�F����I��
    return write_size;
  else			//�قȂ�ꍇ:�ُ�I��
    return -1;
  
}

#endif
