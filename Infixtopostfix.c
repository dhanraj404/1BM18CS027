#include<stdio.h>
#include<ctype.h>
void push(char c,int *t,char s[20]);
char pop(int *t,char s[20]);
void main()
{
	char stack[20];
	int top = -1;
	char exp[20];
	char *e, x;
	int check=0;
	printf("Enter the expression :: ");
	scanf("%s",exp);
	e = exp;
	printf("Postfix expression:: ");
    	while(*e != '\0')
	{
		check=isalnum(*e);
        	if(check==1)
            		printf("%c",*e);
        	else if(*e == '(')
			push(*e,&top,stack);
		else if(*e == ')')
        	{
			while((x = pop(&top,stack)) != '(')
                		printf("%c", x);
        	}
		else
		{
            		while(priority(stack[top]) >= priority(*e))
				printf("%c",pop(&top,stack));
			push(*e,&top,stack);
        	}
        	e++;
    	}
    	while(top != -1)
    	{
		printf("%c",pop(&top,stack));
    	}
	printf("\n");
}
void push(char c,int *t,char s[20])
{
	if(*t==19)
	{
		printf("Stack Overflow");
		return;
	}
	s[++(*t)] = c;
}
char pop(int *t,char s[20])
{
	if((*t) == -1)
		return -1;
	else
		return s[(*t)--];
}
int priority(char x)
{
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
}
