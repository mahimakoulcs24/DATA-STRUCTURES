#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head= NULL;
struct Node* createNode(int value)
{
    struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
    newNode-> data= value;
    newNode->next= NULL;
    newNode-> prev= NULL;
    return newNode;
};


void InsertToLeft(int val){
    struct Node* newNode= createNode(val);
    if(head==NULL){
        head= newNode;
        return;
    }
    else{
        newNode->next= head;
        head->prev= newNode;
        head=newNode;
    }
};
void DelNode(int key)
{
    struct Node* temp= head;

    while(temp!= NULL && temp-> data != key){
        temp= temp->next;
    }
    if(temp==NULL){
        printf("Value Not found!!\n");
        return;
    }

    if(temp->prev != NULL){
        temp->prev->next= temp->next;
    }else{
    head= temp->next;}

    if(temp->next != NULL){
        temp->next->prev= temp-> prev;
    }

    free(temp);
    printf("Deleted!\n");
}



void displayLL()
{
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d\t ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1.Insert in the left \n2.Delete a given value \n3.Display Linked List\n4.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            InsertToLeft(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            DelNode(value);
            break;
        case 3:
            displayLL();
            break;

        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}
