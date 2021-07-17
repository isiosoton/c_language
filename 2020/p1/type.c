#include <stdio.h>

int main(void)
{
    int i, select, n=100;
    char types[10][100] = 
    {
        {"一ノ型 画面への出力"},
        {"二ノ型 変数への値の代入"},
        {"三ノ型 演算"},
        {"四ノ型 コマンドラインからの入力"},
        {"五ノ型 条件分岐"},
        {"六ノ型 繰り返し"},
        {"七ノ型 繰り返しを最初から"},
        {"八ノ型 繰り返しからの離脱"},
        {"九ノ型 ファイルの読み込み"},
        {"十ノ型 配列"}
    };

    while(1)
    {
        printf("\n--------------------\nプログラミングの型\n");
        printf("1. すべての型を表示\n2. 型番号を指定して表示\n3. 終了\n");
        printf("メニュー番号を入力してください：");
        scanf("%d", &select);

        if(select == 3)
        {
            printf(" プログラムを終了します。\n");
            break;
        }
        else if(select == 1)
        {
            for(i=0; i<10; i++)
            {
                printf("  プログラミング %s\n", types[i]);
            }
        }
        else if(select == 2)
        {
            while(1)
            {
                printf(" 型の番号（1〜10）を入力してください\n");
                printf(" メニューに戻るには0を入力してください：");
                scanf("%d", &n);
                if(1<=n && n<=10)
                {
                    printf("\n  プログラミング %s\n\n", types[n-1]);
                }
                else if(n == 0)
                {
                    break;
                }
                else
                {
                    printf("\n  1〜10の数字を入力してください。\n\n");
                }

            }
        }
        else
        {
            printf("\n1-3の数字を入力してください。\n");
        }
        
    }
}
