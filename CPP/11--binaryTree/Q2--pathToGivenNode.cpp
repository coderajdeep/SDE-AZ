// Time complexity O(n)
// Space Complexity O(h) : h --> height of binary tree
// https://www.interviewbit.com/problems/path-to-given-node/
// https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/

bool utils(TreeNode *root, int target, vector<int> &ans) {
    if(!root) return false;
    ans.push_back(root->val);
    if(root->val == target) return true;
    if(utils(root->left, target, ans) || utils(root->right, target, ans)) {
        return true;
    }
    ans.pop_back();
    return false;
} 
vector<int> Solution::solve(TreeNode* root, int target) {
    if(!root) return vector<int> {};
    vector<int> ans;
    utils(root, target, ans);
    return ans;
}