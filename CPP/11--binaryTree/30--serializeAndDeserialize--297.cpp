// Time complexity O(n)
// Space complexity O(n)

string serialize(TreeNode* root) {
    if(!root) return "";
    queue<TreeNode*>q;
    q.push(root);
    TreeNode* curr = nullptr;
    string ans;
    while(!q.empty()) {
        curr = q.front();
        q.pop();
        if(!curr) {
            ans += "#,";
        }
        else {
            ans += (to_string(curr->val) + ",");
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(!data.size()) return nullptr;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    TreeNode* curr;
    q.push(root);

    while(!q.empty()) {
        curr = q.front();
        q.pop();

        getline(s, str, ',');
        if(str=="#") {
            curr->left = nullptr;
        }
        else {
            curr->left = new TreeNode(stoi(str));
            q.push(curr->left);
        }

        getline(s, str, ',');
        if(str=="#") {
            curr->right = nullptr;
        }
        else {
            curr->right = new TreeNode(stoi(str));
            q.push(curr->right);
        }
    }
    return root;
}