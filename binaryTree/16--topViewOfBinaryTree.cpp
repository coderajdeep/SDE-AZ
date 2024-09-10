// Time complexity O(n + wlogw) : w --> max width , n --> total nodes
// Space complexity O(n)

vector<int> getTopView(TreeNode<int> *root) {
    if(!root) return vector<int> {};
    queue<pair<TreeNode<int>*, int>> q;
    // <root, vLevel>
    map<int, int> mp;
    // <vLevel, node->data>
    q.push({root, 0});
    pair<TreeNode<int>*, int> p;
    TreeNode<int>* node;
    int vLevel;

    while(!q.empty()) {
        p = q.front();
        q.pop();
        node = p.first;
        vLevel = p.second;
        if(mp.find(vLevel) == mp.end()) {
            mp[vLevel] = node->data;
        }
        if(node->left) {
            q.push({node->left, vLevel-1});
        }
        if(node->right) {
            q.push({node->right, vLevel+1});
        }
    }
    vector<int> ans(mp.size());
    int index = 0;
    for(pair<int, int>pr:mp) {
        ans[index++] = pr.second;
    }
    return ans;
}
