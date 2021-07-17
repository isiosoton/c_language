#include <stdio.h>
#include <stdlib.h>

//課題11
struct STATUS {
	int	id;
	char	name[50];
	int	pw, hp, ex;
};

void read_file(struct STATUS amem[], struct STATUS m[][3][3], int levelup[], char *files[]);

int main(void)
{
	struct STATUS party[3]={}, amem[6]={}, mon[8][3][3]; //課題11
	int i, j, levelup[101]; //課題11
	int	f, s, game; //課題10
	char *files[6] = {"members.txt", "monsters.txt", "levelup.txt", "save-party.txt", "save-monsters.txt", "save.txt"};//課題9

	//ファイルからの読み込み
	read_file(amem, mon, levelup, files);

	for(i=0; i<6; i++)
	{
		printf("%d, %s, %d, %d\n", amem[i].id, amem[i].name, amem[i].pw, amem[i].hp);
	}
	
	for(i=4; i<=6; i++) //フロア番号
	{
		for(j=0; j<3; j++) //部屋番号
		{
			printf("%d, %s, %d, %d, %d\n", mon[i][j][0].id, mon[i][j][0].name, mon[i][j][0].pw, mon[i][j][0].hp, mon[i][j][0].ex);
			printf("%d, %s, %d, %d, %d\n", mon[i][j][1].id, mon[i][j][1].name, mon[i][j][1].pw, mon[i][j][1].hp, mon[i][j][1].ex);
			printf("%d, %s, %d, %d, %d\n", mon[i][j][2].id, mon[i][j][2].name, mon[i][j][2].pw, mon[i][j][2].hp, mon[i][j][2].ex);
		}
	}

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
void read_file(struct STATUS amem[], struct STATUS m[][3][3], int levelup[], char *files[])
{
	FILE	*fp;
	int	i, f, r, n, id;
	
	//メンバーファイル （課題9）
	if((fp=fopen(files[0], "r")) == NULL)
	{
		printf("members.txtがありません\n");
		exit(1);
	}
	
	//読み込み （課題11）
	i=0;
	while(fscanf(fp, "%d %s %d %d", &amem[i].id, amem[i].name, &amem[i].pw, &amem[i].hp)!=EOF)
	{
		i++;
	}
	//クローズ
	fclose(fp);
	
	//モンスターファイル （課題9）
	if((fp=fopen(files[1], "r")) == NULL)
	{
		printf("monsters.txtがありません\n");
		exit(1);
	}
	
	//読み込み （課題11）
	i=0;
	while(fscanf(fp, "%d%d%d%d", &id, &f, &r, &n)!=EOF)
	{
		m[f][r][n].id = id;
		fscanf(fp, "%s %d%d%d", m[f][r][n].name, &m[f][r][n].pw, &m[f][r][n].hp, &m[f][r][n].ex);
		//i++;
	}
	
	//クローズ
	fclose(fp);
	
	//レベルアップファイル （課題9）
	if((fp=fopen(files[2], "r")) == NULL)
	{
		printf("%sがありません\n", files[2]);
		exit(1);
	}
	
	//読み込み （課題11）
	i=0;
	while(fscanf(fp, "%d", &levelup[i])!=EOF)
	{
		i++;
	}
	
	//クローズ
	fclose(fp);
	
}