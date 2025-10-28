#include <stdio.h>
#include <stdlib.h>


//creating a struct node
typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right; 
} Node ;

Node* root=NULL;
//creating a root node
Node* create(int value){
	Node* node=(Node*)malloc(sizeof(Node));
	node->value=value;
	node->left=node->right=NULL;
	return node;
}

Node* insert(Node* root, int value){
	if (root==NULL)
		return create(value);
	if (value < (root->value))
		root->left=insert(root->left,value);
	else if (value > (root->value))
		root->right=insert(root->right,value);
	return root;
}

Node* minimum(Node* root){
	while(root && root->left != NULL)
		root=root->left;
	return root;
}

Node* Delete(Node* root, int value){
	if (root==NULL)
		return NULL;
	if (value < (root->value))
		root->left=Delete(root->left,value);
	else if (value > (root->value))
		root->right=Delete(root->right,value);
	else{
		if (root->left==NULL){
			Node*temp=root->right;
			free(root);
			return temp;
		}
		else if (root->right==NULL){
			Node* temp=root->left;
			free(root);
			return temp;
		}
		Node* temp=minimum(root->right);
		root->value=temp->value;
		root->right=Delete(root->right,temp->value);
	}
	return root;
}

void inorderTraversal(Node* root){
	if (root){
		inorderTraversal(root->left);
		printf("%d ",root->value);
		inorderTraversal(root->right);
	}
}

void postorderTraversal(Node* root){
	if (root){
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->value);	
	}
}

void preorderTraversal(Node* root){
	if (root){
		printf("%d ",root->value);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}
int main(){
	int value,choice;
	printf("\nBINARY TREE OPERATION");
	printf("\n+++++++++++++++++++++");
	printf("\n1. CREATE\n2. INSERT\n3. DELETE\n4. PREORDER TRAVERSAL\n5. INORDER TRAVERSAL\n6. POSTORDER TRAVERSAL \n7. EXIT");
	while(1){
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("Enter value : ");
				 scanf("%d",&value);
				 create(value);
				 break;
			case 2 : printf("Enter value to insert : ");
				 scanf("%d",&value);
				 root=insert(root,value);
				 break;
			case 3 : printf("Enter value to delete : ");
				 scanf("%d",&value);
				 root=Delete(root,value);
				 break;

			case 4 : printf("PREORDER TRAVERSAL : ");
				  preorderTraversal(root);
				  printf("\n__________________");
				  break;
			case 5 : printf("INORDER TRAVERSAL : ");
				  inorderTraversal(root);
				  printf("\n__________________");
				  break;
			case 6 : printf("POSTORDER TRAVERSAL : ");
				  postorderTraversal(root);
				  printf("\n__________________");
				  break;
			case 7 : printf("Exiting Program.....................\n");
				 exit(0);
			default : printf("Enter a valid choice.");
			printf("\n__________________");
		}
		
	}
	return 0;
}
