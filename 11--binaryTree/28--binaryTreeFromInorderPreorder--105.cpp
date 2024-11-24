// Time complexity O(n2)
// Space complexity O(n)

TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int &preStart) {
    if(inStart > inEnd) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[preStart++]);
    // this is for finding the root index in inorder vector
    int inIndex;
    for(int i=inStart; i<=inEnd; ++i) {
        if(inorder[i]==root->val) {
            inIndex = i;
            break;
        }
    }
    root->left = getTree(preorder, inorder, inStart, inIndex-1, preStart);
    root->right = getTree(preorder, inorder, inIndex+1, inEnd, preStart);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int inStart = 0, inEnd = inorder.size()-1, preStart = 0;
    TreeNode* root = getTree(preorder, inorder, inStart, inEnd, preStart);
    return root;
}


// Optimized approach
// Uisng hash table to find the inorder root index in constant timeF
// Time complexity O(n)
// Space complexity  O(n)
TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &inorderHash, int inStart, int inEnd, int &preStart) {
    if(inStart > inEnd) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[preStart++]);
    // this is for finding the root index in inorder vector in constant time
    int inIndex = inorderHash[root->val];
    root->left = getTree(preorder, inorder, inorderHash, inStart, inIndex-1, preStart);
    root->right = getTree(preorder, inorder, inorderHash, inIndex+1, inEnd, preStart);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int inStart = 0, inEnd = inorder.size()-1, preStart = 0;
    unordered_map<int, int> inorderHash;
    for(int i=0; i<=inEnd; ++i) {
        inorderHash[inorder[i]] = i;
    }
    TreeNode* root = getTree(preorder, inorder, inorderHash, inStart, inEnd, preStart);
    return root;
}