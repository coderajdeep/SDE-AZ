// Time complexity O(n)
// Space complexity O(h) : recursion stack space
// Best approach
// https://youtu.be/_-QHfMDde90?si=WTxWEKm6m5Qp4iV6
// Clean solution

// Solution 1
// Limitation of this method is, this will not work if only one node is exist and another doesnot exist
// In this case, LCA should be null, but this method will return the node as a LCA
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q) return root;
    TreeNode *lnode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rnode = lowestCommonAncestor(root->right, p, q);
    if(lnode && rnode) return root;
    // below condition can be handled last line
    //if(!lnode && !rnode) return nullptr;
    return lnode ? lnode : rnode;
}
// Solution 2
// Both are same
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root==p || root==q) return root;
    TreeNode* lnode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rnode = lowestCommonAncestor(root->right, p, q);
    if(!lnode) return rnode;
    if(!rnode) return lnode;
    else return root;
}

// Coding Ninjas
// Where node value is given
int lowestCommonAncestor(TreeNode<int> *root, int x, int y) {
	if(!root) return -1;
    if(root->data==x || root->data==y) return root->data;
    int ldata = lowestCommonAncestor(root->left, x, y);
    int rdata = lowestCommonAncestor(root->right, x, y);
    if(ldata==-1) return rdata;
    if(rdata==-1) return ldata;
    else return root->data;
}

// Time Complexity O(2*n)
// Space complexity O(2*n)
void dfs(TreeNode* root, vector<vector<TreeNode*>>& paths, vector<TreeNode*>& path, TreeNode* p, TreeNode* q) {
    if(!root) return;
    path.push_back(root);
    if(root==p || root==q) {
        paths.push_back(path);
    }
    dfs(root->left, paths, path, p, q);
    dfs(root->right, paths, path, p, q);
    path.pop_back();
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root) return root;
    vector<vector<TreeNode*>> paths;
    vector<TreeNode*> path;
    dfs(root, paths, path, p, q);
    // needs to check paths size
    // if its less than 2 then LCA not possible
    int n = paths[0].size();
    int m = paths[1].size();
    if(n==1 || m==1) return root;
    int i = 0, j = 0;
    while(i<n && j<m) {
        if(paths[0][i]!=paths[1][j]) {
            return paths[0][i-1];
        }
        // else if path will execute when p or q is ancestor
        else if(paths[0][i]==q) {
            return q;
        }
        else if(paths[1][j]==p) {
            return p;
        }
        ++i;
        ++j;
    }
    return root;
}



// Time complexity O(n2)
// Space complexity O(h2)
// Coding Ninjas
bool isNodeExist(TreeNode<int> *root, int node) {
    if(!root) return false;
    if(root->data == node) return true;
    return (isNodeExist(root->left, node) || isNodeExist(root->right, node));
}

bool postOrder(TreeNode<int> *root, int& ans, int x, int y) {
    if(!root) return false;
    if(postOrder(root->left, ans, x, y) || postOrder(root->right, ans, x, y)) {
        return true;
    }
    if(isNodeExist(root, x) && isNodeExist(root, y)) {
        ans = root->data;
        return true;
    }
    return false;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(!root) return -1;
    int ans = -1;
    postOrder(root, ans, x, y);
    return ans;
}