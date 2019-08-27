#include<stdio.h>
#include<string.h>
void push(char ele,char s[100],int *t);
char pop(char s[100],int *t);
int pre(char ele);
void push(char ele,char s[100],int *t)
{
	if(*t==99)
	{
		printf("stack overflow\n");
	}
	else
		s[++(*t)]=ele;
}
char pop(char s[100],int *t)
{
	if(*t==-1)
		return -3;
	else
		return s[(*t)--];
}
int pre(char ele)
{
	if(ele=='^')
	return 3;
	else if(ele=='*'||ele=='/')
	return 2;
	else if(ele=='+'||ele=='-')
	return 1;
}
int main()
{
	char stack[100],infix[100];
	char e;
	int top=-1;
	printf("Enter the infix expression");
        scanf("%s",infix);
	infix[strlen(infix)]='\0';
	int i=0;
	int j;
	while(infix[i]!='\0')
	{
		if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z'))
			printf("%c",infix[i]);
		else if(infix[i]=='(')
			push(infix[i],stack,&top);
		else if(infix[i]==')')
		{
			while((e=pop(stack,&top))!='(')
				printf("%c",e);
		}
		else
		{
			if(pre(stack[top])>=pre(infix[i]))
				push(infix[i],stack,&top);
			else
			{
				while(pre(stack[top])>=pre(infix[i]))
					e=pop(stack,&top);
				push(infix[i],stack,&top);
			}
		}
		i++;
	}
	while(top!=-1)
	{
		printf("%c",pop(stack,&top));
	}
	return 0;
}
				

