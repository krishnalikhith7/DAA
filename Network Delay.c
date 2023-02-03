#include <stdio.h>
#include<stdlib.h>
int cost(int** times,int k,int j,int timesSize)
{
    for(int i=0;i<timesSize;i++)
    {
        if(times[i][0]==k && times[i][1]==j)
        {
            return times[i][2];
        }

    }
    return 10000;
}
int min_arr(int arr[100],int j,int n,int visited[100])
{
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[j]>arr[i] && visited[i]!=1)
        {
            flag=1;
            break;
        }
    }
    return flag;
}
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int r=-1,flag;
    int dist[n+1];
    int visited[n+1];
    for(int i=1;i<=n;i++)
    {
        dist[i]=cost(times,k,i,timesSize);
        visited[i]=0;
    }
    visited[k]=1;
    dist[k]=0;
    int q=1;
    while(q<=n-1)
    {
    for(int i=1;i<=n;i++)
    {
        if(visited[i]!=1 && min_arr(dist,i,n,visited)==0)
        {
            visited[i]=1;
            q=q+1;
            for(int k=0;k<timesSize;k++)
            {
                if(times[k][0]==i)
                {
                    int p=times[k][1];
                    int s=cost(times,i,p,timesSize);
                    if(dist[p]>(dist[i]+s))
                    {
                        dist[p]=dist[i]+s;
                    }
                }
            }
        }
    }
    }
    r=dist[1];
    for(int i=1;i<=n;i++)
    {
        flag=0;
        if(dist[i]==10000)
        {
            flag=1;
            break;
        }
        else{
            if(dist[i]>r)
            {
                r=dist[i];
            }
        }
    }
    if(flag==1)
    {
    return -1;
    }
    else{
        return r;
    }
}
void main()
{
    int timesSize,timesColSize=3,k,n;
    printf("enter number of vertices");
    scanf("%d",&n);
    printf("enter timesSize");
    scanf("%d",&timesSize);
    int **times=(int**)malloc(timesSize*sizeof(int*));
    for(int i=0;i<timesSize;i++)
    {
        times[i]=(int*)malloc(timesColSize*sizeof(int));
    }
    for(int i=0;i<timesSize;i++)
    {
        for(int j=0;j<timesColSize;j++)
        {
            scanf("%d",&times[i][j]);
        }
    }
    printf("enter starting edge");
    scanf("%d",&k);
    int r=networkDelayTime(times,timesSize,&timesColSize,n,k);
    printf("network delay :%d",r);
}

output1:
enter number of vertices4
enter timesSize3
2
1
1
2
3
1
3
4
1
enter starting edge2
network delay :2

output2:
enter number of vertices2
enter timesSize1
1
2
1
enter starting edge2
network delay :-1
