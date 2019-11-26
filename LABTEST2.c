// Function to reverse the circular linked list 
void reverse(Node** head_ref) 
{ 
    // if list is empty 
    if (*head_ref == NULL) 
        return; 
  
    // reverse procedure same as reversing a 
    // singly linked list 
    Node* prev = NULL; 
    Node* current = *head_ref; 
    Node* next; 
    do { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } while (current != (*head_ref)); 
  
    // adjutsing the links so as to make the 
    // last node point to the first node 
    (*head_ref)->next = prev; 
    *head_ref = prev; 
} 

//SORT CLL

void sortList() {  
//Current will point to head  
struct node *current = head, *index = NULL;  
int temp;  
if(head == NULL) {  
printf("List is empty");  
}  
else {  
do{  
//Index will point to node next to current  
index = current->next;  
while(index != head) {  
//If current node is greater than index data, swaps the data  
if(current->data > index->data) {  
temp =current->data;  
current->data= index->data;  
index->data = temp;  
}  
index= index->next;  
}  
current =current->next;  
}while(current->next != head);   
}  
}  

//CONCAT TWO CLL

struct node *merge(struct node *p, struct node *q)
{
    struct node *temp = NULL;
    struct node *r = NULL;
    r = p;
    temp = p;
    while (temp->link != p)
        temp = temp->link;
    temp->link = q;
    temp = q;
    while (temp->link != q)
        temp = temp->link;
    temp->link = r;
    return (r);
}

//MIN MAX

void printMinMax(struct Node** head) 
{ 
    // check list is empty 
    if (*head == NULL) { 
        return; 
    } 
  
    // pointer for traversing 
    struct Node* current; 
  
    // initialize head to current pointer 
    current = *head; 
  
    // initialize max int value to min 
    // initialize min int value to max 
    int min = INT_MAX, max = INT_MIN; 
  
    // While last node is not reached 
    while (current->next != *head) { 
  
        // If current node data is lesser for min 
        // then replace it 
        if (current->data < min) { 
            min = current->data; 
        } 
  
        // If current node data is greater for max 
        // then replace it 
        if (current->data > max) { 
            max = current->data; 
        } 
  
        current = current->next; 
    } 
  
    cout << "\nMinimum = " << min << ", Maximum = " << max; 
} 

//
// C code to implement Priority Queue 
// using Linked List 
#include <stdio.h> 
#include <stdlib.h> 

// Node 
typedef struct node { 
	int data; 

	// Lower values indicate higher priority 
	int priority; 

	struct node* next; 

} Node; 

// Function to Create A New Node 
Node* newNode(int d, int p) 
{ 
	Node* temp = (Node*)malloc(sizeof(Node)); 
	temp->data = d; 
	temp->priority = p; 
	temp->next = NULL; 

	return temp; 
} 

// Return the value at head 
int peek(Node** head) 
{ 
	return (*head)->data; 
} 

// Removes the element with the 
// highest priority form the list 
void pop(Node** head) 
{ 
	Node* temp = *head; 
	(*head) = (*head)->next; 
	free(temp); 
} 

// Function to push according to priority 
void push(Node** head, int d, int p) 
{ 
	Node* start = (*head); 

	// Create new Node 
	Node* temp = newNode(d, p); 

	// Special Case: The head of list has lesser 
	// priority than new node. So insert new 
	// node before head node and change head node. 
	if ((*head)->priority > p) { 

		// Insert New Node before head 
		temp->next = *head; 
		(*head) = temp; 
	} 
	else { 

		// Traverse the list and find a 
		// position to insert new node 
		while (start->next != NULL && 
			start->next->priority < p) { 
			start = start->next; 
		} 

		// Either at the ends of the list 
		// or at required position 
		temp->next = start->next; 
		start->next = temp; 
	} 
} 

// Function to check is list is empty 
int isEmpty(Node** head) 
{ 
	return (*head) == NULL; 
} 

// Driver code 
int main() 
{ 
	// Create a Priority Queue 
	// 7->4->5->6 
	Node* pq = newNode(4, 1); 
	push(&pq, 5, 2); 
	push(&pq, 6, 3); 
	push(&pq, 7, 0); 

	while (!isEmpty(&pq)) { 
		printf("%d ", peek(&pq)); 
		pop(&pq); 
	} 

	return 0; 
} 


//
