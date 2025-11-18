//Program 1:WAP to Implement Singly Linked List with following operations
//a) Create a linked list.
//b) Deletion of first element, specified element and last
//element in the list.
//c) Display the contents of the linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("\nNode inserted at beginning\n");
}

void deleteNodeAtBeg(struct Node** head) {
    struct Node* ptr;
    if (*head == NULL) {
        printf("\nList is empty\n");
    } else {
        ptr = *head;
        *head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning\n");
    }
}

void deleteNodeAtEnd(struct Node** head) {
    struct Node *ptr, *ptr1;

    if (*head == NULL) {
        printf("\nList is empty\n");
    } else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("\nThe only node of the list deleted\n");
    } else {
        ptr = *head;
        while (ptr->next != NULL) {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nNode deleted successfully from end\n");
    }
}

void deleteAtPos(struct Node** head, int pos) {
    if (*head == NULL) {
        printf("\nList is empty\n");
        return;
    }

    struct Node *ptr = *head, *prev;
    int i;

    if (pos == 1) {
        *head = ptr->next;
        free(ptr);
        printf("\nNode deleted from position 1\n");
        return;
    }

    for (i = 1; ptr != NULL && i < pos; i++) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    prev->next = ptr->next;
    free(ptr);
    printf("\nNode deleted from position %d\n", pos);
}

void display(struct Node* head) {
    struct Node* temp = head;

    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Insert Node at Beginning\n");
        printf("2. Delete Node at Beginning\n");
        printf("3. Delete from End\n");
        printf("4. Delete at a Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                deleteNodeAtBeg(&head);
                break;
            case 3:
                deleteNodeAtEnd(&head);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPos(&head, pos);
                break;
            case 5:
                display(head);
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
