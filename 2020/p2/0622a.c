#include<stdio.h>
 int main(void)
{
   int a,b; 
   while(scanf("%d %d",&a,&b) != EOF)
   {
       printf("%02d %02d\n",a,b);
   }
   return 0;
}