// Time complexity O(n)
// Space complexity O(maxWidth)
// https://youtu.be/ZbybYvcVLks?si=ou4d4H7yS_2949t8

// When we subtract the first width index from all same level value and push their childs into queues, still working fine
// left --> x right --> y
// if we dont subtract
// then width will be
// 2*y+2 - 2*x+1 --> 2*(y-x) + 1
// if we do subtract
// then width will be
// 2*(y-x)+2 - 1 --> 2*(y-x) + 1
// Both are same
// So we need to subtract for integer overflow

int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    queue<pair<TreeNode*, long>> q;
    pair<TreeNode*, long> p;
    TreeNode *curr;
    long vIndex, maxWidth = 0, start;
    q.push({root, 0});
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            p = q.front();
            q.pop();
            curr = p.first;
            vIndex = p.second;
            if(i==0) start = vIndex;
            vIndex -= start;
            if(i==size-1) maxWidth = max(maxWidth, vIndex+1);
            if(curr->left) {
                q.push({curr->left, 2*vIndex+1});
            }
            if(curr->right) {
                q.push({curr->right, 2*vIndex+2});
            }
        }
    }
    return maxWidth;
}