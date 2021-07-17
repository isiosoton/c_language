#include <stdio.h>
int main(void)
{
    float h;
    printf("身長は？");
    scanf("%f", &h);

    /***************/
    if(h<100)
    {
        printf("小さめ\n");
    }
    else if(100<=h && h<200)
    {
        printf("ふつう\n");
    }
    else if(h>=200)
    {
        printf("おおきい\n");
    }
    else
    {
        printf("うちゅうじん\n");
    }
    /***************/
    
    return 0;
}
