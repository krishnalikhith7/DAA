#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int min(int dist[],int v[],int pointsSize)
{
    int m=INT_MAX,ind;
    for(int i=0;i<pointsSize;i++)
    {
        if(v[i]==0 && dist[i]<m)
        {
            m=dist[i];
            ind=i;

        }
    }
    return ind;
}
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int cost[pointsSize][pointsSize],v[1000],dist[pointsSize],u;
    for(int i=0;i<pointsSize;i++)
    {
        v[i]=0;
        dist[i]=INT_MAX;
        for(int j=0;j<pointsSize;j++)
        {
        if(i!=j)
        {
            cost[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
        }
        else
        {
            cost[i][j]=INT_MAX;
        }
        }
    }
    dist[0]=0;
    for(int i=0;i<pointsSize;i++)
    {
        u=min(dist,v,pointsSize);
        v[u]=1;
        for(int j=0;j<pointsSize;j++)
        {
            if(cost[u][j]<dist[j] && v[j]==0)
            {
                dist[j]=cost[u][j];
            }
        }
    }
    int s=0;
    for(int i=0;i<pointsSize;i++)
    {
        s+=dist[i];

    }
    return s;
}
void main()
{
int pointsSize,x=2;
int* pointsColSize=&x;
printf("enter number of points");
scanf("%d",&pointsSize);
int** points=(int**)malloc(pointsSize*sizeof(int*));
for(int i=0;i<pointsSize;i++)
{
points[i]=(int*)malloc(*(pointsColSize)*(sizeof(int)));
}
for(int i=0;i<pointsSize;i++)
{
for(int j=0;j<*(pointsColSize);j++)
{
scanf("%d",&points[i][j]);
}
}
int cost=minCostConnectPoints(points,pointsSize,pointsColSize);
printf("minimum cost to connect all points:%d",cost);
}

output:
enter number of points5
0
0
2
2
3
10
5
2
7
0
minimum cost to connect all points:20
