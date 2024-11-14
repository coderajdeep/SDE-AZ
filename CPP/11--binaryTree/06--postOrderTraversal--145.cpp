// leetcode
// Time complexity O(n)
// Space complexity O(n)
void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void revrseVector(vector<int>& arr) {
    int start = 0, end = arr.size()-1;
    while(start<end) {
        swapElements(arr[start++], arr[end--]);
    }
} 

vector<int> postorderTraversal(TreeNode* root) {
    if(!root) return vector<int> {};

    vector<int> postorder;
    stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* curr = nullptr;

    while(!stk.empty()) {
        curr = stk.top();
        stk.pop();
        postorder.push_back(curr->val);
        if(curr->left) {
            stk.push(curr->left);
        }
        if(curr->right) {
            stk.push(curr->right);
        }
    }

    revrseVector(postorder);

    return postorder;
}

// Postorder traversal using one stack
// Time complexity O(2*n)
// Space complexity O(n)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return vector<int> {};

        stack<TreeNode*> stk;
        vector<int> postorder;
        TreeNode* curr = root;

        while(!stk.empty() || curr) {
            if(curr) {
                stk.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = stk.top()->right;
                if(temp) {
                    curr = temp;
                }
                else {
                    temp = stk.top();
                    stk.pop();
                    postorder.push_back(temp->val);
                    while(!stk.empty() && (temp == stk.top()->right)) {
                        temp = stk.top();
                        stk.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }

        return postorder;
    }
};