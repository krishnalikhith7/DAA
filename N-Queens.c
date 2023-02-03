#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
int x[100];
char Q[100][100];
bool place(int k,int i)
{
        for(int j=0;j<=k-1;j++)
        {
                if(x[j]==i ||((abs(x[j]-i)==abs(j-k))))
                {
                        return false;
                }
        }
        return true;
}
void nqueens(int k,int n)
{
        int w;
        for(int i=0;i<n;i++)
        {
                if(place(k,i))
                {
                        x[k]=i;
                        if(k==n-1)
                        {

                                for(int j=0;j<n;j++)
                                {
                                        w=x[j];
                                        for(int m=0;m<n;m++)
                                        {
                                                if(m==w)
                                                {
                                                        Q[j][m]='Q';
                                                }
                                                else
                                                {
                                                        Q[j][m]='.';
                                                }
                                        }
                                }
                                for(int s=0;s<n;s++)
                                {
                                        for(int t=0;t<n;t++)
                                        {
                                                printf("%c\t",Q[s][t]);
                                        }

                                }
                                printf("\n");
                        }

                        else
                        {
                                nqueens(k+1,n);
                        }
                }
        }
}

void main()
{
        int n;
        printf("enter n");
        scanf("%d",&n);
        nqueens(0,n);

}

output:
enter n4
.       Q       .       .       .       .       .       Q       Q       .       .       .       .       .       Q       .
.       .       Q       .       Q       .       .       .       .       .       .       Q       .       Q       .       .
