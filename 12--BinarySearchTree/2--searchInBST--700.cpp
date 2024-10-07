
// Time complexity O(h)
// Space complexity O(h)
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root || (root->val == val)) return root;
    else if(root->val > val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// Time complexity O(h)
// Space complexity O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return root;
    while(root && root->val!=val) {
        if(root->val>val) root = root->left;
        else  root = root->right;
    }
    // root can be searched value or null
    return root;
}