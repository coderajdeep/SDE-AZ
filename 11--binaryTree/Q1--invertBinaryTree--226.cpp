// Invert Binary Tree -- leetcode 226s
// Time complexity O(n)
// Space complexity O(h) : recursive space complexity h --> height of the tree

// Solution 1
// Solution 1 & 2 are same
// Using PreOrder Traversal
// PostOrder traversal will also work
TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// Solution 2
TreeNode* invertTree(TreeNode* root) {
    if(!root) return root;
    swap(root->left, root->right);
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}

// Iterative solution using level order traversal
TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode *curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    return root;
}


TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    swap(root->left, root->right);
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    return root;
}

// Iterative approach
TreeNode* invertTree(TreeNode* root) {
    if(!root) {
        return root;
    }
    
    stack<TreeNode*>s;
    s.push(root);
    
    while(!s.empty()) {
        TreeNode *curr = s.top();
        s.pop();
        
        if(curr->right) {
            s.push(curr->right);
        }
        if(curr->left) {
            s.push(curr->left);
        }
        
        swap(curr->right, curr->left);
    }
    
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) {
        return root;
    }
    stack<TreeNode*>s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *curr = s.top();
        s.pop();
        swap(curr->right, curr->left);
        if(curr->right) {
            s.push(curr->right);
        }
        if(curr->left) {
            s.push(curr->left);
        }
    }
    
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    swap(root->left, root->right);
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    return root;
}

TreeNode* invertTree(TreeNode* root) {
    if(!root) return nullptr;
    
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    
    root->left = l;
    root->right = r;

    swap(root->left, root->right);

    return root;
}

// Geeks
void mirror(Node* node) {
    if(!node) return;
    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}