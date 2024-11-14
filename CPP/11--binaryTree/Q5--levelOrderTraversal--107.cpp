int height(TreeNode *root) {
    return (root ? (1 + max(height(root->left), height(root->right))) : 0);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*>q;
    q.push(root);
    int h = height(root);
    vector<vector<int>> ans(h);
    
    while(!q.empty()) {
        int size = q.size();
        vector<int>arr(size);
        for(int i=0; i<size; ++i) {
            TreeNode *curr = q.front();
            q.pop();
            arr[i] = curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        ans[--h] = arr; 
    }
    return ans;
}