#include <stdio.h>
int main(void)
{
    int l,k=1001,j,i;
    float temp[2],h[k][2];
    
    for(l=0;scanf("%f%f",&h[l][0],&h[l][1])!=EOF || l<k;l++)
    {
        //printf("%f %f\n",h[l][0],h[l][1]);
    }
    for(j=k-1; 0<j; j--)
    {
        for(i=0; i<j; i++)
		{
			if(h[i][0]>h[i+1][0])
			{
				temp[0] = h[i][0];
                temp[1] = h[i][1];
				h[i][0] = h[i+1][0];
                h[i][1] = h[i+1][1];
				h[i+1][0] = temp[0];
                h[i+1][1] = temp[1];
			}
			//printf("%d %d　★\n", i, i+1);
		}
    }
    int m;
    for(m=0;m<l;m++)
    {
        printf("%4d %3.1f %3.1f\n",m+1,h[m][0],h[m][1]);
    }
    return 0;    
}