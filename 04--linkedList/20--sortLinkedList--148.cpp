// Sort singly linkedlist -- leetcode 148

// Time complexity O(nlogn)
// Space complexity O(1)
ListNode* getMidNode(ListNode* root) {
    if(!root || !root->next) {
        return root;
    }
    ListNode *slow = root, *fast = root, *prev = nullptr;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    return slow;
}
ListNode* mergeList(ListNode* first, ListNode* second) {
    ListNode* dummyNode = new ListNode();
    ListNode *root = dummyNode;
    while(first && second) {
        if(first->val <= second->val) {
            dummyNode->next = first;
            first = first->next;
        }
        else {
            dummyNode->next = second;
            second = second->next;
        }
        dummyNode = dummyNode->next;
    }
    if(first) {
        dummyNode->next = first;
    }
    else if(second) {
        dummyNode->next = second;
    }
    return root->next;
}
ListNode* sortList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *mid = getMidNode(head);
    ListNode *firstHalf = sortList(head);
    ListNode *secondHalf = sortList(mid);
    ListNode *newHead = mergeList(firstHalf, secondHalf);
    return newHead;
}