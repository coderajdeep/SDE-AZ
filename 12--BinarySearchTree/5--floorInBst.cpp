// Time complexity O(h)
// Space complexity O(1)

int floor(Node* root, int x) {
	if(!root) return -1;
	int ans = -1;
	while(root) {
		if(root->data == x) return x;
		else if(root->data > x) {
			root = root->left;
		}
		else {
			ans = root->data;
			root = root->right;
		}
	}
	return ans;
}