# Expression Tree in C

## 🌳 Basics

- Leaf nodes = operands (numbers)
- Internal nodes = operators (+, -, *, /)

Example: Expression `3 + ((5 + 9) * 2)`

```
        +
       / \
      3   *
         / \
        +   2
       / \
      5   9
```

---

## 🌱 Step 1: Node Structure

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isdigit()

struct ExprNode {
    char value;             // Operator or operand
    struct ExprNode *left;
    struct ExprNode *right;
};

struct ExprNode* createExprNode(char val) {
    struct ExprNode* node = (struct ExprNode*)malloc(sizeof(struct ExprNode));
    node->value = val;
    node->left = node->right = NULL;
    return node;
}
```

---

## 🌱 Step 2: Build Expression Tree from Postfix

```c
#define MAX 100

struct ExprNode* stack[MAX];
int top = -1;

void push(struct ExprNode* node) { stack[++top] = node; }
struct ExprNode* pop() { return stack[top--]; }

struct ExprNode* buildExpressionTree(char postfix[]) {
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(createExprNode(c));
        } else { // Operator
            struct ExprNode* node = createExprNode(c);
            node->right = pop();
            node->left = pop();
            push(node);
        }
    }
    return pop(); // root
}
```

Example postfix: `"359+2*+"` for expression `3 + ((5+9)*2)`

---

## 🌿 Step 3: Traversals

```c
void inorder(struct ExprNode* root) {
    if (root) {
        if (!isdigit(root->value)) printf("(");
        inorder(root->left);
        printf("%c", root->value);
        inorder(root->right);
        if (!isdigit(root->value)) printf(")");
    }
}

void preorder(struct ExprNode* root) {
    if (root) {
        printf("%c ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct ExprNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->value);
    }
}
```

---

## 🧮 Step 4: Evaluate Expression Tree

```c
int evaluate(struct ExprNode* root) {
    if (isdigit(root->value))
        return root->value - '0';

    int leftVal = evaluate(root->left);
    int rightVal = evaluate(root->right);

    switch(root->value) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;
}
```

---

## ⚡ Step 5: Complete Program

```c
int main() {
    char postfix[] = "359+2*+"; // Example expression
    struct ExprNode* root = buildExpressionTree(postfix);

    printf("Inorder (infix): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Evaluated Result: %d\n", evaluate(root));

    return 0;
}
```
