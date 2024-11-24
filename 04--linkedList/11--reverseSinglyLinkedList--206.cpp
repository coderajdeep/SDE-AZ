// Reverse a linkedlist -- leetcode 206

// Iterative way
// Time complexity O(n)
// Space complexity O(1)
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *prev = nullptr, *curr = head, *nxt = nullptr;
    while(curr) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

// Recursive solution
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
// 1-->2-->3-->4-->null
// reverseList(1) will reverse the linkedlist
// null<--1<--2<--3<--4
// 4 is the newHead
// reverseList(2) will reverse the linkedlist (except 1) and return 4 as a new head
// null<--2<--3<--4
// 1-->2