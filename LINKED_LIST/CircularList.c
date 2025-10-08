#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
    }
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);

    if (*head == NULL && position == 0) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(Node** head) {
    if (*head == NULL)
        return;

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    Node* toDelete = *head;
    temp->next = (*head)->next;
    *head = (*head)->next;
    free(toDelete);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL)
        return;

    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* secondLast = *head;
    while (secondLast->next->next != *head)
        secondLast = secondLast->next;

    Node* last = secondLast->next;
    secondLast->next = *head;
    free(last);
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL)
        return;

    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void traverse(Node* head) {
    if (head == NULL)
        return;

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int search(Node* head, int key) {
    if (head == NULL)
        return 0;

    Node* temp = head;
    do {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    } while (temp != head);

    return 0; 
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 15, 2);

    printf("Circular Linked List: ");
    traverse(head);

    deleteFromEnd(&head);
    deleteAtPosition(&head, 1);

    printf("Circular Linked List after deletion: ");
    traverse(head);

    int key = 10;
    if (search(head, key))
        printf("Element %d is found in the linked list.\n", key);
    else
        printf("Element %d is not found in the linked list.\n", key);

    return 0;
}
