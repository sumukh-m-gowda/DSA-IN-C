#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up for insertion
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        heapifyUp(parent);
    }
}

// Insert element
void insert(int value) {
    if (size == MAX) {
        printf("Heap is full!\n");
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Heapify down for deletion
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// Delete root
void deleteRoot() {
    if (size <= 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted root: %d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Display heap
void display() {
    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Build heap from array
void buildHeap(int arr[], int n) {
    for (int i = 0; i < n; i++)
        insert(arr[i]);
}

int main() {
    int arr[] = {20, 15, 30, 5, 10, 25, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Building heap...\n");
    buildHeap(arr, n);
    display();

    printf("\nInserting 45...\n");
    insert(45);
    display();

    printf("\nDeleting root...\n");
    deleteRoot();
    display();

    return 0;
}
