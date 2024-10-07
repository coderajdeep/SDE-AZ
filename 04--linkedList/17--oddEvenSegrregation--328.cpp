// Segrregate odd and even indexed node in singly linked list -- leetcode 328

// Time complexity O(n)
// Space complexity O(n)
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *odd = new ListNode();
    ListNode *even = new ListNode();
    ListNode *oddHead = odd;
    ListNode *evenHead = even;
    int index = 1;
    while(head) {
        int num = head->val;
        if(index%2==1) {
            odd->next = new ListNode(num);
            odd = odd->next;
        }
        else {
            even->next = new ListNode(num);
            even = even->next;
        }
        ++index;
        head = head->next;
    }
    odd->next = evenHead->next;
    return oddHead->next;
}


// Time complexity O(n)
// Space complexity O(1)
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) {
        return head;
    }
    ListNode *odd = head, *even = head->next;
    ListNode *evenHead = even;
    while(even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}


// Same as above
// But the above one is better for this perticular problem
// But this can be extended to other problem solution
ListNode* oddEvenList(ListNode* head) {
    ListNode *oddDummy = new ListNode(0), *evenDummy = new ListNode(0);
    ListNode *odd = oddDummy, *even = evenDummy;
    bool isOdd = true;
    while(head) {
        if(isOdd) {
            oddDummy->next = head;
            oddDummy = oddDummy->next;
        }
        else {
            evenDummy->next = head;
            evenDummy = evenDummy->next;
        }
        isOdd = !isOdd;
        head = head->next;
    }
    oddDummy->next = nullptr; // Terminate odd list
    evenDummy->next = nullptr; // Terminate even list
    oddDummy->next = even->next; // Connect odd list's tail to even list's head
    return odd->next;
}