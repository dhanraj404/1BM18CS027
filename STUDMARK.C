#include <stdio.h>
struct student
{
int s1,s2,s3;
}s;
void main()
{
    clrscr();
    fflush(stdin);
    printf("Enter Marks of all 3 subjects :");
    scanf("%d,%d,%d",&s.s1,&s.s2,&s.s3);
    printf(" SUB 1 Marks: %d \n",s.s1);
    printf(" SUB 2 Marks: %d \n",s.s2);
    printf(" SUB 3 Marks: %d \n",s.s3);
    getch();

}