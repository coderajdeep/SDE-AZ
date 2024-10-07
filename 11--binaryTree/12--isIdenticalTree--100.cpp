// Time complexity O(n)
// Space Complexity O(n)

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    return ((p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}