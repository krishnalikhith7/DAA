#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    if(a==-1 && b==-1)
    {
        return -1;
    }
    else if(a==-1)
    {
        return b;
    }
    else if(b==-1)
    {
        return a;
    }
    else
    {
        if(a<b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}
int coinChange(int* coins, int coinsSize, int amount){
    int k;
    if(amount==0)
    {
        return 0;
    }
    int a[coinsSize+1][amount+1];
    a[0][0]=0;
    for(int i=1;i<=amount;i++)
    {
        if(i%coins[0]==0)
        {
            a[0][i]=i/coins[0];
        }
        else
        {
            a[0][i]=-1;
        }
    }
    for(int i=1;i<coinsSize;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(coins[i]>j)
            {
                a[i][j]=a[i-1][j];
            }
            else
            {
                k=a[i][j-coins[i]];
                if(k!=-1)
                {
                    k=k+1;
                }
                a[i][j]=min(a[i-1][j],k);
            }
        }
    }
    return a[coinsSize-1][amount];
}
void main()
{
int coinsSize,amount;
printf("enter number of different coins");
scanf("%d",&coinsSize);
int* coins=(int*)malloc(sizeof(int)*coinsSize);
printf("enter denominations");
for(int i=0;i<coinsSize;i++)
{
scanf("%d",&coins[i]);
}
printf("enter amount");
scanf("%d",&amount);
int r=coinChange(coins,coinsSize,amount);
printf("Minimum number of coins required: %d",r);
}

output:
enter number of different coins3
enter denominations1
2
5
enter amount11
Minimum number of coins required: 3
