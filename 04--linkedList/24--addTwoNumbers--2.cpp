// Add Two Numbers -- leetcode 2

// Time complexity O(max length of (l1, l2))
// Space complexity O(1)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2) return nullptr;
    if(!l1) return l2;
    if(!l2) return l1;
    ListNode *dummy = new ListNode(0);
    ListNode *head = dummy;
    int carry = 0;
    while(l1 && l2) {
        int num = (carry + l1->val + l2->val);
        carry = num / 10;
        l1->val = num % 10;
        dummy->next = l1;
        l1 = l1->next;
        l2 = l2->next;
        dummy = dummy->next;
    }
    while(l1) {
        int num = (carry + l1->val);
        carry = num / 10;
        l1->val = num % 10;
        dummy->next = l1;
        l1 = l1->next;
        dummy = dummy->next;
    }
    while(l2) {
        int num = (carry + l2->val);
        carry = num / 10;
        l2->val = num % 10;
        dummy->next = l2;
        l2 = l2->next;
        dummy = dummy->next;
    }
    if(carry) {
        dummy->next = new ListNode(carry);
    }
    return head->next;
}

// Time complexity O(max(l1 length, l2 length))
// Space complexity O(max(l1 length, l2 length))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, data;
    ListNode *root = new ListNode();
    ListNode *head = root;
    while(l1 && l2) {
        data = carry + l1->val + l2->val;
        root->next = new ListNode(data%10);
        carry = data / 10;
        root = root->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1) {
        data = carry + l1->val;
        root->next = new ListNode(data%10);
        carry = data / 10;
        root = root->next;
        l1 = l1->next;
    }
    while(l2) {
        data = carry + l2->val;
        root->next = new ListNode(data%10);
        carry = data / 10;
        root = root->next;
        l2 = l2->next;
    }
    if(carry) {
        root->next = new ListNode(carry);
    }
    return head->next;
}

// Time complexity O(max(l1 length, l2 length))
// Space complexity O(max(l1 length, l2 length))
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0, data;
    ListNode *root = new ListNode();
    ListNode *head = root;
    while(l1 || l2 || carry) {
        data = carry;
        if(l1) {
            data += l1->val;
            l1 = l1->next;
        }
        if(l2) {
            data += l2->val;
            l2 = l2->next;
        }
        root->next = new ListNode(data % 10);
        root = root->next;
        carry = data / 10;
    }
    return head->next;
}