#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

int isFull()  { return (front == 0 && rear == SIZE-1) || (rear + 1 == front); }
int isEmpty() { return front == -1; }

void enqueue(int val) {
    if (isFull()) {
        printf("Queue Full\n");
        return;
    }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % SIZE;
    cq[rear] = val;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return -1;
    }
    int val = cq[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
    return val;
}

void display() {
    if (isEmpty()) { printf("Queue Empty\n"); return; }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue(); enqueue(40); enqueue(50); enqueue(60);
    display();
    return 0;
}
