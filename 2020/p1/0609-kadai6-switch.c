#include <stdio.h>
int main(void)
{
    float	w, h; /* w:底辺の長さ, h:高さ */
    int     sel, s;
    float	S;
    char    a;

    for(; sel!=4; )
    {
        printf("面積を算出します。\n");
        printf("1. 円\n2. 正方形\n3. 三角形\n4. 終了\n");
        printf("図形を選んでください：");
        scanf("%d", &sel);
        
        swith(sel)
        {
            case 1:
                printf("円の面積を計算します。\n");
                printf("円の半径を入力してください：");
                scanf("%f", &w);
                
                S = 3.14 * w * w;
                printf("円の面積は%.2fです。\n", S);
                break;
        
            case 2:
                printf("正方形の面積を計算します。\n");
                printf("1辺の長さを入力してください：");
                scanf("%f", &w);
                
                S = w * w;
                printf("正方形の面積は%.2fです。\n", S);
                break;

            case 3:
                printf("三角形の面積を計算します。\n");
                printf("底辺の長さを入力してください：");
                scanf("%f", &w);
                printf("高さを入力してください：");
                scanf("%f", &h);
                
                S = w * h / 2.0;
                printf("三角形の面積は%.2fです。\n", S);
                break;

            case 4:
                printf("終了します。\n");
                break; //今回のfor文では無くても良い
            
            default:
                printf("入力が不適切でした。\n");
                break;
        }
        
    }
    
    return 0;
}
