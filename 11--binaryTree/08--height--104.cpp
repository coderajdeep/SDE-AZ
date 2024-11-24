int maxDepth(TreeNode* root) {
    if(!root) return 0;
    int lheight = maxDepth(root->left);
    int rheight = maxDepth(root->right);
    return (1 + max(lheight, rheight));
}