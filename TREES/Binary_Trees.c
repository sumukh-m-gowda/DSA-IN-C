#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
    if (q->front == -1)
        q->front = 0;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q))
        return NULL;
    return q->arr[q->front++];
}

void insertLevelOrder(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, *root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else
            enqueue(&q, temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else
            enqueue(&q, temp->right);
    }
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL) enqueue(&q, temp->left);
        if (temp->right != NULL) enqueue(&q, temp->right);
    }
}

int main() {
    struct Node* root = NULL;

    insertLevelOrder(&root, 1);
    insertLevelOrder(&root, 2);
    insertLevelOrder(&root, 3);
    insertLevelOrder(&root, 4);
    insertLevelOrder(&root, 5);
    insertLevelOrder(&root, 6);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}

