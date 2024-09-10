// Remove N-th node from end of the linkedlist -- leetcode 19

// Time complexity O(n)
// Space complexity O(1)
// Single traversal
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // this is for when n==1 and head==nullptr
    if(!head) {
        return head;
    }
    ListNode *ptr = head, *curr = head;
    for(int i=1; i<n; ++i) {
        // when n is greater than the length of linkedlist
        if(!ptr) {
            return nullptr;
        }
        ptr = ptr->next;
    }
    ListNode *temp = nullptr;
    // When n == size of linkedlist
    // So need to delete the first node
    if(!ptr->next) {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *prev = nullptr;
    while(ptr && ptr->next) {
        prev = curr;
        curr = curr->next;
        ptr = ptr->next;
    }
    // we need to delete curr node
    // prev is the previous of curr node
    prev->next = curr->next;
    delete curr;
    return head;
}


// Time complexity O(n)
// Space complexity O(1)
// Single traversal
// Same as previous solution
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return head;
    int N = n;
    ListNode *curr = head;
    while (curr && (--N)) {
        curr = curr->next;
    }
    // n > length
    if(!curr) return nullptr;

    // when n == length
    // so we need to delete the head
    if(!curr->next) {
        head = head->next;
    }
    else {
        ListNode *ptr = head, *prev = nullptr;
        while(curr && curr->next) {
            prev = ptr;
            ptr = ptr->next;
            curr = curr->next;
        }
        prev->next = prev->next->next;
    }
    return head;
}