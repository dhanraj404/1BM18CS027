//Queue operations
#include<stdio.h>
#include<stdlib.h>
#define size 10
void insert(int e,int q[],int *r)
{
    if(*r==size-1)
    {
        printf("Queue Overflow.\n");
    }
    else
    {
        *r=*r+1;
        q[*r]=e;
    }
}
void display(int q[],int f,int r)
{
    int i;
    if(f>r)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Elements in queue are:\n");
    for(i=f;i<=r;i++)
    {
        printf("%d\n",q[i]);
    }
    }
}
int delete(int q[],int *f)
{
    int item;
    item=q[*f];
    *f=*f+1;
    return item;
}
int main()
{
    int queue[10],front=0,rear=-1,option,n,i,element;
    while(1)
    {
        printf("1.Insert\n2.Deletion\n3.Display\n4.Exit\n");
        printf("Enter option:\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: printf("Enter no of elements to be inserted:\n");
                    scanf("%d",&n);
                    printf("Enter the elements:");
                    for(i=0;i<n;i++)
                    {
                        scanf("%d",&element);
                        insert(element,queue,&rear);
                    }
                    display(queue,front,rear);
                    break;
            case 2: if(front<=rear)
                    {
                        printf("Enter no of elements to be deleted\n");
                        scanf("%d",&n);
                       if(front+n<=rear+1)
                        {
                                for(i=1;i<=n;i++)
                            {
                                element=delete(queue,&front);
                                printf("The deleted element is : %d\n",element);
                            }
                            display(queue,front,rear);
                        }
                        else
                            printf("No of elements to b deleted are greater than those present in queue\n");
                    }
                    else
                        printf("Queue is empty\n");
                    break;
            case 3: display(queue,front,rear);
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid Input\n");
                    break;

        }
    }
    return 0;
}
/*
bmsce@bmsce-Precision-T1700:~/1BM18CS027$ gcc Queue.c
bmsce@bmsce-Precision-T1700:~/1BM18CS027$ ./a.out
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
1
Enter no of elements to be inserted:
2
Enter the elements:1
2
Elements in queue are:
1
2
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
2
Enter no of elements to be deleted
2
The deleted element is : 1
The deleted element is : 2
Queue is empty.
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
3
Queue is empty.
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
4
*/
