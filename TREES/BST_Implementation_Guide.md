# Binary Search Tree (BST) in C

## 🚀 Step 1: Basic BST Node Structure

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
```

## 🌱 Step 2: BST Insertion

Rules:
- If new value < current → go left
- If new value > current → go right
- If NULL → insert new node here

```c
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) 
        return createNode(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}
```

✅ Example usage:

```c
int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    return 0;
}
```

## 🔍 Step 3: Searching in BST

```c
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
```

✅ Example:
```c
struct Node* result = search(root, 60);
if (result != NULL)
    printf("Found %d\n", result->data);
else
    printf("Not found\n");
```

## 🌿 Step 4: Tree Traversals

### (a) Inorder (L → Root → R)
```c
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
```

### (b) Preorder (Root → L → R)
```c
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
```

### (c) Postorder (L → R → Root)
```c
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
```

## ❌ Step 5: Deletion in BST

### Helper to find inorder successor
```c
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
```

### Delete function
```c
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
```

✅ Example:
```c
printf("Before deletion (Inorder): ");
inorder(root);
printf("\n");

root = deleteNode(root, 50);

printf("After deletion (Inorder): ");
inorder(root);
printf("\n");
```

## 🧠 Step 6: Additional Useful Operations

### Find Minimum & Maximum
```c
int findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    while (root->right != NULL)
        root = root->right;
    return root->data;
}
```

### Find Height (Depth) of BST
```c
int height(struct Node* root) {
    if (root == NULL)
        return -1; 
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}
```
