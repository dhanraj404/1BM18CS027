//Stack implementaion using Linklist
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node* Node;

Node push(int ele, Node top)
{
    if (top == NULL)
    {
        top =(Node)malloc(sizeof(struct node));
        top->next = NULL;
        top->data = ele;
	return top;
    }
    else
    {
        Node temp =(Node)malloc(sizeof(struct node));
        temp->next = top;
        temp->data = ele;
        top = temp;
	return top;
    }
}
void display(Node top)
{
    Node t = top;

    if (t == NULL)
    {
        printf("Stack is empty");
        return;
    }
    printf(" Elements in the stack are:\n");
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
 }
Node pop(Node top)
{
    Node t = top;

    if (t == NULL)
    {
        printf("\nStack underflow");
        return top;
    }
    else
        t = t->next;
    printf("\n Popped element : %d", top->data);
    free(top);
    top = t;
    return top;
}

void main()
{
	int no, ch, e;
	Node top = NULL;
	while (1)
	{
		printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit");
		printf("\n Enter choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:printf(" Enter data : ");
			       scanf("%d", &no);
			       top = push(no, top);
			       break;
			case 2:top = pop(top);
			       break;
			case 3:display(top);
			       break;
			case 4:  exit(0);
			default :printf("Invalid Input");
				 break;
		}
	}	
}



