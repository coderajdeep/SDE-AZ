// Intersection of two linkedlist -- leetcode 160

// Time complexity O(n)
// Space complexity O(n)
// Uisng unordered_set
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) {
        return nullptr;
    }
    unordered_set<ListNode*> s;
    while(headA) {
        s.insert(headA);
        headA = headA->next;
    }
    while(headB) {
        if(s.find(headB)!=s.end()) {
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;
}


// Time complexity O(n)
// Space complexity O(1)
// Similar to finding the length but in better way
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) {
        return nullptr;
    }
    ListNode *ptrA = headA, *ptrB = headB;
    while(ptrA && ptrB) {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    // if ptrA or ptrB zero then there is length difference
    // otherwise both are same length
    while(ptrA && headA) {
        ptrA = ptrA->next;
        headA = headA->next;
    }
    while(ptrB && headB) {
        ptrB = ptrB->next;
        headB = headB->next;
    }
    while(headA && headB) {
        if(headA==headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}


// Time complexity O(n)
// Space complexity O(1)
int getLength(ListNode *head) {
    if(!head) {
        return 0;
    }
    if(!head->next) {
        return 1;
    }
    
    ListNode *slow = head, *fast = head;
    int count = 0;
    
    while(fast and fast->next) {
        ++count;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast) {
        return (2*count + 1);
    }
    return 2*count;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int n1 = getLength(headA);
    int n2 = getLength(headB);
    int diff = abs(n1-n2);
    ListNode *small = (n1<=n2) ? headA : headB;
    ListNode *large = (n1>n2) ? headA : headB;
    while(diff--) {
        large = large->next;
    }
    while(large && small) {
        if(large == small) return large;
        large = large->next;
        small = small->next;
    }
    return nullptr;
}