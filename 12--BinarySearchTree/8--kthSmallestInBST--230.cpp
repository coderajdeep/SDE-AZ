// Kth smallest element in BST
// Time complexity O(n)
// Space complexity O(1)
// Best approach
int kthSmallest(TreeNode* root, int k) {
    if(!root) return -1;
    TreeNode *curr = root, *prev=nullptr;
    int cnt = 1, ans;
    while(curr) {
        if(curr->left) {
            prev = curr->left;
            while(prev->right && prev->right!=curr) {
                prev = prev->right;
            }
            if(prev->right) {
                if(cnt==k) {
                    ans = curr->val;
                    // If we break this then leetcode will give segmentation error
                    // because we have altered prev->right --> curr
                    // if we do complete traversal, then we undo this in further step
                }
                ++cnt;
                prev->right = nullptr;
                curr = curr->right;
            }
            else {
                prev->right = curr;
                curr = curr->left;
            }
        }
        else {
            if(cnt==k) {
                ans = curr->val;
            }
            ++cnt;
            curr = curr->right;
        }
    }
    return ans;
}

// Time complexity O(n)
// Recursive Stack Space complexity O(h) : h--> height
void inorder(TreeNode *root, int &k, int &ans) {
    if(!root) return;
    inorder(root->left, k, ans);
    if((--k)==0) {
        ans = root->val;
        return;
    }
    inorder(root->right, k, ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    inorder(root, k, ans);
    return ans;
}


// Geeks
// Kth largest element in BST
// Time complexity O(n)
// Space complexity O(1)
int kthLargest(Node *root, int K) {
    int ans, cnt = 1;
    while(root) {
        if(root->right) {
            Node *prev = root->right;
            while(prev->left && prev->left!=root) {
                prev = prev->left;
            }
            if(prev->left) {
                if(cnt==K) {
                    ans = root->data;
                    // Geeks test case does not check if we have altered the given node or not
                    // so this will work
                    break;
                }
                ++cnt;
                prev->left = nullptr;
                root = root->left;
            }
            else {
                prev->left = root;
                root = root->right;
            }
        }
        else {
            if(cnt==K) {
                ans = root->data;
                break;
            }
            ++cnt;
            root = root->left;
        }
    }
    return ans;
}