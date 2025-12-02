#include <stdio.h>
#include <stdlib.h>

typedef struct BST {
    int data;
    struct BST *right, *left;
} node;

node* create() {
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, node* temp) {
    if (root == NULL)
        return temp;

    if (temp->data < root->data)
        root->left = insert(root->left, temp);

    else if (temp->data > root->data)
        root->right = insert(root->right, temp);

    return root;
}

void inorder(node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node* root) {
    if(root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    node* root = NULL;
    int choice;

    while(1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert element\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = insert(root, create());
                break;

            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
