#include <stdio.h>
#define SIZE 100

int heap[SIZE];
int n = 0;

void insertMin(int val) {
    int i = ++n;
    heap[i] = val;
    while (i > 1 && heap[i/2] > heap[i]) {
        int t = heap[i]; heap[i] = heap[i/2]; heap[i/2] = t;
        i /= 2;
    }
}

int extractMin() {
    if (n == 0) return -1;
    int min = heap[1];
    heap[1] = heap[n--];
    int i = 1;
    while (1) {
        int l = 2*i, r = 2*i+1, smallest = i;
        if (l <= n && heap[l] < heap[smallest]) smallest = l;
        if (r <= n && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            int t = heap[i]; heap[i] = heap[smallest]; heap[smallest] = t;
            i = smallest;
        } else break;
    }
    return min;
}

int main() {
    insertMin(30); insertMin(10); insertMin(20);
    printf("%d\n", extractMin()); // 10
    printf("%d\n", extractMin()); // 20
}
