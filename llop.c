#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node * NODE;
NODE insert_front(int item,NODE head);
void display(NODE head);
NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
		return p;
	else
	{
		printf("Memory could not be allocated\n");
		exit(0);
	}
}
NODE insert_front(int item,NODE head)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head;
	head=p;
	return head;
}
void display(NODE head)
{
	NODE p;
	if(head==NULL)
	{
		printf("list is empty\n");
		exit(0);
	}
	p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
NODE sort(NODE head)
{
	NODE p=head;
	NODE q=NULL;
	int temp;
	if(head==NULL)
		return head;
	while(p->next!=NULL)
	{
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
	}
	return head;
}
NODE reverse(NODE head)
{
	NODE curr=head;
	NODE prev=NULL;
	NODE nextn=NULL;
	if(head==NULL)
	{
		printf("list is empty\n");
		return head;
	}
	if(head->next==NULL)
		return head;
	while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
	}
	head=prev;
	return head;
}
NODE concatenate(NODE h1,NODE h2)
{
	NODE p=h1;
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=h2;
	return h1;
}
int main()
{
	NODE head1=NULL;
	NODE head2=NULL;
	int ch,item,n,i;
	printf("enter\n1.Insertion list1\n2.Insertion list2\n3.Sorting in list1\n4.Reversing list1\n5.Sorting list2\n6.Reverseing list2\n7.Concatenate\n8.Display list1\n9.Display list2\n10.exit\n");
	scanf("%d",&ch);
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:printf("enter the no. of elements\n");
				scanf("%d",&n);
				printf("enter the items to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					head1=insert_front(item,head1);
				}
				break;
			case 2:printf("enter the no. of elements\n");
				scanf("%d",&n);
				printf("enter the items to be inserted\n");
				for(i=0;i<n;i++)
				{
					scanf("%d",&item);
					head2=insert_front(item,head2);
				}
				break;
			case 3:head1=sort(head1);
				break;
			case 4:head1=reverse(head1);
				break;
			case 5:head2=sort(head2);
				break;
			case 6:head2=reverse(head2);
				break;
			case 7:head1=concatenate(head1,head2);
				break;
			case 8:display(head1);
				break;
			case 9:display(head2);
				break;
			default:printf("invalid input check for unavailability\n");
		}
		printf("enter next choice or '0' to exit\n");
		scanf("%d",&ch);
	}
	return 0;
}
/*
enter
1.Insertion list1
2.Insertion list2
3.Sorting in list1
4.Reversing list1
5.Sorting list2
6.Reverseing list2
7.Concatenate
8.Display list1
9.Display list2
10.exit
1
enter the no. of elements
4
enter the items to be inserted
10
40
30
20
enter next choice or '0' to exit
3
enter next choice or '0' to exit
4
enter next choice or '0' to exit
8
40
30
20
10
enter next choice or '0' to exit
2
enter the no. of elements
2
enter the items to be inserted
50
60
enter next choice or '0' to exit
7
enter next choice or '0' to exit
8
40
30
20
10
60
50
enter next choice or '0' to exit
*/
