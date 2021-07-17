#include <stdio.h>

void read_file();

int main(void)
{
	//ファイルからの読み込み
	read_file();
	
	return 0;
}

/*************************************
*
*	ファイルデータ読み込み関数
*
*************************************/
void read_file(void)
{
	FILE	*fp;
	
	//メンバーファイル
	if((fp=fopen("members.txt", "r")) == NULL)
	{
		printf("members.txtがありません\n");
		exit(1);
	}
	fclose(fp);
	
	
	//モンスターファイル
	if((fp=fopen("monsters.txt", "r")) == NULL)
	{
		printf("monsters.txtがありません\n");
		exit(1);
	}
	fclose(fp);
	
	//レベルアップファイル
	if((fp=fopen("levelup.txt", "r")) == NULL)
	{
		printf("levelup.txtがありません\n");
		exit(1);
	}
	fclose(fp);	
}
