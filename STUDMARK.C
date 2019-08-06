#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks[3];
} s;
int main()
{
    int i;
    printf("Enter information of students:\n");
    // storing information
    printf("\nEnter roll number :\n");
    scanf("%d",&s.roll);
    printf("Enter name: ");
    scanf("%s",s.name);
    for(i=0; i<3;i++)
    {
        printf("Enter marks of subject %d: ",i+1);
        scanf("%f",&s.marks[i]);
        printf("\n");
    }
    printf("Displaying Information:\n\n");
    // displaying information
        printf("\nRoll number: %d\n",s.roll);
        printf("Name: %s \n",s.name);

    for(i=0; i<3; i++)
    {
        printf("Marks of sub %d : %.1f",i+1,s.marks[i]);
        printf("\n");
    }
    return 0;
}
