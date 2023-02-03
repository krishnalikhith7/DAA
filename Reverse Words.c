#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char * reverseWords(char * s){
    int n=strlen(s);
    char stack[n];
    char *r=malloc(n+1);
    char ch;
    int top=-1,k=0;
   for(int i=n-1;i>=0;i--)
    {
        ch=s[i];
        if(ch!=' ')
        {
            stack[++top]=ch;
        }
        else if(ch==' ' && top!=-1)
        {
            while(top>=0)
            {
                r[k]=stack[top];
                k++;
                top--;
            }
            r[k++]=' ';
        }
            
    }
    if(top!=-1)
    {
        while(top>=0)
        {
            if(stack[top]!=' ')
            {
            r[k]=stack[top];
            k++;
            top--;
            }
        }
    }
    if(s[0]==' ')
    {
        r[k-1]='\0';
    }
    r[k]='\0';
    return r;
}
void main()
{
char *s;
printf("Enter String");
scanf("%[^\n]",s);
char *r=reverseWords(s);
printf("After reversing words Resulting string is:\n%s",r);
}

output:
Enter String  hello world
After reversing words Resulting string is:
world hello
