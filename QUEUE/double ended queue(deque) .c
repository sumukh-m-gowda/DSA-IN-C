#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull()  { return (front == 0 && rear == SIZE-1) || (front == rear + 1); }
int isEmpty() { return front == -1; }

void insertFront(int val) {
    if (isFull()) { printf("Deque Full\n"); return; }
    if (isEmpty()) front = rear = 0;
    else if (front == 0) front = SIZE - 1;
    else front--;
    deque[front] = val;
}

void insertRear(int val) {
    if (isFull()) { printf("Deque Full\n"); return; }
    if (isEmpty()) front = rear = 0;
    else if (rear == SIZE - 1) rear = 0;
    else rear++;
    deque[rear] = val;
}

int deleteFront() {
    if (isEmpty()) { printf("Deque Empty\n"); return -1; }
    int val = deque[front];
    if (front == rear) front = rear = -1;
    else if (front == SIZE - 1) front = 0;
    else front++;
    return val;
}

int deleteRear() {
    if (isEmpty()) { printf("Deque Empty\n"); return -1; }
    int val = deque[rear];
    if (front == rear) front = rear = -1;
    else if (rear == 0) rear = SIZE - 1;
    else rear--;
    return val;
}

void display() {
    if (isEmpty()) { printf("Deque Empty\n"); return; }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertRear(10); insertRear(20); insertFront(5);
    display();
    deleteRear(); display();
    return 0;
}
