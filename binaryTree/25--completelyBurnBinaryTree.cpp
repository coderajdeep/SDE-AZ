// Time to completely burn a binary tree from a given node -- coding ninjas / geeks
// Time complexity O(2*n)
// Space complexity O(2*w + 2*n)
// Geeks
Node* utils(Node *root, int target, unordered_map<Node*, Node*> &um) {
    if(!root) return nullptr;
    queue<Node*> q;
    q.push(root); 
    Node *temp;
    while(!q.empty()) {
        Node *curr = q.front();
        if(curr->data == target) {
            temp = curr;
        }
        q.pop();
        if(curr->left) {
            q.push(curr->left);
            um[curr->left] = curr;
        }
        if(curr->right) {
            q.push(curr->right);
            um[curr->right] = curr;
        }
    }
    return temp;
}
int minTime(Node* root, int target) 
{
    if(!root) return -1;
    unordered_map<Node*, Node*> um;
    unordered_set<Node*> us;
    Node *tar = utils(root, target, um);
    queue<Node*> q;
    q.push(tar);
    us.insert(tar);
    int time = 0;
    
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; ++i) {
            Node *curr = q.front();
            q.pop();
            if(curr->left && us.find(curr->left)==us.end()) {
                us.insert(curr->left);
                q.push(curr->left);
            }
            if(curr->right && us.find(curr->right)==us.end()) {
                us.insert(curr->right);
                q.push(curr->right);
            }
            if(root != curr) {
                Node *par = um[curr];
                if(par && us.find(par)==us.end()) {
                    us.insert(par);
                    q.push(par);
                }
            }
        }
        ++time;
    }
    return time - 1;
}


// Coding Ninjas
void findParents(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &startNode, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &um, int start) {
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* curr;

    while(!q.empty()) {
        curr = q.front();
        if(curr->data == start) {
            startNode = curr;
        }
        q.pop();
        if(curr->left) {
            um[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            um[curr->right] = curr;
            q.push(curr->right);
        }
    }
} 

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    if(!root) return 0;
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> um;
    BinaryTreeNode<int>* startNode = nullptr;
    findParents(root, startNode, um, start);
    if(!startNode) return 0;

    int level = 0, size;
    queue<BinaryTreeNode<int>*> q;
    q.push(startNode);
    unordered_set<BinaryTreeNode<int>*> us;
    us.insert(startNode);
    BinaryTreeNode<int>* curr;
    BinaryTreeNode<int>* par;

    while(!q.empty()) {
        size = q.size();
        for(int i=0; i<size; ++i) {
            curr = q.front();
            q.pop();
            
            if(curr!=root) {
                par = um[curr];
                if(us.find(par)==us.end()) {
                    q.push(par);
                    us.insert(par);
                }
            }
            if(curr->left && us.find(curr->left)==us.end()) {
                us.insert(curr->left);
                q.push(curr->left);
            }
            if(curr->right && us.find(curr->right)==us.end()) {
                us.insert(curr->right);
                q.push(curr->right);
            }
        }
        ++level;
    }
    return (level-1);
}