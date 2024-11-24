// Is BT a valid BST
// Time complexity O(n)
// Space complexity O(h) : considering recursive stack space

bool isBSTValid(TreeNode *root, long leftValue, long rightValue) {
    if(!root) return true;
    // We can check this in the next line also
    if((root->val)<=leftValue || (root->val)>=rightValue) return false;
    return isBSTValid(root->left, leftValue, root->val) && isBSTValid(root->right, root->val, rightValue);
    // return (root->val)>leftValue && (root->val)<rightValue && isBSTValid(root->left, leftValue, root->val) 
    // && isBSTValid(root->right, root->val, rightValue);
}
bool isValidBST(TreeNode* root) {
    return isBSTValid(root, LONG_MIN, LONG_MAX);
}


// Uisng iterative method (level order traversal)
// Time complexity O(n)
// Space complexity O(w) : w --> Max node in one level
struct Node {
    TreeNode *node;
    long leftValue, rightValue;
    Node(TreeNode *node, long leftValue, long rightValue) {
        Node::node = node;
        Node::leftValue = leftValue;
        Node::rightValue = rightValue;
    }
};
bool isValidBST(TreeNode* root) {
    if(!root) return true;
    queue<Node> q;
    q.push({root, LONG_MIN, LONG_MAX});
    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        int nodeValue = curr.node->val;
        if(nodeValue<=curr.leftValue || nodeValue>=curr.rightValue) return false;
        if(curr.node->left) {
            q.push({curr.node->left, curr.leftValue, nodeValue});
        }
        if(curr.node->right) {
            q.push({curr.node->right, nodeValue, curr.rightValue});
        }
    }
    return true;
}