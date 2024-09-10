// Time complexity O(n)
// Space complexity O(W) : W --> maximum width

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root) return vector<vector<int>> {};

    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr = nullptr;
    vector<vector<int>> ans;
    bool isOdd = true;

    while(!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for(int i=0; i<size; ++i) {
            curr = q.front();
            q.pop();
            if(isOdd) {
                level[i] = curr->val;
            }
            else {
                level[size-i-1] = curr->val;
            }
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        ans.push_back(level);
        isOdd = !isOdd;
    }
    return ans;
}