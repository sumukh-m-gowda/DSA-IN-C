/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    int result;
    if (leftDepth > rightDepth) {
        result = leftDepth + 1;
    } else {
        result = rightDepth + 1;
    }

    return result;
}

int minDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL)
        return 1 + minDepth(root->right);
    if (root->right == NULL)
        return 1 + minDepth(root->left);
    int lDepth = minDepth(root->left);
    int rDepth = minDepth(root->right);
    int result;
    if (lDepth < rDepth ){
        result = lDepth + 1;
    } else  {
        result = rDepth + 1;
    }
    return result;
}
