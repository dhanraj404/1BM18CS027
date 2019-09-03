#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 10
void insert(int e,int q[],int *r,int *f)
{
    if((*f==*r+1)||(*f==0&&*r==size-1))
    {
        printf("Queue Overflow. . .\n");
        return ;
    }
    else
    {
        if(*f==-1)
            *f=0;
        *r=(*r+1)%size;
        q[*r]=e;
    }
}
void display(int q[],int f,int r)
{
    int i;

    if(f==-1)
    {
        printf("Queue is empty. . .\n");
    }
    else
    {
        printf("Elements in queue are:\n");
        if(f<=r)
        {

            for(i=f;i<=r;i=(i+1))
            {
                printf("%d\n",q[i]);

            }

        }
        else
        {

            for(i=0;i<=r;i++)
            {
                printf("%d\n",q[i]);

            }
            for(i=f;i<=size-1;i++)
            {
                printf("%d\n",q[i]);

            }

        }
    }
}
int delete(int q[],int *f,int *r)
{
    int item;
    if(*f==-1)
        printf("Queue is empty. . .\n");
    else
    {
        item=q[*f];
        if(*f==*r)
        {
            *f=-1;*r=-1;
        }
        else
        {
            *f=(*f+1)%size;
        }
        return item;
    }
}
int main()
{
    int queue[10],front=-1,rear=-1,option,n,i,element;
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
                        insert(element,queue,&rear,&front);
                    }
                    display(queue,front,rear);
                    break;
            case 2: if(front!=-1)
                    {
                        printf("Enter no. of elements to be deleted\n");
                        scanf("%d",&n);
                       if((front+n<=rear+1)||((size-(front-rear-1))>=n)&&front>rear)
                        {
                                for(i=1;i<=n;i++)
                            {
                                element=delete(queue,&front,&rear);
                                printf("The deleted element is : %d\n",element);
                            }
                            display(queue,front,rear);
                        }

                        else
                            {
                                 printf("No. of elements to be deleted is more than the No. of elements in the queue:\n");
                            }
                        }
                    else
                        printf("Queue is empty\n");
                    break;
            case 3: display(queue,front,rear);
                    break;
            case 4: exit(0);
                    break;
            default:printf("Invalid option. . .");
                    break;
        }
    }
    return 0;
}
/*
bmsce@bmsce-Precision-T1700:~/1BM18CS027$ gcc Qcircle.c
bmsce@bmsce-Precision-T1700:~/1BM18CS027$ ./a.out
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
1
Enter no of elements to be inserted:
5
Enter the elements:1
2
3
4
5
Elements in queue are:
1
2
3
4
5
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
1
Enter no of elements to be inserted:
1
Enter the elements:6
Queue Overflow. . .
Elements in queue are:
1
2
3
4
5
1.Insert
2.Deletion
3.Display
4.Exit
Enter option:
2
Enter no. of elements to be deleted
3
The deleted element is : 1
The deleted element is : 2
The deleted element is : 3
Elements in queue are:
4
5
*/
