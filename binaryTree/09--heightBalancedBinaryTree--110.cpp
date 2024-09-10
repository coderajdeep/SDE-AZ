// Time complexity O(n)
// Space complexity O(h) : h --> height of the binary tree

int height(TreeNode* root) {
    if(!root) return 0;
    int lheight = height(root->left);
    if(lheight==-1) return -1;
    int rheight = height(root->right);
    if(rheight==-1) return -1;
    if(abs(lheight-rheight)>1) return -1;
    return (1 + max(lheight, rheight));
}
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    return (height(root)!=-1);
}