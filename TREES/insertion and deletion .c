#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue structure for level order traversal
struct Queue {
    int front, rear, size;
    struct Node** arr;
};

// Function to create a queue
struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1)
        return; // queue full
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = node;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == -1)
        return NULL;
    struct Node* node = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return node;
}

// Check if queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Insert node in binary tree (Level Order)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* curr = dequeue(q);

        if (curr->left != NULL)
            enqueue(q, curr->left);
        else {
            curr->left = createNode(data);
            return root;
        }

        if (curr->right != NULL)
            enqueue(q, curr->right);
        else {
            curr->right = createNode(data);
            return root;
        }
    }
    return root;
}

// Delete the deepest node
void deleteDeepest(struct Node* root, struct Node* dNode) {
    struct Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct Node* curr = dequeue(q);

        if (curr == dNode) {
            free(dNode);
            return;
        }

        if (curr->left) {
            if (curr->left == dNode) {
                free(curr->left);
                curr->left = NULL;
                return;
            } else {
                enqueue(q, curr->left);
            }
        }

        if (curr->right) {
            if (curr->right == dNode) {
                free(curr->right);
                curr->right = NULL;
                return;
            } else {
                enqueue(q, curr->right);
            }
        }
    }
}

// Delete a given key
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    struct Node* keyNode = NULL;
    struct Node* curr = NULL;

    while (!isEmpty(q)) {
        curr = dequeue(q);

        if (curr->data == key)
            keyNode = curr;

        if (curr->left)
            enqueue(q, curr->left);
        if (curr->right)
            enqueue(q, curr->right);
    }

    if (keyNode != NULL) {
        int x = curr->data;
        keyNode->data = x;
        deleteDeepest(root, curr);
    }

    return root;
}

// Inorder traversal for checking result
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 11);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 15);
    root = insertNode(root, 8);

    printf("Inorder traversal before deletion:\n");
    inorder(root);

    root = deleteNode(root, 11);

    printf("\nInorder traversal after deletion:\n");
    inorder(root);

    return 0;
}
