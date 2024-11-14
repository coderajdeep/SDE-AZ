// leetcode iterative
// Time complexity O(n)
// Space complexity O(n)
vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return vector<int> {};
    
    vector<int> preorder;
    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* curr = nullptr;

    while(!stk.empty()) {
        curr = stk.top();
        stk.pop();
        preorder.push_back(curr->val);
        if(curr->right) {
            stk.push(curr->right);
        }
        if(curr->left) {
            stk.push(curr->left);
        }
    }
    return preorder;
}

// Coding Ninjas iterative
vector<int> preOrder(TreeNode<int> * root){
    if(!root) return vector<int> {};

    vector<int> preorder;
    TreeNode<int>* curr = nullptr;
    stack<TreeNode<int>*> stk;
    stk.push(root);
    
    while(!stk.empty()) {
        curr = stk.top();
        stk.pop();
        preorder.push_back(curr->data);
        if(curr->right) {
            stk.push(curr->right);
        }
        if(curr->left) {
            stk.push(curr->left);
        }
    }
    return preorder;
}