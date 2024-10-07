// Time complexity O(n + wlogw)
// Space Complexity O(n)

vector <int> bottomView(Node *root) {
    if(!root) return vector<int> {};
    
    queue<pair<Node*, int>> q;
    pair<Node*, int> tempPair;
    map<int, int> mp;
    q.push({root, 0});
    Node* curr;
    int vLevel;
    
    while(!q.empty()) {
        tempPair = q.front();
        q.pop();
        curr = tempPair.first;
        vLevel = tempPair.second;
        mp[vLevel] = curr->data;
        
        if(curr->left) {
            q.push({curr->left, vLevel-1});
        }
        if(curr->right) {
            q.push({curr->right, vLevel+1});
        }
    }
    
    vector<int> ans(mp.size());
    int index = 0;
    for(pair<int, int> p : mp) {
        ans[index++] = p.second;
    }
    return ans;
}