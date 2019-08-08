//Program 3
#include<stdio.h>
#include<conio.h>
struct student
{
  int id,age,marks;
};
int main()
{
    struct student s[100];
    int i,n;
    printf("Enter the no. of Students :\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the ID,Age and Marks of Student :%d\n",i+1);
        scanf("%d %d %d",&s[i].id,&s[i].age,&s[i].marks);            // Getting data from user
        if(s[i].age>20 && s[i].marks>=0 && s[i].marks<=100)       //validating
        {
          printf("Data is valid :\n");
        if(s[i].marks>=65)                                      //Checking Eligibility
        {
          printf("Student is eligible\n");
        }
        else
          printf("Student is not eligible\n");
        }
        else
        {
          printf("Data is invalid\n");

        }
     }
    getch();
    return 0;
}
