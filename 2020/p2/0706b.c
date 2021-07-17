#include <stdio.h>

int main(void)
{
  float t, d[10]={10,9,8,7,6,5,4,3,2,1};
  int i=0, j;

  for(j=9;0<j;j--)
  {
    for(i=0;i<j;i++)
    {
      if(d[i]>d[i+1])
      {
          t = d[i];
          d[i] = d[i+1];
          d[i+1] = t;
      }
    }
  }
  return 0;
}
