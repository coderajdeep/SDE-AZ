// Time complexity O(h)
// Space complexity O(1)
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    // Generally default ceil value should be INT_MAX
    int ans = -1;
    while(root) {
        if(root->data == input) {
            return root->data;
        }
        else if(input < root->data) {
            ans = root->data;
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return ans;
}