#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node *NODE;

NODE getnode(int item) {
    NODE p = (NODE)malloc(sizeof(struct node));
    if(p!=NULL){
	p->data=item;
	p->left = NULL; 
     	p->right = NULL; 
    	return p;
	}
    else {
        printf("Memory allocation failed!\n");
        exit(0);
    }
}
NODE insert(NODE root,int item)
{
	if(root ==NULL)
		return getnode(item);
	if(item<root->data)
		root->left = insert(root->left,item);
	else if(item>root->data)
		root->right = insert(root->right,item);
	return root;
}
void inorder(NODE root){
	if(root == NULL)
	return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(NODE root){
	if(root == NULL)
	return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(NODE root){
	if(root == NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
int main(){
	NODE root = NULL;
	int ele,ch;
	for(;;){
	printf("\n----Enter your choice----\n");
	printf("1.Insert.\n2.Inorder Traversal.\n3.Preorder Traversal.\n4.Postorder Traversal.\n5.Exit:\n");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf("\nEnter the element:\n");
			scanf("%d",&ele);
			root = insert(root,ele);
			break;
		case 2: inorder(root);
			break;
		case 3: preorder(root);
			break;
		case 4: postorder(root);
			break;
		case 5: exit(1);
		default :printf("Invalid Choice");
		}
	}
}
/*
bmsce@bmsce-Precision-T1700:~/Desktop$ gcc btree.c
bmsce@bmsce-Precision-T1700:~/Desktop$ ./a.out

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
1

Enter the element:
1

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
1

Enter the element:
2

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
1

Enter the element:
3

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
1

Enter the element:
4

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
1

Enter the element:
5

----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
2
1	2	3	4	5	
----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
3
1	2	3	4	5	
----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
4
5	4	3	2	1	
----Enter your choice----
1.Insert.
2.Inorder Traversal.
3.Preorder Traversal.
4.Postorder Traversal.
5.Exit:
5
bmsce@bmsce-Precision-T1700:~/Desktop$ 
*/	





