#include <stdio.h>
int main(void)
{
    int num;
    printf("1～4までの数字を入力してください：\n");
    scanf("%d", &num);
    if(num == 1)
    {
        printf("一ノ型 画面への出力\n");
    }
    else if(1<= num && num <= 4)  //もしnum が1～4までの数字なら
    {
        printf("二ノ型 変数への値の代入\n");
        printf("三ノ型 演算\n");
        printf("四ノ型 コマンドラインからの入力\n");
        printf("五ノ型 条件分岐\n");
    }
    else //上記の条件に当てはまらない場合
    {
        printf("まだ早い！\n");
	}
}
