// Mid of linkedlist -- leetcode 876

ListNode* middleNode(ListNode* head) {
    if(!head && !head->next) {
        return head;
    }
    ListNode *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // fast == null => list length is even
    // else odd
    // if length is even then there are two middle
    // we need to return the 2nd mid
    // If the size is N
    // then we need to return N/2 element (0 based index)
    return slow; 
}