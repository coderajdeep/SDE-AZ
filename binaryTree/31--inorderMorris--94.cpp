// Morris InOrder traversal
// Time complexity O(2*n)
// Space complexity O(1)

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    while(root) {
        if(root->left) {
            TreeNode *prev = root->left;
            while(prev->right && prev->right != root) {
                prev = prev->right;
            }
            if(prev->right) {
                prev->right = nullptr;
                inorder.push_back(root->val);
                root = root->right;
            }
            else {
                prev->right = root;
                root = root->left;
            }
        }
        else {
            inorder.push_back(root->val);
            root = root->right;
        }
    }
    return inorder;
}