// Time complexity O(n)
// Space complexity O(h) : h --> height of binary tree

int height(TreeNode* root, int& diameter) {
    if(!root) return 0;
    int lheight = height(root->left, diameter);
    int rheight = height(root->right, diameter);
    diameter = max(diameter, (lheight + rheight));
    return (1 + max(lheight, rheight));
}
int diameterOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int diameter = 0;
    height(root, diameter);
    return diameter;
}