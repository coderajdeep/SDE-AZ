// Connect next node in each level -- leetcode 116
// Time complexity O(n)
// Space complexity O(n)

Node* connect(Node* root) {
    if(!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    Node *prevNode = nullptr;

    while(!q.empty()) {
        int size = q.size();
        prevNode = nullptr;
        for(int i=0; i<size; ++i) {
            Node *curr = q.front();
            q.pop();
            if(prevNode) {
                prevNode->next = curr;
            }
            prevNode = curr;
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
    }
    return root;
}