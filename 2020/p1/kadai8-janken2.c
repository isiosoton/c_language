#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int	x, r, you, pc;
    char te[3][10]={"グー", "チョキ", "パー"};
	srand(time(NULL));

	printf("ジャンケンしましょう！\n");
	//for(you=0,pc=0; you<3 && pc<3;)
	you=pc=0; 
	while(you<3 && pc<3)
	{
		r = rand()%3+1;
		printf("1. グー\n2. チョキ\n3. パー\n :");
		scanf("%d", &x);
		
        printf("\nあなた%d 　 コンピュータ%d\n", x, r);
        printf("　%s　vs　%s\n", te[x-1], te[r-1]);

		if(x == r)
		{
			printf("\nあいこ\n\n");
			continue;
		}
		else if((x == 1 && r == 2) || (x == 2 && r == 3) || (x == 3 && r == 1))
		{
			printf("\nあなたの勝ち\n");
			you++;
		}
        else if((x == 1 && r == 3) || (x == 2 && r == 1) || (x == 3 && r == 2))
		{
			printf("\nあなたの負け\n");
			pc++;
		}
		else
		{
			printf("\n入力を確認してください。\n");
		}
		printf("あなたの%d勝、%d敗です。\n\n", you, pc);
	}
	if(you == 3)
	{
		printf("あなたが先に３勝しました。\n");
	}
	else
	{
		printf("ゲームオーバー\n");
	}
	
	return 0;
}
