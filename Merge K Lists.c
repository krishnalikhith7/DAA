#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode* create(struct ListNode *head)
{
struct ListNode *new,*prev;
int x;
printf("enter data in ascending order,enter -1 to end");
scanf("%d",&x);
while(x!=-1)
{
new=(struct ListNode*)malloc(sizeof(struct ListNode));
new->val=x;
new->next=NULL;
if(head==NULL)
{
head=new;
prev=new;
}
else
{
prev->next=new;
prev=new;
}
printf("enter data in ascending order,enter -1 to end");
scanf("%d",&x);
}
return head;
}
struct ListNode* mergesort(struct ListNode* l1,struct ListNode* l2)
 {
if(l1==NULL && l2==NULL)
{
    return NULL;
}
else if(l1==NULL)
{
    return l2;
}
else if(l2==NULL)
{
    return l1;
}
else
{
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *temp1=l1,*temp2=l2;
    struct ListNode *res=l3;
    if(temp1->val<temp2->val)
    {
        l3->val=temp1->val;
        temp1=temp1->next;
    }
    else{
        l3->val=temp2->val;
        temp2=temp2->next;
    }
while(temp1!=NULL && temp2!=NULL)
{
    if(temp1->val<=temp2->val)
    {
        res->next=temp1;
        res=temp1;
        temp1=temp1->next;
    }
    else
    {
        res->next=temp2;
        res=temp2;
        temp2=temp2->next;
    }
}
if(temp1!=NULL)
{
    while(temp1!=NULL)
    {
        res->next=temp1;
        res=temp1;
        temp1=temp1->next;
    }
}
if(temp2!=NULL)
{
    while(temp2!=NULL)
    {
        res->next=temp2;
        res=temp2;
        temp2=temp2->next;
    }
}
return l3;
 } 
 }
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)
    {
        return NULL;
    }
    else{

struct ListNode* res=lists[0];
for(int i=1;i<listsSize;i++)
{
    res=mergesort(res,lists[i]);
}
return res;
    }
}
void display(struct ListNode *head)
{
    struct ListNode* temp=head;
    printf("[");
    while(temp!=NULL)
    {
        printf("%d,",temp->val);
        temp=temp->next;
    }
    printf("]");
}
void main()
{
    int listsSize;
    printf("enter number of lists");
    scanf("%d",&listsSize);
    struct ListNode* lists[listsSize];
    struct ListNode *temp,*res;
    for(int i=0;i<listsSize;i++)
    {
        temp=NULL;
        temp=create(temp);
        lists[i]=temp;
    }
    res=mergeKLists(lists,listsSize);
    display(res);
}

output:
enter number of lists3
enter data in ascending order,enter -1 to end1
enter data in ascending order,enter -1 to end4
enter data in ascending order,enter -1 to end5
enter data in ascending order,enter -1 to end-1
enter data in ascending order,enter -1 to end1
enter data in ascending order,enter -1 to end3
enter data in ascending order,enter -1 to end4
enter data in ascending order,enter -1 to end-1
enter data in ascending order,enter -1 to end2
enter data in ascending order,enter -1 to end6
enter data in ascending order,enter -1 to end-1
[1,1,2,3,4,4,5,6,]
