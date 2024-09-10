// Solution 3
// Best solution for finding predecessor and successor in BST
// Time complexity O(H)
// Space complexity O(1)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    Node *curr = root;
    while(curr) {
        if(curr->key > key) {
            suc = curr;
            curr = curr->left;
        }
        else if(curr->key < key) {
            curr = curr->right;
        }
        // equal case
        // we can merge last two case
        else {
            curr = curr->right;
        }
    }
    curr = root;
    while(curr) {
        if(curr->key < key) {
            pre = curr;
            curr = curr->right;
        }
        else if(curr->key > key) {
            curr = curr->left;
        }
        // equal case
        // we can merge last two case
        else {
            curr = curr->left;
        }
    }
}

// Solution 2
// Time complexity O(H)
// Space complexity O(1)
Node * inOrderSuccessor(Node *root, Node *x) {
    if(!x || !root) return nullptr;
    Node *curr = root, *ans = nullptr;
    int val = x->data;
    while(curr) {
        if(curr->data > val) {
            ans = curr;
            curr = curr->left;
        }
        else if(curr->data < val) {
            curr = curr->right;
        }
        // equal case
        // we can merge last two case
        else {
            curr = curr->right;
        }
    }
    return ans;
}


// Solution 1
// Time complexity O(n)
// Space complexity O(h)
// Inorder predecessor
// Work@tech
void predecessor(Node *root, Node *node, bool &flag, Node *&ans) {
	if(!root) return;
	predecessor(root->left, node, flag, ans);
	if(root == node) {
		flag = false;
		return;
	}
	if(flag) {
		ans = root;
	}
	predecessor(root->right, node, flag, ans);
}

Node* findPredecessor(Node* root, Node* p) {
	Node *ans = nullptr;
	bool flag = true;
    predecessor(root, p, flag, ans);
	return ans;
}

// Inorder successor
void inorder(Node *root, Node *node, bool &flag, Node *&ans) {
    if(!root) return;
    inorder(root->left, node, flag, ans);
    if(flag) {
        ans = root;
        flag = !flag;
        return;
    }
    if(root==node) {
        flag = true;
    }
    inorder(root->right, node, flag, ans);
} 
Node * inOrderSuccessor(Node *root, Node *x)
{
    if(!root) return nullptr;
    bool flag = false;
    Node *ans = nullptr;
    inorder(root, x, flag, ans);
    return ans;
}