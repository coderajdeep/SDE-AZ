// Time complexity O(n)
// Recursive space complexity O(n)

void solve(TreeNode *root, TreeNode *&prev) {
    if(!root) return;
    solve(root->right, prev);
    solve(root->left, prev);
    root->left = nullptr;
    root->right = prev;
    prev = root;
}
void flatten(TreeNode* root) {
    TreeNode *prev = nullptr;
    solve(root, prev);
}