// Time complexity O(h)

int minValue(Node* root) {
    int val = INT_MAX;
    while(root) {
        val = min(root->data, val);
        root = root->left;
    }
    return val;
}

// Recursive solution
int minValue(Node* root) {
    if(!root) return INT_MAX;
    return min(root->data, minValue(root->left));
}