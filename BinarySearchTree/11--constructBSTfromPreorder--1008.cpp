// Solution 3
// Best solution
// Time complexity O(n)
// Space complexity O(h)
TreeNode* getTree(int &index, int upperLimit, vector<int> &preorder) {
    if(index == preorder.size() || preorder[index] > upperLimit) {
        return nullptr;
    }
    int rootValue = preorder[index++];
    TreeNode *root = new TreeNode(rootValue);
    root->left = getTree(index, rootValue, preorder);
    root->right = getTree(index, upperLimit, preorder);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;
    return getTree(index, INT_MAX, preorder);
}

// Solution 1
// Time complexity O(n*h)
// Space complexity O(n)
TreeNode* insertIntoBST(TreeNode *root, int val) {
    TreeNode *node = new TreeNode(val);
    if(!root) return node;
    TreeNode *curr = root;
    while(curr) {
        if(curr->val > val) {
            if(!curr->left) {
                curr->left = node;
                break; 
            }
            curr = curr->left;
        }
        else {
            if(!curr->right) {
                curr->right = node;
                break; 
            }
            curr = curr->right;
        }
    }
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode *root = nullptr;
    for(int val : preorder) {
        root = insertIntoBST(root, val);
    }
    return root;
}

// Solution 2
// Time complexity O(nlogn) + O(n)
// Space complexity O(n)ß
TreeNode* getTree(int inStart, int inEnd, int &preStart, vector<int> &preorder, unordered_map<int, int> &inHash) {
    if(inStart>inEnd) return nullptr;
    int rootValue = preorder[preStart++];
    TreeNode *root = new TreeNode(rootValue);
    int inIndex = inHash[rootValue];
    root->left = getTree(inStart, inIndex-1, preStart, preorder, inHash);
    root->right = getTree(inIndex+1, inEnd, preStart, preorder, inHash);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    vector<int> inorder(preorder.begin(), preorder.end());
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> inHash;
    int n = preorder.size(), preStart = 0;
    for(int i=0; i<n; ++i) {
        inHash[inorder[i]] = i;
    }
    return getTree(0, n-1, preStart, preorder, inHash);
}