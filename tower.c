#include<stdio.h>
void tower_Hanoi(int n, char from, char to, char aux) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from, to); 
        return; 
    } 
    tower_Hanoi(n-1, from, aux, to); 
    printf("\n Move disk %d from rod %c to rod %c", n, from, to); 
    tower_Hanoi(n-1, aux, to, from); 
} 
  
int main() 
{ 
    int n;
    printf("Enter no of disks:");
    scanf("%d",&n);
    tower_Hanoi(n, 'A', 'C', 'B');  // A, B and C are names of towers 
        printf("\n");
	printf("Disks moved from A to C\n");
    return 0; 
} 
