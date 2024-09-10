// LCA in binary tree

// Solution 1
// Best solution
// Time complexity O(log(h))
// Space complexity O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while(root) {
        if(root==p || root==q) return root;
        if(root->val > p->val && root->val > q->val) {
            root = root->left;
        }
        else if(root->val < p->val && root->val < q->val) {
            root = root->right;
        }
        else return root;
    }
    return nullptr;
}

// Solution 2
// Time complexity O(n)
// Space complexity O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q) return root;
    TreeNode *lnode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rnode = lowestCommonAncestor(root->right, p, q);
    if(lnode && rnode) return root;
    return lnode ? lnode : rnode;
}