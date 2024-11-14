// leetcode Iterative Inorder Traversal
// Time complexity O(n)
// Space complexity O(n)
vector<int> inorderTraversal(TreeNode* root) {
    if(!root) return vector<int> {};

    vector<int> inorder;
    TreeNode* curr = root;
    stack<TreeNode*> stk;

    while(!stk.empty() || curr) {
        if(curr) {
            stk.push(curr);
            curr = curr->left;
        }
        else {
            curr = stk.top();
            stk.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
    }
    return inorder;
}