#include <stdio.h>
#include <stdlib.h>
struct dcll {
    int data;
    struct dcll* next;
    struct dcll* prev;
};
struct dcll* head = NULL;

// Create n nodes in doubly circular linked list
void createList(int n){
    struct dcll *temp, *newNode;
    int value, i;
    head = NULL;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct dcll*)malloc(sizeof(struct dcll));
        newNode->data = value;
        if (head == NULL) {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        } else {
            temp = head->prev; // last node
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }
}

// Traverse the list forward
void traverse(){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct dcll* temp = head;
    printf("Doubly circular linked list: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Count nodes
int countnodes(){
    if (head == NULL) return 0;
    int count = 0;
    struct dcll* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Insert at position
void insert(int data, int pos){
    struct dcll* newNode = (struct dcll*)malloc(sizeof(struct dcll));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    int length = countnodes();
    if (pos < 1 || pos > length + 1) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    if (pos == 1) {
        struct dcll* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    } else {
        struct dcll* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        struct dcll* nextNode = temp->next;
        newNode->next = nextNode;
        newNode->prev = temp;
        temp->next = newNode;
        nextNode->prev = newNode;
    }
}

// Delete node at position (1-based)
void delete(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int length = countnodes();
    if (pos < 1 || pos > length) {
        printf("Position out of range\n");
        return;
    }
    struct dcll* temp = head;
    if (length == 1 && pos == 1) {
        free(head);
        head = NULL;
        return;
    }
    if (pos == 1) {
        struct dcll* last = head->prev;
        last->next = head->next;
        head->next->prev = last;
        struct dcll* toDelete = head;
        head = head->next;
        free(toDelete);
    } else {
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// Search element
void search(int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dcll* temp = head;
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
void sortlist() {
    if (head == NULL || head->next == head) {
        printf("List is too short for sorting\n");
        return;
    }
    int swapped;
    struct dcll *ptr1, *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        do {
            struct dcll* ptr2 = ptr1->next;
            if (ptr2 == head) break;
            if (ptr1->data > ptr2->data) {
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        } while (ptr1->next != lptr && ptr1 != head);
        lptr = ptr1;
    } while (swapped);
    printf("List sorted in ascending order\n");
}

// Reverse the list
void reverselist() {
    if (head == NULL || head->next == head) {
        printf("List is too short to reverse\n");
        return;
    }
    struct dcll *current = head;
    struct dcll *temp = NULL;
    do {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    } while (current != head);
    head = temp->prev;
    printf("List reversed\n");
}

// Find middle node
void findmiddle() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dcll* slow = head;
    struct dcll* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

// Insert at beginning
void insertfn(int data) {
    insert(data, 1);
    printf("Node inserted at the beginning.\n");
}

// Insert at end
void insertln(int data) {
    int length = countnodes();
    insert(data, length + 1);
    printf("Node inserted at the end.\n");
}

// Delete first node
void deletefn() {
    delete(1);
    printf("First node deleted.\n");
}

// Delete last node
void deleteln() {
    int length = countnodes();
    delete(length);
    printf("Last node deleted.\n");
}

int main() {
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
    } while (choice != 14);
    return 0;
}