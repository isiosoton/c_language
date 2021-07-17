#include <stdio.h>

//関数のプロトタイプ宣言
void A(void);

//main関数
int main(void)
{
		printf("main開始\n");
		A();
		printf("main終了\n");
		
		return 0;
}

//各関数の定義
//A関数の定義
void A(void)
{
		printf("A実行\n");
}
