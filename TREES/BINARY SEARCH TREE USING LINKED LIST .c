#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* create a new node */
Node* createNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

/* insert value into BST (recursive) */
Node* insert(Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    /* if equal, do nothing (no duplicates) */
    return root;
}

/* search value in BST (recursive) -> returns node or NULL */
Node* search(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key == root->data) return root;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}

/* inorder traversal (sorted order) */
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

/* preorder */
void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

/* postorder */
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

/* find minimum node in a subtree */
Node* findMin(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

/* delete a value from BST */
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // found node to delete
        if (!root->left && !root->right) {
            // leaf
            free(root);
            return NULL;
        } else if (!root->left) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            free(root);
            return temp;
        } else {
            // two children: replace with inorder successor (min in right subtree)
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

/* free whole tree */
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

/* small demo */
int main() {
    Node* root = NULL;
    int values[] = {50, 30, 20, 40, 70, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i)
        root = insert(root, values[i]);

    printf("Inorder (sorted): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    int key = 40;
    Node* found = search(root, key);
    printf("Search %d: %s\n", key, found ? "found" : "not found");

    printf("Deleting 50 (root with 2 children)...\n");
    root = deleteNode(root, 50);

    printf("Inorder after delete: ");
    inorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
