// Time complexity O((logn)*(logn))
// Space complexity O(logn)

int leftHeight(TreeNode* root) {
    if(!root) return 0;
    int height = 0;
    while(root) {
        ++height;
        root = root->left;
    }
    return height;
}
int rightHeight(TreeNode* root) {
    if(!root) return 0;
    int height = 0;
    while(root) {
        ++height;
        root = root->right;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lheight = leftHeight(root->left);
    int rheight = rightHeight(root->right);
    if(lheight==rheight) {
        return (1<<(lheight+1)) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}