#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node* NODE;

NODE getnode() {
NODE p;
p =(NODE) malloc (sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("mory allocation failed!\n");
exit(0);
}
}

NODE insert(NODE head,int ele){
NODE p,q;
q = getnode();
q->data=ele;
q->next = NULL;
if(head == NULL)
return q;
p = head;
while(p->next!=NULL)
{
p = p->next;
}
p->next = q;
}

void sort(NODE head)
{
NODE p=head,q=NULL;
int temp;
if(head == NULL)
{
return;
}
while(p->next!=NULL)
{
q = p->	next;
while(q!=NULL)
{
if(p->data>q->data)
{
temp= p->data;
p->data = q->data;
q->data = temp;
}
q=q->next;
}
p=p->next;
}
}

NODE reverse(NODE head)
{
NODE curr = head,prev = NULL,nextn = NULL;
if(head == NULL)
{
printf("LIST IS EMPTY!\n");
return head;
}

if(head->next ==NULL)
return head;
while (curr!=NULL)
{
nextn = curr->next;
curr->next = prev;
prev = curr;
curr = nextn;
}
head = prev;
return head;
}

NODE concatinate(NODE head1, NODE head2)
{
NODE temp = head1;
if (head1 == NULL)
return head2;
if(head2 == NULL)
return head1;
while(temp->next!=NULL)
{
temp = temp->next;
}
temp->next=head2;
return head1;
}

void display(NODE head)
{
NODE p;
if(head == NULL)
{
printf("LIST IS EMPTY!\n");
exit(0);
}
p = head;
while(p!=NULL)
{
printf("%d\n",p->data);
p = p->next;
}
}

int main()
{
int n,ele,ele1,n1,i,ch;
NODE head = NULL, head1=NULL;
while(1){
printf("1.Insert\n2.Sort\n3.Concatinate\n4.Display\n5.Reverse\n6.Exit\n");
scanf("%d",&n);
switch(n)
{
case 1: printf("Enter the element:\n");
	scanf("%d",&ele);
	head = insert(head,ele);
	break;
case 2: sort(head);
	break;
case 3: printf("Enter the number of elements in the 2nd list:\n");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
	printf("Enter the ele %d:\n",i+1);
	scanf("%d",&ele1);
	head1 = insert(head1,ele1);
	}
	head = concatinate(head,head1);
	break;
case 4: display(head);
	break;
case 5: head= reverse(head);
	break;
default: printf("INVALID ENTRY!\n");
}
}
return 1;
}
  
