
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TeeNode* createnode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = createNode('R');
    struct TreeNode* nodeA = createNode('A');
    struct TreeNode* nodeB = createNode('B');
    struct TreeNode* nodeC = createNode('C');
    struct TreeNode* nodeD = createNode('D');
    struct TreeNode* nodeE = createNode('E');
    struct TreeNode* nodeF = createNode('F');
    struct TreeNode* nodeG = createNode('G');

    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    printf("root->right->left->data: %c\n", root->right->left->data);

    return 0;
}
