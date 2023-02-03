#include<stdio.h>
void merge(int* nums1,int nums1Size, int m, int* nums2, int nums2Size,int n) 
{
        int i=0,j=0,k=0;
        int a[m+n];
        while(i!=m && j!=n)
        {
            if(nums1[i]<nums2[j])
            {
                a[k]=nums1[i];
                i=i+1;
                k=k+1;
            }
            else if(nums1[i]>nums2[j])
            {
                a[k]=nums2[j];
                j=j+1;
                k=k+1;
            }
            else{
                a[k]=nums1[i];
                i=i+1;
                k=k+1;
                a[k]=nums2[j];
                j=j+1;
                k=k+1;
            }
        }
        if(i==m)
        {
            while(j!=n)
            {
                a[k]=nums2[j];
                k=k+1;
                j=j+1;
            }
        }
        if(j==n)
        {
            while(i!=m)
            {
                a[k]=nums1[i];
                k=k+1;
                i=i+1;
            }
        }
        for(i=0;i<(m+n);i++)
        {
            nums1[i]=a[i];
        }
        
}
void main()
{
int m,n;
//int nums1[m+n],nums2[n];
printf("enter number of elements in nums1:");
scanf("%d",&m);
printf("enter number of elements in nums2:");
scanf("%d",&n);
int nums1[m+n],nums2[n];
printf("enter elements in nums1 in sorted order");
for(int i=0;i<m;i++)
{
scanf("%d",&nums1[i]);
}
printf("enter elements in nums2 in sorted order");
for(int i=0;i<n;i++)
{
scanf("%d",&nums2[i]);
}
merge(&nums1[0],sizeof(nums1)/sizeof(int),m,&nums2[0],sizeof(nums2)/sizeof(int),n);
printf("[");
for(int i=0;i<(m+n);i++)
{
printf("%d,",nums1[i]);
}
printf("]");
}

output:
enter number of elements in nums1:3
enter number of elements in nums2:3
enter elements in nums1 in sorted order1
2
3
enter elements in nums2 in sorted order2
5
6
[1,2,2,3,5,6,]
