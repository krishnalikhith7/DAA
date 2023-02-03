#include<stdio.h>
#include<stdlib.h>
int maxEvents(int** events, int eventsSize, int* eventsColSize){
    int b[2];
    for(int i=0;i<eventsSize;i++)
    {
        for(int j=0;j<eventsSize-i-1;j++)
        {
            if(events[j][1]>events[j+1][1])
            {
                b[0]=events[j][0];
                b[1]=events[j][1];
                events[j][0]=events[j+1][0];
                events[j][1]=events[j+1][1];
                events[j+1][0]=b[0];
                events[j+1][1]=b[1];
            }
            else if(events[j][1]==events[j+1][1])
            {
                if(events[j][0]>events[j+1][0])
                {
                b[0]=events[j][0];
                b[1]=events[j][1];
                events[j][0]=events[j+1][0];
                events[j][1]=events[j+1][1];
                events[j+1][0]=b[0];
                events[j+1][1]=b[1];
                }
            }
        }
    }

    int k=events[eventsSize-1][1],c=0;
    int a[k+1];
    for(int i=0;i<=k;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<eventsSize;i++)
    {
        if(a[events[i][0]]==0)
        {
            a[events[i][0]]=1;
            c=c+1;
        }
        else
        {
            for(int j=(events[i][0]+1);j<=events[i][1];j++)
            {
                if(a[j]==0)
                {
                    a[j]=1;
                    c=c+1;
                    break;
                }
            }
        }
    }
    return c;
}
void main()
{
int eventsSize,x=2;
int* eventsColSize=&x;
printf("enter total number of events");
scanf("%d",&eventsSize);
int** events=(int**)malloc(eventsSize*sizeof(int*));
for(int i=0;i<eventsSize;i++)
{
events[i]=(int*)malloc(*(eventsColSize)*sizeof(int));
}
for(int i=0;i<eventsSize;i++)
{
for(int j=0;j<*(eventsColSize);j++)
{
scanf("%d",&events[i][j]);
}
}
int c=maxEvents(events,eventsSize,eventsColSize);
printf("Maximum number of events that can be attended is %d",c);
}

output:
enter total number of events3
1
2
2
3
3
4
Maximum number of events that can be attended is 3
