/*Name: Monish Khan
Roll no: 24051636*/
#include <stdio.h>
#include <stdlib.h>
struct cll {
    int data;
    struct cll* next;
};
struct cll* head = NULL;

// Create n nodes in circular linked list
void createList(int n){
    struct cll *temp, *newNode;
    int value, i;
    head = NULL;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct cll*)malloc(sizeof(struct cll));
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

// Traverse the circular linked list
void traverse(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct cll* temp = head;
    printf("Circular linked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Count nodes in the circular linked list
int countnodes() {
    if (head == NULL) {
        printf("List is empty.\n");
        return 0;
    }
    int count = 0;
    struct cll* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at position
void insert(int data, int pos){
    struct cll* newNode = (struct cll*)malloc(sizeof(struct cll));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
        return;
    }
    if (pos == 1){
        struct cll* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    } else {
        struct cll* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Delete at position
void delete(int pos){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1){
        struct cll* temp = head;
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct cll* temp2 = head;
            while (temp2->next != head) {
                temp2 = temp2->next;
            }
            head = head->next;
            temp2->next = head;
            free(temp);
        }
        return;
    }
    struct cll* temp = head;
    for (int i = 1; i < pos -1 && temp->next != head; i++) {
        temp = temp->next;
    }
    if (temp->next == head || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct cll* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

// Search element
void search(int n){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct cll* temp = head;
    int pos = 1;
    do {
        if (temp->data == n) {
            printf("Element %d found at position %d.\n", n, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found in the list.\n", n);
}

// Sort list (Bubble sort)
void sortlist(){
    if (head == NULL || head->next == head) return;
    int swapped;
    struct cll *ptr1, *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        do {
            struct cll* ptr2 = ptr1->next;
            if (ptr2 == head) break;
            if (ptr1->data > ptr2->data) {
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != lptr);
        lptr = ptr1;
    } while (swapped);
    printf("List sorted in ascending order\n");
}

// Reverse the circular list
void reverselist(){
    if (head == NULL || head->next == head) return;
    struct cll *prev = NULL, *current = head, *nextNode;
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    head->next = prev;
    head = prev;
    printf("List reversed\n");
}

// Find middle node
void findmiddle(){
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct cll *slow = head, *fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

// Insert at beginning
void insertfn(int data){
    insert(data, 1);
    printf("Node inserted at the beginning.\n");
}

// Insert at last
void insertln(int data){
    int length = countnodes();
    insert(data, length + 1);
    printf("Node inserted at the end.\n");
}

// Delete first node
void deletefn(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct cll* last = head;
    while (last->next != head) {
        last = last->next;
    }
    struct cll* temp = head;
    last->next = head->next;
    head = head->next;
    free(temp);
    printf("First node deleted\n");
}

// Delete last node
void deleteln() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        printf("Last node deleted\n");
        return;
    }
    struct cll* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct cll* lastNode = temp->next;
    temp->next = head;
    free(lastNode);
    printf("Last node deleted\n");
}

int main(){
    int choice, n, data, pos;
    do {
        printf("\n-----MENU-----\n");
        printf("1. Create List\n2. Insert\n3. Delete\n4. Count nodes\n5. Traverse\n6. Search\n7. Sort\n8. Reverse\n9. Middle Node\n10. Insert at Beginning\n11. Insert at Last\n12. Delete First Node\n13. Delete Last Node\n14. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
            insert(data, pos);
            break;
            case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delete(pos);
            break;
            case 4:
            printf("Node count: %d\n", countnodes());
            break;
            case 5:
            traverse();
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
    } while (choice!=14);
    return 0;
}