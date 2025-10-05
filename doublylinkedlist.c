#include <stdio.h>
#include <stdlib.h>
struct dll {
    int data;
    struct dll* next;
    struct dll* prev;
};
struct dll* head = NULL;

// Create n nodes in doubly linked list
void createList(int n) {
    struct dll *temp, *newNode;
    int value, i;
    head = NULL;
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct dll*)malloc(sizeof(struct dll));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

// Traverse the doubly linked list forward
void traverse() {
    struct dll* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes in the doubly linked list
int countnodes() {
    struct dll* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Insert a node at a specific position (1-based)
void insert(int data, int pos) {
    struct dll* newNode = (struct dll*)malloc(sizeof(struct dll));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    struct dll* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

// Delete a node from a specific position (1-based)
void delete(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct dll* temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Search an element in the doubly linked list
void search(int n) {
    struct dll* temp = head;
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

// Sort the doubly linked list in ascending order using bubble sort
void sortlist() {
    struct dll *i, *j;
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

// Reverse the doubly linked list
void reverselist() {
    struct dll* temp = NULL;
    struct dll* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    printf("List reversed\n");
}

// Find middle node (slow and fast pointer)
void findmiddle() {
    struct dll* slow = head;
    struct dll* fast = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

// Insert node at beginning
void insertfn(int data) {
    struct dll* newnode = (struct dll*)malloc(sizeof(struct dll));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    printf("Node inserted at the beginning.\n");
}

// Insert node at the end
void insertln(int data) {
    struct dll* newnode = (struct dll*)malloc(sizeof(struct dll));
    if (newnode == NULL) {
        printf("Memory allocation failed!.\n");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        struct dll* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    printf("Node inserted at the end.\n");
}

// Delete the first node
void deletefn() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct dll* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("First Node deleted.\n");
}

// Delete the last node
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
    struct dll* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted\n");
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