#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int j,int k)
{
    int temp;
    temp=a[j];
    a[j]=a[k];
    a[k]=temp;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize){
    int *dp=(int*)malloc(endTimeSize*sizeof(int));
    int flag=0;
for(int i=0;i<endTimeSize;i++)
{
    for(int j=0;j<endTimeSize-i-1;j++)
    {
        if(endTime[j]>endTime[j+1])
        {
            swap(endTime,j,j+1);
            swap(startTime,j,j+1);
            swap(profit,j,j+1);
        }
    }
}
for(int i=0;i<endTimeSize;i++)
{
    for(int j=0;j<=i;j++)
    {
        if(endTime[j]<=startTime[i])
        {
            dp[i]=max(profit[i]+dp[j],dp[i]);
            flag=1;
        }  
    }
    if(flag==0)
    {
        dp[i]=profit[i];
    }
}
int max=dp[0];
for(int i=0;i<endTimeSize;i++)
{
    if(dp[i]>max)
    {
        max=dp[i];
        
    }
}
return max;
}
void main()
{
int startTimeSize,endTimeSize,profitSize;
printf("enter startTimeSize");
scanf("%d",&startTimeSize);
int* startTime=(int*)malloc(startTimeSize*sizeof(int));
printf("enter starting times");
for(int i=0;i<startTimeSize;i++)
{
scanf("%d",&startTime[i]);
}
printf("enter endTimeSize");
scanf("%d",&endTimeSize);
int* endTime=(int*)malloc(endTimeSize*sizeof(int));
printf("enter ending times");
for(int i=0;i<endTimeSize;i++)
{
scanf("%d",&endTime[i]);
}
printf("enter profitSize");
scanf("%d",&profitSize);
int* profit=(int*)malloc(profitSize*sizeof(int));
printf("enter profits");
for(int i=0;i<profitSize;i++)
{
scanf("%d",&profit[i]);
}
int max_profit=jobScheduling(startTime,startTimeSize,endTime,endTimeSize,profit,profitSize);
printf("Maximum profit: %d",max_profit);
}

output:
enter startTimeSize4
enter starting times 
1
2
3
4
enter endTimeSize4
enter ending times
3
4
5
6
enter profitSize4
enter profits
50
10
40
70
Maximum profit: 120
