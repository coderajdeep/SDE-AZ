// Time complexity O(n+n)
// Space complexity O(n)

// Solution 1
// Solution 2 is better
TreeNode* getTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int &postEnd) {
    if(inStart>inEnd) return nullptr;
    TreeNode* root = new TreeNode(postorder[postEnd--]);
    int inIndex;
    for(int i=inStart; i<=inEnd; ++i) {
        if(inorder[i]==root->val) {
            inIndex = i;
            break;
        }
    }
    root->right = getTree(inorder, postorder, inIndex+1, inEnd, postEnd);
    root->left = getTree(inorder, postorder, inStart, inIndex-1, postEnd);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int inStart = 0;
    int inEnd = inorder.size()-1;
    int postEnd = postorder.size()-1;
    TreeNode* root = getTree(inorder, postorder, inStart, inEnd, postEnd);
    return root;
}

// Solution 1
// Optimized approach
// Time complexity O(n)
// Space complexity  O(n)

TreeNode* getTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &inHash, int inStart, int inEnd, int &postEnd) {
    if(inStart > inEnd) {
        return nullptr;
    }
    int rootValue = postorder[postEnd--];
    TreeNode *root = new TreeNode(rootValue);
    int inRootIndex = inHash[rootValue];
    root->right = getTree(inorder, postorder, inHash, inRootIndex+1, inEnd, postEnd);
    root->left = getTree(inorder, postorder, inHash, inStart, inRootIndex-1, postEnd);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> inHash;
    for(int i=0; i<n; ++i) {
        inHash[inorder[i]] = i;
    }
    int inStart = 0, inEnd = n-1, postEnd = n-1;
    return getTree(inorder, postorder, inHash, inStart, inEnd, postEnd);
}