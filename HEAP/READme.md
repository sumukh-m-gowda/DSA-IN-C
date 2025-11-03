# 🧠 Heap in C — Complete Notes + Theory + Examples + Code

## ✅ 1. What is a Heap?
A **heap** is a **complete binary tree** that satisfies a special rule called the **heap property**.

### Types:
### 🔹 Max Heap
- Every parent node’s value is **greater than or equal** to its children's values.
- The **root** contains the **maximum value**.

### 🔹 Min Heap
- Every parent node’s value is **less than or equal** to its children's values.
- The **root** contains the **minimum value**.

---

## ✅ 2. How Heap is Stored in C (Array Representation)

A heap is stored in an **array** (not using pointers or nodes).

For node at index `i`:

```
Left child  = 2*i + 1  
Right child = 2*i + 2  
Parent      = (i - 1) / 2  
```

### Example Max Heap

```
          50
        /    \
      30      40
     /  \    /
   10   5   20
```

Stored as:
```
heap[] = {50, 30, 40, 10, 5, 20}
```

---

## ✅ 3. Fundamental Heap Operations

| Operation | Description |
|----------|-------------|
| insert() | Add new element and restore heap using **heapify up** |
| deleteRoot() | Delete root and restore heap using **heapify down** |
| heapifyUp() | Fix heap from bottom → up |
| heapifyDown() | Fix heap from top → down |
| display() | Print heap array |
| buildHeap() | Convert array to heap |

---

# ✅ 4. What is Heapify?

**Heapify** = adjusting the tree when heap property breaks.

Two types:

## ⭐ Heapify Up (After INSERT)
Used when a new element is inserted at the **end** of the heap.

### Why?
Because the new element might be **greater than its parent** (in max heap).

### How?  
1. Insert at last index  
2. Compare with parent  
3. If child > parent → swap  
4. Move up and repeat  
5. Stop when property is satisfied

### Example (Heapify Up for Max Heap):

Initial:
```
        40
       /  \
     35    30
     /
   20
```

Insert `50`:
```
        40
       /  \
     35    30
     /
   20
   /
  50
```

Comparisons:
- 50 > 20 → swap  
- 50 > 35 → swap  
- 50 > 40 → swap  

Final:
```
        50
       /  \
     40    30
     /
   35
   /
  20
```

✅ Heapify Up complete.

---

## ⭐ Heapify Down (After DELETE ROOT)
Used when the **root is deleted** and last element is placed at root.

### Why?
The replacement element may be **smaller than its children** (max heap).

### How?
1. Replace root with last element  
2. Compare with children  
3. Swap with **largest child**  
4. Move down and repeat  
5. Stop when heap property holds  

### Example:

Initial:
```
        50
       /  \
     40    30
     / \
   35  20
```

Delete 50 → move last element (20) to root:
```
        20
       /  \
     40    30
     /
   35
```

Comparisons:
- 20 < 40 → swap  
- 20 < 35 → swap  

Final:
```
        40
       /  \
     35    30
     /
   20
```

✅ Heapify Down complete.

---

# ✅ 5. Complete C Code (All Operations in One File)

```c
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (after insertion)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[parent] < heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Insert element
void insert(int value) {
    heap[size] = value;   // put at last
    heapifyUp(size);      // fix the heap
    size++;
}

// Heapify Down (after deleting root)
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

// Delete root element
int deleteRoot() {
    if (size <= 0)
        return -1;

    int root = heap[0];

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

// Display heap
void display() {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(50);
    insert(30);
    insert(40);
    insert(10);
    insert(5);
    insert(20);

    printf("Initial Max Heap:\n");
    display();

    insert(45);
    printf("\nAfter inserting 45:\n");
    display();

    printf("\nDeleted root: %d\n", deleteRoot());
    printf("After deleting root:\n");
    display();

    return 0;
}
```

---

# ✅ Summary

- Heap = complete binary tree + heap property  
- Max Heap root = max element  
- Insert → Heapify Up  
- Delete Root → Heapify Down  
- Easy to store using array indexing formula  
- Used in **Priority Queue**, **Heapsort**, **Dijkstra**, etc.

---

✅ **This entire snippet is ONE BLOCK.**  
✅ **Copy–paste directly to GitHub.**  
✅ **You don’t need to merge anything — everything is inside here.**
