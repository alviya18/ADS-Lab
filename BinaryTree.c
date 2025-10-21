#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Function to build tree interactively
struct Node* createTree() {
    int value, choice;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node* newNode = createNode(value);

    printf("Does %d have a left child? (1.Yes 0.No): ", value);
    scanf("%d", &choice);
    if (choice == 1)
        newNode->left = createTree();

    printf("Does %d have a right child? (1.Yes 0.No): ", value);
    scanf("%d", &choice);
    if (choice == 1)
        newNode->right = createTree();

    return newNode;
}

// Tree traversals
void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice;

    while (1) {
        printf("\n1.Create \n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n5.Height\n6.Count\n7.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Create Binary Tree ---\n");
                root = createTree();
                break;
            case 2:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of the Tree: %d\n", height(root));
                break;
            case 6:
                printf("No. of nodes: %d\n", countNodes(root));
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
