#include<stdio.h>
#include<stdlib.h>
struct node
{
int val;
struct node *next;
};
typedef struct node node;
node* create(node *head)
{
node *new,*prev;
int x;
printf("enter data in ascending order,enter -1 to end");
scanf("%d",&x);
while(x!=-1)
{
new=(node*)malloc(sizeof(node));
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
void display(node* head)
{
node *temp=head;
if(temp==NULL)
{
printf("[]\n");
}
else
{
printf("[");
while(temp!=NULL)
{
printf("%d,",temp->val);
temp=temp->next;
}
printf("]\n");
}
}
node* add(node* l,node* new)
{
if(l==NULL)
{
l=new;
}
else
{
node* temp=l;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=new;
}
return l;
}
node* mergeSort(node* l1,node* l2)
{
node *new,*l3=NULL;
if(l1==NULL && l2==NULL)
{
return l1;
}
else
{
while(l1!=NULL && l2!=NULL)
{
new=(node*)malloc(sizeof(node));
new->next=NULL;
if(l1->val<=l2->val)
{
new->val=l1->val;
l3=add(l3,new);
l1=l1->next;
}
else
{
new->val=l2->val;
l3=add(l3,new);
l2=l2->next;
}
}
if(l1==NULL)
{
while(l2!=NULL)
{
new=(node*)malloc(sizeof(node));
new->val=l2->val;
new->next=NULL;
l3=add(l3,new);
l2=l2->next;
}
}
if(l2==NULL)
{
while(l1!=NULL)
{
new=(node*)malloc(sizeof(node));
new->val=l1->val;
new->next=NULL;
l3=add(l3,new);
l1=l1->next;
}
}
return l3;
}
}
void main()
{
node *list1=NULL,*list2=NULL,*res;
list1=create(list1);
display(list1);
list2=create(list2);
display(list2);
res=mergeSort(list1,list2);
display(res);
}

output:
enter data in ascending order,enter -1 to end1
enter data in ascending order,enter -1 to end2
enter data in ascending order,enter -1 to end4
enter data in ascending order,enter -1 to end-1
[1,2,4,]
enter data in ascending order,enter -1 to end1
enter data in ascending order,enter -1 to end3
enter data in ascending order,enter -1 to end4
enter data in ascending order,enter -1 to end-1
[1,3,4,]
[1,1,2,3,4,4,]
