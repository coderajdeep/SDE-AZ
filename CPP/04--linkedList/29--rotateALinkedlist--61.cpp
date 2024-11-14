// Rotate a linkedlist -- leetcode 61
// Time complexity O(n)
// Space complexity O(1)
int getLength(ListNode* head) {
    if(!head) return 0;
    ListNode *slow = head, *fast = head;
    int len = 0;
    while(fast && fast->next) {
        ++len;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) return (2*len + 1);
    return 2*len;
}
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next) return head;
    int len = getLength(head);
    // k can be greater than len that's why need to take mod 
    k = k % len;
    if(k==0) return head;
    k = len - k;
    ListNode *curr = head;
    while(--k) {
        curr = curr->next;
    }
    // new head
    ListNode *newHead = curr->next;

    // need to cut out the previous section
    curr->next = nullptr;

    // need to get the last node of 2nd portion
    ListNode *ptr = newHead;
    while(ptr && ptr->next) ptr = ptr->next;
    ptr->next = head;
    return newHead; 
}