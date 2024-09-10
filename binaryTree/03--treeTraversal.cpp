// Binary Tree traversal

void inOrder(TreeNode* root, vector<int>& inorder) {
    if(!root) return;
    inOrder(root->left, inorder);
    inorder.push_back(root->data);
    inOrder(root->right, inorder);
}
void preOrder(TreeNode* root, vector<int>& preorder) {
    if(!root) return;
    preorder.push_back(root->data);
    preOrder(root->left, preorder);
    preOrder(root->right, preorder);
}
void postOrder(TreeNode* root, vector<int>& postorder) {
    if(!root) return;
    postOrder(root->left, postorder);
    postOrder(root->right, postorder);
    postorder.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(!root) vector<vector<int>> {{}, {}. {}};
    vector<vector<int>> ans;
    vector<int> inorder, preorder, postorder;
    inOrder(root, inorder);
    preOrder(root, preorder);
    postOrder(root, postorder);
    return {inorder, preorder, postorder};
}

// Three traversal in a single go
// Time complexity O(3*N)
// Space complexity O(4*N)
vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(!root) return vector<vector<int>> {{}, {}, {}};
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<TreeNode*, int>> stk;
    pair<TreeNode*, int> p;
    int num;
    TreeNode* curr = nullptr;
    stk.push(make_pair(root, 1));

    while(!stk.empty()) {
        p = stk.top();
        stk.pop();
        curr = p.first;
        num = p.second;

        if(num==1) {
            preOrder.push_back(curr->data);
            stk.push(make_pair(curr, 2));
            if(curr->left) {
                stk.push(make_pair(curr->left, 1));
            }
        }
        else if(num==2) {
            inOrder.push_back(curr->data);
            stk.push(make_pair(curr, 3));
            if(curr->right) {
                stk.push(make_pair(curr->right, 1));
            }
        }
        else if(num==3) {
            postOrder.push_back(curr->data);
        }
    }
    return vector<vector<int>> {inOrder, preOrder, postOrder};
}