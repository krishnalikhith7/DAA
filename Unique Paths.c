#include<stdio.h>
int uniquePaths(int m, int n){
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        a[i][0]=1;
    }
    for(int i=0;i<n;i++)
    {
        a[0][i]=1;
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            a[i][j]=a[i][j-1]+a[i-1][j];
        }
    }
    return a[m-1][n-1];
}
void main()
{
int m,n;
printf("enter number of rows in grid");
scanf("%d",&m);
printf("enter number of columns in grid");
scanf("%d",&n);
int r=uniquePaths(m,n);
printf("Number of Unique Paths: %d",r);
}

output:
enter number of rows in grid3
enter number of columns in grid7
Number of Unique Paths: 28
