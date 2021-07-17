#include <stdio.h>
#include <string.h>
int main(void)
{
		int		i;
		char	name[10], name_sub[10], name_sub2[10];
		
		printf("勇者よ、君の名は？：");

		//&が無くても良い
		scanf("%s", name);
		
		printf("\n1. 勇者%sくん、一緒に冒険に出かけよう！\n\n", name);
		
		//name中の文字列を別の変数に代入してみよう
		//name_sub = name; //これはできない
		for(i=0; name[i]!='\0';i++)
		{
				name_sub[i] = name[i];
		}
		name_sub[i] = '\0';
		printf("\n2. 勇者%sくん、一緒に冒険に出かけよう！\n\n", name_sub);
		
		strncpy(name_sub2, name, 10);
		printf("\n3. 勇者%sくん、一緒に冒険に出かけよう！\n\n", name_sub2);
		
		//if(name == name_sub2)//このように文字列を比較することはできない
		if(strcmp(name, name_sub2) == 0) //文字の比較
		{
			printf("おなじ\n");
		}
		if(strncmp(name, name_sub2, 5) == 0) //文字の比較(文字数での範囲を指定可)
		{
			printf("おなじ\n");
		}
		return 0;
		//2バイト文字(日本語、漢字など)は3倍の箱が必要
}
