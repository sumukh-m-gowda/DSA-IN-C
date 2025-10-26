#include <stdio.h>
#define MAX 100   // Maximum size of heap array

int heap[MAX];
int size = 0;     // Current number of elements in heap

// -------------------------- Utility Functions --------------------------

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// -------------------------- Heapify Up --------------------------
// Used after insertion to restore heap property (Bottom → Up)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// -------------------------- Heapify Down --------------------------
// Used after deletion or buildHeap (Top → Down)
void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare with left child
    if (left < size && heap[left] > heap[largest])
        largest = left;

    // Compare with right child
    if (right < size && heap[right] > heap[largest])
        largest = right;

    // If parent is smaller, swap and continue down
    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(largest);
    }
}

// -------------------------- Insert --------------------------
void insert(int value) {
    if (size == MAX) {
        printf("Heap is full! Cannot insert.\n");
        return;
    }

    heap[size] = value;  // Place new element at end
    size++;

    heapifyUp(size - 1); // Restore heap property
    printf("Inserted %d successfully.\n", value);
}

// -------------------------- Extract Max --------------------------
int extractMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int maxValue = heap[0];  // Root (max)
    heap[0] = heap[size - 1]; // Move last to root
    size--;

    heapifyDown(0); // Restore heap property
    return maxValue;
}

// -------------------------- Peek / Get Max --------------------------
int getMax() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    return heap[0];
}

// -------------------------- Build Heap from Array --------------------------
void buildHeap(int arr[], int n) {
    if (n > MAX) {
        printf("Array too large!\n");
        return;
    }

    // Copy array into heap
    for (int i = 0; i < n; i++)
        heap[i] = arr[i];

    size = n;

    // Heapify all non-leaf nodes (bottom → up)
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapifyDown(i);
}

// -------------------------- Display Heap --------------------------
void displayHeap() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// -------------------------- Main Function --------------------------
int main() {
    int choice, value, arr[] = {10, 5, 30, 20, 35, 15};

    while (1) {
        printf("\n---- MAX HEAP MENU ----\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Get Max\n");
        printf("4. Build Heap from Array\n");
        printf("5. Display Heap\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            value = extractMax();
            if (value != -1)
                printf("Extracted Max: %d\n", value);
            break;

        case 3:
            value = getMax();
            if (value != -1)
                printf("Max value: %d\n", value);
            break;

        case 4:
            buildHeap(arr, 6);
            printf("Heap built from array successfully!\n");
            break;

        case 5:
            displayHeap();
            break;

        case 6:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
