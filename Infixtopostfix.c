#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

int isoperator(char ch);
char pop(char a[40],int* t);
void push(char ele,char a[40],int* t);
int precedence(char ch);

char pop(char a[40],int* t)
{
    char g;
    if(*t>-1)
       {
        g=a[*t];
        *t-=1;
       }
   return g;
}
void push(char ele,char a[40],int* t)
{
    a[*t]=ele;
    *t+=1;
}
int isoperator(char ch)
{
    if(ch=='/'||ch=='+'||ch=='-'||ch=='*'||ch=='^')
         return 1;
    else
         return 0;
}
int precedence(char ch)
{
    switch(ch)
    {
    case '^':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}

int main()
{
    char stack[40],infix[20],postfix[20];
    printf("Enter the expression");
    scanf("%s",infix);
    int i=0,j=0,top=-1;
    char sym;
    while(infix[i]!='\0')
    {
        sym=infix[i];
        if(sym=='(')
        {
            push(sym,stack,&top);
        }
        else if(isdigit(sym)||isalpha(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(isoperator(sym)==1)
        {
            if(precedence(sym)>precedence(top))
            {
                push(sym,stack,&top);
            }
            else
                 postfix[j++]=sym;
        }
        else if(sym==')')
        {

            while(stack[top]!='(')
              {
                char x=pop(stack,&top);
                postfix[j++]=x;
              }
              if(stack[top]=='(')
              top--;
        }
        else
             printf("Invalid Input");

    }
     while(top!=-1)
     {
         char v=pop(stack,&top);
         postfix[j++]=v;
     }
     postfix[j]='\0';
     puts(postfix);
}
