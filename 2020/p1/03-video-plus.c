#include <stdio.h>

int kakezan(int x, int y);

int main(void)
{
		int x, y, ans;
		
		x = 100;
		y = 200;
		printf ("main : x = %d, y = %d\n", x, y);

		ans = kakezan(x, y);
		printf ("sub : %d * %d = %d\n", x, y, ans);
		
		return 0;
}

int kakezan(int x, int y)
{
		int	ans;

		ans = x * y;

        return (ans);
}
/*
掛け算を"kakezan"という文字で定義しただけ？
ans: そうです。自分で付けた名前です。名前の付け方については教科書を参照してください。

関数の戻り値は一つしか設定できないのですか？
ans: そうです、戻り値は一つしか設定できません。

voidとは？
ans: voidとは何も無いという意味です。

関数がどんな時に便利か？
ans: プログラムが長くなった時にプログラムを読みやすくするために使います。
     それはprintf関数などこれまで使ってきた関数が関数でない時のことを想像するとわかるかもしれません。

return のあとの ()は必要か？
ans: 無くても正常に動作します。

*/

