// leetcode
// Need to return vector of vector
// Each level elements into one vector and then push this vector into another vector
// Time complexity O(n)
// Space Complexity O(n)

vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return vector<vector<int>> {};

    vector<vector<int>> levelOrder;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* curr = nullptr;

    while(!q.empty()) {
        int size = q.size();
        vector<int> levelElements(size);
        for(int i=0; i<size; ++i) {
            curr = q.front();
            q.pop();
            levelElements[i] = curr->val;
            
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        levelOrder.push_back(levelElements);
    }
    return levelOrder;
}

// Coding ninjas
// Need to return vector
vector<int> levelOrder(TreeNode<int> * root){
    if(!root) return vector<int> {};

    vector<int> levelOrder;
    queue<TreeNode<int>*>q;
    q.push(root);
    TreeNode<int>* curr = nullptr;

    while(!q.empty()) {
        curr = q.front();
        q.pop();
        levelOrder.push_back(curr->data);
        if(curr->left) {
            q.push(curr->left);
        }
        if(curr->right) {
            q.push(curr->right);
        }
    }
    return levelOrder;
}

// Time complexity O(n2)
// Space complexity O(n)
void printNthLevel(TreeNode* root, int level, vector<int> &levelOrder) {
    if(!root) return;
    if(level==1) {
        levelOrder.push_back(root->val);
    }
    else if(level > 1) {
        printNthLevel(root->left, level-1, levelOrder);
        printNthLevel(root->right, level-1, levelOrder);
    }
}
int height(TreeNode* root) {
    return !root ? 0 : (max(height(root->left), height(root->right)) + 1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return vector<vector<int>> {};
    vector<vector<int>> levelOrderTraversal;
    int ht = height(root);
    for(int i=1; i<=ht; ++i) {
        vector<int>levelOrder;
        printNthLevel(root, i, levelOrder);
        levelOrderTraversal.push_back(levelOrder);
    }
    return levelOrderTraversal;
}