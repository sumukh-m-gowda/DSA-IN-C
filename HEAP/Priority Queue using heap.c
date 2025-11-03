// 🧩 Priority Queue Functions — Short Notes
// 🔹 insertMin()
// Inserts a new element into the Min Heap (smallest element = highest priority).
// Adds it at the end, then calls heapifyUpMin() to restore heap order (move it upward if smaller than parent).
// 🔹 insertMax()
// Inserts a new element into the Max Heap (largest element = highest priority).
// Adds it at the end, then calls heapifyUpMax() to restore heap order (move it upward if larger than parent).
// 🔹 extractMin()
// Removes and returns the smallest element (root) from the Min Heap.
// Replaces root with the last element, reduces heap size, then calls heapifyDownMin() to restore heap property.
// 🔹 extractMax()
// Removes and returns the largest element (root) from the Max Heap.
// Replaces root with the last element, reduces heap size, then calls heapifyDownMax() to restore heap property.
// 🔹 displayMinHeap()
// Prints all elements currently in the Min Heap array (level-order).
// Helps visualize the current structure of the Min Heap.
// 🔹 displayMaxHeap()
// Prints all elements currently in the Max Heap array (level-order).
// Helps visualize the current structure of the Max Heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------- STRUCTURE ----------
typedef struct {
    int arr[MAX];
    int size;
} PriorityQueue;

// ---------- UTILITY ----------
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ---------- HEAPIFY UP ----------
void heapifyUpMin(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->arr[parent] > pq->arr[index]) {
        swap(&pq->arr[parent], &pq->arr[index]);
        heapifyUpMin(pq, parent);
    }
}

void heapifyUpMax(PriorityQueue *pq, int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && pq->arr[parent] < pq->arr[index]) {
        swap(&pq->arr[parent], &pq->arr[index]);
        heapifyUpMax(pq, parent);
    }
}

// ---------- HEAPIFY DOWN ----------
void heapifyDownMin(PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < pq->size && pq->arr[left] < pq->arr[smallest])
        smallest = left;
    if (right < pq->size && pq->arr[right] < pq->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&pq->arr[index], &pq->arr[smallest]);
        heapifyDownMin(pq, smallest);
    }
}

void heapifyDownMax(PriorityQueue *pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < pq->size && pq->arr[left] > pq->arr[largest])
        largest = left;
    if (right < pq->size && pq->arr[right] > pq->arr[largest])
        largest = right;

    if (largest != index) {
        swap(&pq->arr[index], &pq->arr[largest]);
        heapifyDownMax(pq, largest);
    }
}

// ---------- INSERT ----------
void insertMin(PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Min Heap is full!\n");
        return;
    }
    pq->arr[pq->size] = value;
    pq->size++;
    heapifyUpMin(pq, pq->size - 1);
}

void insertMax(PriorityQueue *pq, int value) {
    if (pq->size == MAX) {
        printf("Max Heap is full!\n");
        return;
    }
    pq->arr[pq->size] = value;
    pq->size++;
    heapifyUpMax(pq, pq->size - 1);
}

// ---------- EXTRACT ----------
int extractMin(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Min Heap is empty!\n");
        return -1;
    }
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDownMin(pq, 0);
    return root;
}

int extractMax(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Max Heap is empty!\n");
        return -1;
    }
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDownMax(pq, 0);
    return root;
}

// ---------- DISPLAY ----------
void display(PriorityQueue pq) {
    for (int i = 0; i < pq.size; i++)
        printf("%d ", pq.arr[i]);
    printf("\n");
}

// ---------- MAIN ----------
int main() {
    PriorityQueue minPQ = {.size = 0};
    PriorityQueue maxPQ = {.size = 0};

    // Insert into Min Heap
    insertMin(&minPQ, 5);
    insertMin(&minPQ, 3);
    insertMin(&minPQ, 8);
    insertMin(&minPQ, 1);

    printf("Min Heap elements: ");
    display(minPQ);
    printf("Extracted min: %d\n", extractMin(&minPQ));
    printf("After extraction: ");
    display(minPQ);

    printf("\n");

    // Insert into Max Heap
    insertMax(&maxPQ, 5);
    insertMax(&maxPQ, 3);
    insertMax(&maxPQ, 8);
    insertMax(&maxPQ, 1);

    printf("Max Heap elements: ");
    display(maxPQ);
    printf("Extracted max: %d\n", extractMax(&maxPQ));
    printf("After extraction: ");
    display(maxPQ);

    return 0;
}
