#include<stdio.h>
#include<stdlib.h>
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    int c[10];
    for(int i=0;i<boxTypesSize-1;i++)
    {
        for(int j=0;j<boxTypesSize-i-1;j++)
        {
            if(boxTypes[j][1]<boxTypes[j+1][1])
            {
                c[0]=boxTypes[j][0];
                c[1]=boxTypes[j][1];
                boxTypes[j][0]=boxTypes[j+1][0];
                boxTypes[j][1]=boxTypes[j+1][1];
                boxTypes[j+1][0]=c[0];
                boxTypes[j+1][1]=c[1];
            }
        }
    }
    int r=0;
    for(int i=0;i<boxTypesSize;i++)
    {
        if(truckSize==0)
        {
            break;
        }
        if(boxTypes[i][0]<truckSize)
        {
            r+=(boxTypes[i][0])*(boxTypes[i][1]);
            truckSize-=boxTypes[i][0];
        }
        else
        {
            r+=truckSize*boxTypes[i][1];
            truckSize=0;
        }

    }
    
    return r;
}
int main()
{
    int truckSize;
    int boxTypesSize;
    int boxTypesColSize=2;
    printf("enter boxTypesSize");
    scanf("%d",&boxTypesSize);
    int** boxTypes=(int**)malloc(boxTypesSize*sizeof(int*));
    for(int i=0;i<boxTypesSize;i++)
    {
       boxTypes[i]=(int*)malloc(boxTypesColSize*sizeof(int));
    }
    for(int i=0;i<boxTypesSize;i++)
    {
        for(int j=0;j<boxTypesColSize;j++)
        {
            scanf("%d",&boxTypes[i][j]);
        }
    }
    printf("enter truck size");
    scanf("%d",&truckSize);
    int c=maximumUnits(boxTypes,boxTypesSize,&boxTypesColSize,truckSize);
    printf("%d",c);
    return 0;
}

output:
enter boxTypesSize3
1
3
2
2
3
1
enter truck size4
8
