// Time complexity O(n)
// Space complexity O(h*2^(h-1))

// Solution 1
bool isLeaf(TreeNode* root) {
    return (!root->left && !root->right);
}
void rootToLeafUtils(TreeNode* root, string& str, vector<string>& ans) {
    if(!root) return;
    int len = 0;
    if(!str.empty()) {
        str += "->";
        len += 2;
    }
    string s = to_string(root->val);
    str += s;
    if(isLeaf(root)) {
        ans.push_back(str);
    }
    rootToLeafUtils(root->left, str, ans);
    rootToLeafUtils(root->right, str, ans);
    len += s.size();
    for(int i=0; i<len; ++i) {
        str.pop_back();
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    if(!root) return vector<string> {};
    string temp;
    vector<string> ans;
    rootToLeafUtils(root, temp, ans);
    return ans;
}

// Solution 2
// Initially generate all root to leaf paths
// then convert each path into string
void solve(TreeNode *root, vector<vector<int>> &paths, vector<int> &path) {
    if(!root) return;
    path.push_back(root->val);
    if(!root->left && !root->right) {
        paths.push_back(path);
    }
    solve(root->left, paths, path);
    solve(root->right, paths, path);
    path.pop_back();
}
vector<string> binaryTreePaths(TreeNode* root) {
    if(!root) return vector<string> {};
    vector<vector<int>> paths;
    vector<int> path;
    solve(root, paths, path);
    vector<string> ans;
    for(vector<int> path : paths) {
        int n = path.size();
        string s = to_string(path[0]);
        for(int i=1; i<n; ++i) {
            s += "->";
            s += to_string(path[i]);
        }
        ans.push_back(s);
    }
    return ans;
}

// Solution 3
// Geeks
// Generate all root to leaf paths
void solve(Node *root, vector<vector<int>> &ans, vector<int> &temp) {
    if(!root) return;
    temp.push_back(root->data);
    if(!root->left && !root->right) {
        ans.push_back(temp);
    }
    solve(root->left, ans, temp);
    solve(root->right, ans, temp);
    temp.pop_back();
}
vector<vector<int>> Paths(Node* root) {
    if(!root) return vector<vector<int>> {};
    vector<int> temp;
    vector<vector<int>> ans;
    solve(root, ans, temp);
    return ans;
}


// For Debugging Code
// Here from level order traversal, tree will be generated
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Solution() {}
    bool isLeaf(TreeNode* root) {
        return (!root->left && !root->right);
    }
    void rootToLeafUtils(TreeNode* root, string& str, vector<string>& ans) {
        if (!root) return;
        if (!str.empty()) {
            str += "->";
        }
        string s = to_string(root->val);
        str += s;
        if (isLeaf(root)) {
            ans.push_back(str);
        }
        rootToLeafUtils(root->left, str, ans);
        rootToLeafUtils(root->right, str, ans);
        int n = s.size() + 2;
        for (int i = 0; i < n; ++i) {
            str.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return vector<string> {};
        string temp;
        vector<string> ans;
        rootToLeafUtils(root, temp, ans);
        return ans;
    }
};

TreeNode* stringToTreeNode(const string& input) {
    // Remove '[' and ']' from the input string
    string str = input.substr(1, input.size() - 2);

    // Use stringstream to split the comma-separated values
    stringstream ss(str);
    string token;
    vector<string> tokens;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    if (tokens.empty()) {
        return nullptr;
    }

    // Create a queue to perform level order traversal and construct the tree
    queue<TreeNode*> nodes;
    TreeNode* root = new TreeNode(stoi(tokens[0]));
    nodes.push(root);
    int index = 1;

    while (!nodes.empty() && index < tokens.size()) {
        TreeNode* current = nodes.front();
        nodes.pop();

        // Left child
        if (tokens[index] != "null") {
            current->left = new TreeNode(stoi(tokens[index]));
            nodes.push(current->left);
        }
        index++;

        // Right child
        if (index < tokens.size() && tokens[index] != "null") {
            current->right = new TreeNode(stoi(tokens[index]));
            nodes.push(current->right);
        }
        index++;
    }

    return root;
}

int main() {
    // Example usage:
    string input = "[1,2,3,null,5]";
    TreeNode* root = stringToTreeNode(input);

    // Your logic or function calls with the binary tree root go here
    Solution* sol = new Solution();
    vector<string> ans =  sol->binaryTreePaths(root);
    for (string s : ans) {
        cout << s << endl;
    }
    // Clean up the allocated memory
    // (You may need to implement a function for deleting the tree)
    // deleteTree(root);

    return 0;
}
