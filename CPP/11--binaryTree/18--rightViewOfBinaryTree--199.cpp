// Time Complexity O(n)
// Space complexity O(h) : h --> height of binary tree (Recursion stack space)

// Solution 1
void rightView(TreeNode* root, vector<int>& ans, int level, int& maxLevel) {
    if(!root) return;
    if(level==maxLevel) {
        ans.push_back(root->val);
        ++maxLevel;
    }
    rightView(root->right, ans, level+1, maxLevel);
    rightView(root->left, ans, level+1, maxLevel);
}
vector<int> rightSideView(TreeNode* root) {
    if(!root) return vector<int> {};
    vector<int> ans;
    int maxLevel = 1;
    rightView(root, ans, 1, maxLevel);
    return ans;
}

// Solution 2
// Similar to solution 1
// Striver solution
void rightView(TreeNode* root, vector<int>& ans, int level) {
    if(!root) return;
    if(level==ans.size()) {
        ans.push_back(root->val);
    }
    rightView(root->right, ans, level+1);
    rightView(root->left, ans, level+1);
}
vector<int> rightSideView(TreeNode* root) {
    if(!root) return vector<int> {};
    vector<int> ans;
    rightView(root, ans, 0);
    return ans;
}

// solution 3
// Uisng Level order traversal
vector<int> rightSideView(TreeNode* root) {
    if(!root) return vector<int> {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool flag;
    while(!q.empty()) {
        int size = q.size();
        flag = true;
        for(int i=0; i<size; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if(flag) {
                ans.push_back(curr->val);
                flag = false;
            }
            if(curr->right) {
                q.push(curr->right);
            }
            if(curr->left) {
                q.push(curr->left);
            }
        }
    }
    return ans;
}


// Left View of binary tree
// Geeks
void leftViewUtils(Node* root, vector<int>& ans, int level, int& maxLevel) {
    if(!root) return;
    if(level==maxLevel) {
        ans.push_back(root->data);
        maxLevel++;
    }
    leftViewUtils(root->left, ans, level+1, maxLevel);
    leftViewUtils(root->right, ans, level+1, maxLevel);
}
vector<int> leftView(Node *root) {
   if(!root) return vector<int> {};
   vector<int> ans;
   int maxLevel = 1;
   leftViewUtils(root, ans, 1, maxLevel);
   return ans;
}

// This will not work
// Which is used in boundary order traversal
vector<int> rightSideView(TreeNode* root) {
    if(!root) return vector<int> {};
    vector<int> ans;
    while(root) {
        ans.push_back(root->val);
        if(root->left) root = root->left;
        else root = root->left;
    }
    return ans;
}