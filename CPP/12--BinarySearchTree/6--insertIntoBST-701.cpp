// Time complexity O(h)
// Space complexity O(h)
// Recursive approach
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) {
        return new TreeNode(val);
    }
    else if(val < root->val) {
        root->left = insertIntoBST(root->left, val);
    }
    else if(val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Iterative Method
// Time complexity O(h)
// Space complexity O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode *node = new TreeNode(val);
    if(!root) return node;
    TreeNode *curr = root;
    while(curr) {
        if(curr->val > val) {
            if(!curr->left) {
                curr->left = node;
                break;
            }
            curr = curr->left;
        }
        else {
            if(!curr->right) {
                curr->right = node;
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}