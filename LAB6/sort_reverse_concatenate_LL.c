#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Sort the list
void sortList(struct Node *head) {
    struct Node *i, *j;
    int temp;

    if (head == NULL)
        return;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Reverse list
struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Concatenate 2 lists
struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    struct Node *temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    int choice, val;

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Insert into List1\n");
        printf("2. Insert into List2\n");
        printf("3. Display Lists\n");
        printf("4. Sort List1\n");
        printf("5. Reverse List1\n");
        printf("6. Concatenate List2 to List1\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(&list1, val);
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(&list2, val);
            break;

        case 3:
            printf("\nList1: ");
            display(list1);
            printf("List2: ");
            display(list2);
            break;

        case 4:
            sortList(list1);
            printf("List1 sorted.\n");
            break;

        case 5:
            list1 = reverseList(list1);
            printf("List1 reversed.\n");
            break;

        case 6:
            list1 = concatenate(list1, list2);
            printf("Lists concatenated into List1.\n");
            break;

        case 7:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
