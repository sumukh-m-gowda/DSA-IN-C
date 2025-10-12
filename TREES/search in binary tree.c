int ifNodeExists(struct Node* root, int key) {
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    int res1 = ifNodeExists(root->left, key);
    if (res1) return 1;
    int res2 = ifNodeExists(root->right, key);
    return res2;
}
