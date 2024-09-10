// Time complexity O(n)
// Space complexity : Recursive stack space O(h)

bool isLeaf(Node* root) {
    return (!root->left && !root->right);
}

bool isParentSum(Node *root){
    if(!root || isLeaf(root)) return true;
    int sum = 0;
    if(root->left) {
        sum += root->left->data;
    }
    if(root->right) {
        sum += root->right->data;
    }
    if(sum != root->data) return false;
    return isParentSum(root->left) && isParentSum(root->right);
}


// Geeks
// Iterative method
int isSumProperty(Node *root) {
    if(!root)
        return 1; // true
    if(!root->left && !root->right)
        return 1; // true
    
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        
        int sum = 0;
        // flag will check the corner case
        // leaf nodes
        bool flag = false;
        
        if(curr->left) {
            q.push(curr->left);
            sum += curr->left->data;
            flag = true;
        }
        if(curr->right) {
            q.push(curr->right);
            sum += curr->right->data;
            flag = true;
        }
        
        if((curr->data!=sum) && flag)
            return 0;
        
    }
    return 1;
}


// Geeks
// Recursive method
// Solution 1
int isSumProperty(Node *root) {
    if(!root) return 1;
    if(!root->left && !root->right) return 1;
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->data != sum) return 0;
    if(isSumProperty(root->left)==0 || isSumProperty(root->right)==0) return 0;
    return 1;
}

// Solution 2 & solution 1 is same
int isSumProperty(Node *root) {
    if(!root) return 1;
    if(!root->left && !root->right) return 1;
    int sum = 0;
    if(root->left) sum += root->left->data;
    if(root->right) sum += root->right->data;
    if(root->data != sum) return 0;
    return isSumProperty(root->left) && isSumProperty(root->right);
}