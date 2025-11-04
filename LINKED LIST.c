#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void createList(struct Node**head, int n)
{
    struct Node* newNode, *temp;
    int data, i;
    if(n<=0)
    {
        printf("List size must be greater than zero\n");
        return;
    }
    *head = NULL;
    for(i=0;i<n;i++)
    {
        newNode= (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d :", i+1);
        scanf("%d", &data);
        newNode->data=data;
        newNode->next=NULL;
    }
    if(*head==NULL)
    {
        *head= newNode;
    }else{
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            temp->next=newNode;
        }
    }
    printf("\nLinked List formed successfully\n");
}


void insertAtBeginning(struct Node** head, int data)
{
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=*head;
    *head=newNode;
    printf("\nNode inserted at beginning\n");
}



void insertAtPosition(struct Node** head, int data, int position) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at position 1.\n");
        return;
    }

    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// Insert node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("Node inserted as the first element.\n");
        return;
    }

    temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at end.\n");
}

void displayList(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, n, data, position;

    while (1) {
        printf("\nSingly Linked List Menu\n");
        printf("1. Create a linked list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at any position\n");
        printf("4. Insert at end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes to create: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (starting from 1): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
