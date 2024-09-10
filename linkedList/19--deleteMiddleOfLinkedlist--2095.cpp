// Delete middle of linkedlist -- leetcode 2095

ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head, *prev = head;
    while(fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}