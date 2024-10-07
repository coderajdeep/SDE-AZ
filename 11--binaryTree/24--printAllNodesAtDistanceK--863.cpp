// Time Complexity O(2*n)
// Space complexity O(2*w + n)

// Soluton 1
// In this solution, getting parenets nodes is being calculated using level order (bfs) traversal
void getParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &um) {
    if(!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left) {
            q.push(curr->left);
            um[curr->left] = curr;
        }
        if(curr->right) {
            q.push(curr->right);
            um[curr->right] = curr;
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root || !target) return vector<int> {};
    unordered_map<TreeNode*, TreeNode*> um;
    unordered_set<TreeNode*> us;
    queue<TreeNode*> q;
    q.push(target);
    us.insert(target);
    vector<int> ans;
    getParents(root, um);
    int level = 0;

    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            TreeNode *curr = q.front();
            q.pop();
            if(k == level) {
                ans.push_back(curr->val);
            }
            if(curr->left && us.find(curr->left)==us.end()) {
                us.insert(curr->left);
                q.push(curr->left);
            }
            if(curr->right && us.find(curr->right)==us.end()) {
                us.insert(curr->right);
                q.push(curr->right);
            }
            if(curr != root) {
                TreeNode *par = um[curr];
                if(par && us.find(par)==us.end()) {
                    us.insert(par);
                    q.push(par);
                }
            }
        }
        if(k == level) return ans;
        ++level;
    }
    // ***
    // this will occure when k > diameter of the binary tree
    return ans;
}


// Solution 2
// In this solution, getting parenets nodes is being calculated using preorde (dfs) traversal
void getParents(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parents) {
    if(!root) return;
    if(root->left) parents[root->left] = root;
    if(root->right) parents[root->right] = root;
    getParents(root->left, parents);
    getParents(root->right, parents);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if(!root || !target) return vector<int> {};
    unordered_map<TreeNode*, TreeNode*> parents;
    unordered_set<TreeNode*> uset;
    getParents(root, parents);
    queue<TreeNode*> q;
    TreeNode *curr;
    int dist = 0;
    vector<int> ans;
    q.push(target);
    uset.insert(target);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            curr = q.front();
            q.pop();
            if(dist==k) {
                ans.push_back(curr->val);
            }
            if(curr->left && uset.find(curr->left)==uset.end()) {
                q.push(curr->left);
                uset.insert(curr->left);
            }
            if(curr->right && uset.find(curr->right)==uset.end()) {
                q.push(curr->right);
                uset.insert(curr->right);
            }
            if(curr != root) {
                TreeNode *par = parents[curr];
                if(uset.find(par) == uset.end()) {
                    q.push(par);
                    uset.insert(par);
                }
            }
        }
        if(dist==k) break;
        ++dist;
    }
    return ans;
}