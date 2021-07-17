#include <stdio.h>
int main(void)
{
  int a,b,c,d;
  do
  {
    printf("数字当てゲーム！");
    a = rand()%10000;
      printf("%d\n",a);
    }
    for(,,)
    {
      printf("予想した自然数を入力してください：");
      scanf("%d",&c);
      if (c < a && 0 < c)
      {
        printf("残念！予想した数字よりも答えは大きいよ\nもう一度予想してみよう！");
      } else if (c > a) {
        printf("残念！予想した数字よりも答えは小さいよ\nもう一度予想してみよう！");
      } else {
        printf("本当に自然数を入力した？\nもう一度入力してね！");
      }
    } while (c = a);
    printf("正解！よく当たったね！");
    printf("終了する場合は1を入力してください。次も行う場合は1以外を入力してください。\n");
    scanf("%d",d);
    if (d == 1)
    {
      break;
    }
  }
  scanf("終了しました。\n");
}