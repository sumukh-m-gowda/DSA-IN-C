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

void insertAtFirst(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        insertAtFirst(head, data);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromFirst(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);
}

void deleteFromEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    
    insertAtFirst(&head, 10);
    printf("Linked list after inserting 10 at beginning:\n");
    printList(head); 
    
    insertAtEnd(&head, 20);
    printf("Linked list after inserting 20 at end:\n");
    printList(head); 
    
    insertAtEnd(&head, 5);
    printf("Linked list after inserting 5 at end:\n");
    printList(head); 
    
    insertAtEnd(&head, 30);
    printf("Linked list after inserting 30 at end:\n");
    printList(head); 
    
    insertAtPosition(&head, 15, 2);
    printf("Linked list after inserting 15 at position 2:\n");
    printList(head);
    
    deleteFromFirst(&head);
    printf("Linked list after deleting first node:\n");
    printList(head); 
    
    deleteFromEnd(&head);
    printf("Linked list after deleting last node:\n");
    printList(head); 
    
    deleteAtPosition(&head, 1);
    printf("Linked list after deleting node at position 1:\n");
    printList(head); 

    return 0;
}
