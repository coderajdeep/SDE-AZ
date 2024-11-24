// Delete a node when only the node pointer is given -- leetcode 237
// Time complexity O(n)
// Space complexity O(1)
void deleteNode(ListNode* node) {
    // node is not the last node
    ListNode *prev = nullptr;
    while(node && node->next) {
        prev = node;
        node->val = node->next->val;
        node = node->next;
    }
    prev->next = nullptr;
}