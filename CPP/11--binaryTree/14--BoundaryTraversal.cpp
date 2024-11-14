// Time Complexity O(2H + N) : N --> number of nodes and H - Height of binary tree

bool isLeaf(TreeNode<int>* root) {
    if(!root) return false;
    return (!root->left && !root->right);
}

void leftSide(TreeNode<int>* root, vector<int>& ans) {
    while(root) {
        if(!isLeaf(root)) {
            ans.push_back(root->data);
        }
        if(root->left) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
}

void rightSide(TreeNode<int>* root, vector<int>& ans) {
    vector<int> temp;
    while(root) {
        if(!isLeaf(root)) {
            temp.push_back(root->data);
        }
        if(root->right) {
            root = root->right;
        }
        else {
            root = root->left;
        }
    }
    int size = temp.size();
    for(int i=size-1; i>=0; --i) {
        ans.push_back(temp[i]);
    }
}

void leaves(TreeNode<int>* root, vector<int>& ans) {
    if(!root) return;
    if(isLeaf(root)) {
        ans.push_back(root->data);
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	if(!root) return vector<int> {};
    vector<int> ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftSide(root->left, ans);
    leaves(root, ans);
    rightSide(root->right, ans);
    return ans;
}
