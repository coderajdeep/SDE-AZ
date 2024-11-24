// Time complexity O(n)
// Space complexity O(H)
void inOrder(TreeNode *root, vector<TreeNode*> &inorder) {
    if(!root) return;
    inOrder(root->left, inorder);
    inorder.push_back(root);
    inOrder(root->right, inorder);
}
TreeNode* getBalancedTree(int left, int right, vector<TreeNode*> &inorder) {
    if(left>right) return nullptr;
    int mid = left + (right-left)/2;
    TreeNode *root = inorder[mid];
    root->left = getBalancedTree(left, mid-1, inorder);
    root->right = getBalancedTree(mid+1, right, inorder);
    return root;
}
TreeNode* balanceBST(TreeNode* root) {
    if(!root) return root;
    vector<TreeNode*> inorder;
    inOrder(root, inorder);
    return getBalancedTree(0, inorder.size()-1, inorder);
}