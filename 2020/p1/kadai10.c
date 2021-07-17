#include <stdio.h>
#include <stdlib.h>


void read_file(void);

int main(void)
{
	int	f, game, s;

	//ファイルからの読み込み
	read_file();
	
	//基本ループ（課題10）
	game = 1;
	f = 4;
	while(game == 1)
	{
		//メニュー番号入力前の出力
		printf("\n===================================\n%dフロア目\n", f);
		if(f == 1)
		{
			printf(" 3. 階段（上の階に行く）\n:");
		}
		else if(2<=f && f<=3)
		{
			printf(" 3. 階段（上の階に行く）\n 4. 階段（下の階に行く）\n:");
		}
		else if(4<=f && f<=6)
		{
			printf(" 0. 部屋0\n 1. 部屋1\n 2. 部屋2\n 3. 階段（上の階に行く）\n 4. 階段（下の階に行く）\n: ");
		} 
		else if(f == 7)
		{
			printf(" 0. BOSS部屋\n 4. 階段（下の階に行く）\n: ");
		}
		
		scanf("%d", &s);
		
		//メニュー番号入力後の処理＆出力
		if((1<=f && f<=6) && (s==3))
		{
			f ++;
			continue;
		}
		else if((2<=f && f<=7) && (s==4))
		{
			f --;
			continue;
		}
		else if(f==1 && s!=3)
		{
			printf("上に行くしかありません。\n");
			continue;
		}
		else if((2<=f && f<=3) && (0<=s && s<=2))
		{
			printf("この階に部屋はありません。\n");
			continue;
		}
		else if((f==7) && !(s==0 || s==4))
		{
			printf("0か4を入力してください。\n");
			continue;
		}
		else if(s<0 || s>4)
		{
			printf("入力を確認してください。\n");
			continue;
		}

		//戦闘のための処理		
		printf("\n-----------------------------------------\n部屋%dに入った。\n戦闘!!\n", s);

	}
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
