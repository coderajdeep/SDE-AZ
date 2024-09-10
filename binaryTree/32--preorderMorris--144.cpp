// https://youtu.be/80Zug6D1_r4?t=1239
// very good explanation
// Morris Preorder traversal
// Time complexity O(2*n)
// Space complexity O(1)

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    while(root) {
        if(root->left) {
            TreeNode *prev = root->left;
            while(prev->right && prev->right!=root) {
                prev = prev->right;
            }
            if(prev->right) {
                prev->right = nullptr;
                root = root->right;
            }
            else {
                prev->right = root;
                preorder.push_back(root->val);
                root = root->left;
            }
        }
        else {
            preorder.push_back(root->val);
            root = root->right;
        }
    }
    return preorder;
}