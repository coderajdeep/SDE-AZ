// Vertical Order Traversal of a binary Tree -- 987
// In leetcode, we need to sort the same vertical and horizontal level elements
// In geeks, we need to just store them in level order of the same vertical and horizontal level elements


// Solution 1
// Time complexity O(nlogn)
// Space Complexity O(2*n)
// cleaner than previous method
// leetcode 987
vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(!root) return vector<vector<int>> {};
    map<int, map<int, multiset<int>>> mp;
    // treeNode, virticalOrder
    queue<pair<TreeNode*, int>> q;
    pair<TreeNode*, int> pr;
    q.push({root, 0});
    int hOrder = 1, vOrder;
    TreeNode *curr;

    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            pr = q.front();
            q.pop();
            curr = pr.first;
            vOrder = pr.second;
            mp[vOrder][hOrder].insert(curr->val);
            if(curr->left) {
                q.push({curr->left, vOrder-1});
            }
            if(curr->right) {
                q.push({curr->right, vOrder+1});
            }
        }
        ++hOrder;
    }

    vector<vector<int>> ans;
    for(pair<int, map<int, multiset<int>>> pr1 : mp) {
        vector<int> temp;
        map<int, multiset<int>> &mp2 = pr1.second;
        for(pair<int, multiset<int>> pr2 : mp2) {
            multiset<int> &st = pr2.second;
            for(int value : st) {
                temp.push_back(value);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}


// Solution 2
// Time Complexity O(nlogn)
// Space Complexity O(2*n)
// leetcode 987
vector<vector<int>> verticalTraversal(TreeNode* root) {
    if(!root) return vector<vector<int>> {};

    queue<pair<TreeNode*, pair<int, int>>> q;
    // <root <hLevel, vLevel>>
    map<int, multiset<pair<int, int>>> mp;
    // <vLevel <hLevel, nodeValue>>
    q.push({root, {1, 0}});
    pair<TreeNode*, pair<int, int>> temp;
    TreeNode* node;
    int hLevel, vLevel, index, n;

    while(!q.empty()) {
        temp = q.front();
        q.pop();
        node = temp.first;
        hLevel = temp.second.first;
        vLevel = temp.second.second;

        mp[vLevel].insert({hLevel, node->val});

        if(node->left) {
            q.push({node->left, {hLevel+1, vLevel-1}});
        }
        if(node->right) {
            q.push({node->right, {hLevel+1, vLevel+1}});
        }
    }

    vector<vector<int>> ans(mp.size());
    int ansIndex = 0;
    for(auto _mp : mp) {
        auto _ms = _mp.second;
        n = _ms.size();
        vector<int> vLevelList(n);
        index = 0;
        for(pair<int, int> p:_ms) {
            vLevelList[index++] = p.second;
        }
        ans[ansIndex++] = vLevelList;
    }
    return ans;
}


// Geeks solution
// Solution 1
// Time complexity O(nlogn)
// Space Complexity O(2*n)
// Worst case, there can be n vertical level
// So time complexity is O(nlogn)
vector<int> verticalOrder(Node *root) {
    if(!root) return vector<int> {};
    // vLevel, vector<int>
    map<int, vector<int>> mp;
    // node, vLevel
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    pair<Node*, int> p;
    Node *curr = nullptr;
    int vLevel;
    
    while(!q.empty()) {
        p = q.front();
        q.pop();
        curr = p.first;
        vLevel = p.second;
        mp[vLevel].push_back(curr->data);
        if(curr->left) {
            q.push({curr->left, vLevel-1});
        }
        if(curr->right) {
            q.push({curr->right, vLevel+1});
        }
    }
    vector<int> ans;
    for(pair<int, vector<int>> p : mp) {
        ans.insert(ans.end(), p.second.begin(), p.second.end());
    }
    return ans;
}

// solution 2
// Time complexity O(nlogn)
// Space Complexity O(2*n)
vector<int> verticalOrder(Node *root) {
    if(!root) return vector<int> {};
    map<int, map<int, vector<int>>> mp;
    // Node, virticalOrder
    queue<pair<Node*, int>> q;
    pair<Node*, int> pr;
    q.push({root, 0});
    int hOrder = 1, vOrder;
    Node *curr;
    int totalSize = 0;
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            pr = q.front();
            q.pop();
            ++totalSize;
            curr = pr.first;
            vOrder = pr.second;
            mp[vOrder][hOrder].push_back(curr->data);
            if(curr->left) {
                q.push({curr->left, vOrder-1});
            }
            if(curr->right) {
                q.push({curr->right, vOrder+1});
            }
        }
        ++hOrder;
    }
    
    vector<int> ans(totalSize);
    int index = 0;
    for(pair<int, map<int, vector<int>>> pr : mp) {
        map<int, vector<int>> &mp2 = pr.second;
        for(pair<int, vector<int>> pr2 : mp2) {
            vector<int> &v = pr2.second;
            for(int value : v) {
                ans[index++] = value;
            }
        }
    }
    return ans;
}