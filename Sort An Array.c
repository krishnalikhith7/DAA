#include<stdio.h>
void merge(int* nums,int l,int m,int u)
 {
     int i=l,j=m+1,k=l;
     int b[500000];
     while(i<=m && j<=u)
     {
         if(*(nums+i)<=*(nums+j))
         {
             b[k]=*(nums+i);
             k=k+1;
             i=i+1;
             
         }
         else
         {
             b[k]=*(nums+j);
             k=k+1;
             j=j+1;
         }
     }
     if(i>m)
     {
         while(j<=u)
         {
             b[k]=*(nums+j);
             k=k+1;
             j=j+1;
             
         }
     }
     if(j>u)
     {
         while(i<=m)
         {
            
             b[k]=*(nums+i);
             k=k+1;
             i=i+1;
             
         }
     }
     for(int s=l;s<=u;s++)
     {
         *(nums+s)=b[s];
     }

 }
 void mergeSort(int* nums,int l,int u)
 {
     if(l<u)
     {
         int m=(l+u)/2;
         mergeSort(nums,l,m);
         mergeSort(nums,m+1,u);
         merge(nums,l,m,u);
     }
 }
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    mergeSort(nums,0,numsSize-1);
    return nums;

}
void main()
{
    int numsSize,x=-1;
    int* returnSize=&x;
    printf("enter nums size");
    scanf("%d",&numsSize);
    int nums[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        printf("enter elements");
        scanf("%d",&nums[i]);
    }
    int* nums2;
    nums2=sortArray(nums,numsSize,returnSize);
    printf("after sorting\n[");
    for(int i=0;i<numsSize;i++)
    {
        printf("%d,",nums2[i]);
    }
    printf("]");
}

output:
enter nums size4
enter elements5
enter elements2
enter elements3
enter elements1
after sorting
[1,2,3,5,]
