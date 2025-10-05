/*Name: Monish Khan
Roll no: 24051636*/
#include <stdio.h>
#include <stdlib.h>
struct sll{
    int data;
    struct sll * next;
};
struct sll* head = NULL;

// Function to create n nodes in the linked list
void createList(int n) {
    struct sll *temp, *newNode;
    int value, i;
    head = NULL;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct sll*)malloc(sizeof(struct sll));
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Traverse the linked list and print elements
void traverse() {
    struct sll * temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes in the linked list
int countnodes() {
    struct sll * temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert a node at a specific position
void insert(int data, int pos) {
    struct sll* newNode = (struct sll*)malloc(sizeof(struct sll));
    newNode->data = data;
    newNode->next = NULL;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct sll* temp = head;
    for (int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete a node from a specific position (1-based)
void delete(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct sll *temp = head, *prev;
    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}

//To Search an element in the linked list
void search(int n) {
    struct sll *temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == n) {
            printf("Element %d found at position %d.\n", n, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found in the list.\n", n);
}

//To sort the elements in ascending order
void sortlist() {
    struct sll *i, *j;
    int temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order\n");
}

//Reverse the linked list
void reverselist() {
    struct sll* prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed\n");
}

//Middle node
void findmiddle() {
    struct sll* mid = head, *last = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (last != NULL && last->next != NULL) {
        mid = mid->next;
        last = last->next->next;
    }

    printf("Middle element is: %d\n", mid->data);
}

//Insert a node at beginning
void insertfn(int data){
    struct sll* newnode= (struct sll*)malloc(sizeof(struct sll));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("Node inserted at the beginning.\n");
}

//Insert a node at the end
void insertln(int data){
    struct sll *newnode=(struct sll*)malloc(sizeof(struct sll));
    if(newnode==NULL){
        printf("Memory allocation failed!.\n");
        return;
    }
    newnode->data= data;
    newnode->next= NULL;
    if(head==NULL){
        head=newnode;
    } else {
        struct sll *temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next= newnode;
    }
    printf("Node inserted at the end.\n");
}

//Delete the fisrt node
void deletefn(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    struct sll *temp=head;
    head= head->next;
    free(temp);
    printf("First Node deleted.\n");
}

//Delete the last node
void deleteln() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }
    struct sll *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct sll *lastnode = temp->next;
    temp->next = NULL;
    free(lastnode);
    printf("Last node deleted\n");
}

int main()
{
    int choice,n,data,pos;
    do{
        printf("\n-----MENU-----\n");
        printf("1. Create List\n2. Insert\n3. Delete\n4. Count nodes\n5. traverse\n6. Search\n7. Sort\n8. Reverse\n9. Middle Node\n10. Insert at Beginning\n11. Inset at Last\n12. Delete First Node\n13. Delete Last Node\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
            printf("Enter the number of nodes: ");
            scanf("%d", &n);
            createList(n);
            break;
            case 2:
            printf("Enter the number to insert: ");
            scanf("%d", &data);
            printf("Enter the position: ");
            scanf("%d", &pos);
            insert(data,pos);
            break;
            case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delete(pos);
            break;
            case 4:
            printf("Node count: %d", countnodes());
            printf("\n");
            break;
            case 5:
            traverse();
            printf("\n");
            break;
            case 6:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            search(data);
            break;
            case 7:
            sortlist();
            break;
            case 8:
            reverselist();
            break;
            case 9:
            findmiddle();
            break;
            case 10:
            printf("Enter number to insert at Beginning: ");
            scanf("%d", &data);
            insertfn(data);
            break;
            case 11:
            printf("Enter number to insert at last: ");
            scanf("%d", &data);
            insertln(data);
            break;
            case 12:
            deletefn();
            break;
            case 13:
            deleteln();
            break;
            case 14:
            printf("Exiting\n");
            break;
            default:
            printf("Invalid choice!\n");
        }
    }while (choice!=14);
    return 0;
}