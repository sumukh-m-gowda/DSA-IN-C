#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Empty\n");
        return -1;
    }
    int val = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return val;
}

void display() {
    if (front == NULL) { printf("Queue Empty\n"); return; }
    printf("Queue: ");
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue(); display();
    return 0;
}
